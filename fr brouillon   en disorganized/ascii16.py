import os
import platform
import queue
import random
import sys
import threading
import time
import traceback
import cv2
import numpy as np
import pyvirtualcam
from PIL import Image, ImageDraw, ImageFont
from PyQt6.QtCore import Qt, pyqtSignal, QTimer, QRunnable, QObject, QThreadPool, pyqtSlot
from PyQt6.QtGui import QCloseEvent, QIcon, QImage, QKeyEvent, QPixmap
from PyQt6.QtWidgets import QApplication,QLabel, QMainWindow, QVBoxLayout, QWidget

class WorkerSignals(QObject):
    '''
    Defines the signals available from a running worker thread.

    Supported signals are:

    finished
        No data

    error
        tuple (exctype, value, traceback.format_exc() )

    result
        object data returned from processing, anything

    progress
        int indicating % progress

    '''
    finished = pyqtSignal()
    error = pyqtSignal(tuple)
    result = pyqtSignal(object)
    progress = pyqtSignal(int)


class Worker(QRunnable):
    '''
    Worker thread

    Inherits from QRunnable to handler worker thread setup, signals and wrap-up.

    :param callback: The function callback to run on this worker thread. Supplied args and
                    kwargs will be passed through to the runner.
    :type callback: function
    :param args: Arguments to pass to the callback function
    :param kwargs: Keywords to pass to the callback function

    '''

    def __init__(self, fn, *args, **kwargs):
        super(Worker, self).__init__()

        # Store constructor arguments (re-used for processing)
        self.fn = fn
        self.args = args
        self.kwargs = kwargs
        self.signals = WorkerSignals()

        # Add the callback to our kwargs
        self.kwargs['progress_callback'] = self.signals.progress

    @pyqtSlot()
    def run(self):
        '''
        Initialise the runner function with passed args, kwargs.
        '''

        # Retrieve args/kwargs here; and fire processing using them
        try:
            result = self.fn(*self.args, **self.kwargs)
        except:
            traceback.print_exc()
            exctype, value = sys.exc_info()[:2]
            self.signals.error.emit((exctype, value, traceback.format_exc()))
        else:
            self.signals.result.emit(result)  # Return the result of the processing
        finally:
            self.signals.finished.emit()  # Done

class Matrix(QMainWindow):
    def __init__(self, parent=None):
        super(Matrix, self).__init__(parent)
        
        self.wd = sys._MEIPASS if getattr(sys, 'frozen', False) else ''
        
        self.counter = 0        
        
        if sys.platform == 'win32':
            import ctypes
            winVer = platform.win32_ver(release='')[0]
            try:
                if int(winVer) >= 10:
                    ctypes.windll.shcore.SetProcessDpiAwareness(2)
                elif int(winVer) == 8:
                    ctypes.windll.shcore.SetProcessDpiAwareness(1)
                else:
                    ctypes.windll.user32.SetProcessDPIAware()
            except (ImportError, AttributeError, OSError):
                pass
            
        # Initialisez les variables globales ici
        self.running = True
        self.ascii_image = ""

        # self.camera_selector_instance.camera_selected.connect(self.handle_camera_selected)
        
        # Ouverture de la caméra
        if platform.system() == 'Windows':
            self.capture = cv2.VideoCapture(0,cv2.CAP_DSHOW)
        elif platform.system() == 'Linux':
            self.capture = cv2.VideoCapture(0)
        self.capture.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
        self.capture.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)

        self.initUI()

        # dimention camera et affichage
        self.width = 1280
        self.height = 720
        
        # Définition des caractères à utiliser pour l'ASCII art
        self.characters = ' ú.ù,:öøýü×ÖÅ³·ÈØÙÍÐ±´¶¹º¼Â²ÇËÒÓ¾Ú'
        self.logo = cv2.imread(os.path.join(self.wd, 'MatrixLogo.png'))
        self.size1, self.size2 = 1280, 301
        self.logo = cv2.resize(self.logo, (self.size1, self.size2))

        self.camera = 0 # À modifier si ne fonctionne pas
        self.frame_lock = threading.Lock()
        self.ascii_image_lock = threading.Lock()

        self.rain_intensity = 0.5
        self.last_ascii_image, rain_ascii_image = "", ""
        self.columns_to_erase_queue = queue.Queue()
        self.columns_launched_queue = queue.Queue()
        self.image_updated = ""

        self.ascii_font_size_width = 20
        self.ascii_font_size_height = self.ascii_font_size_width * 9 / 16

        self.width = 1280
        self.height = 720
        self.font_path = os.path.join(self.wd, 'mtx.ttf')
        self.canvas_image = Image.new('RGB', (self.width, self.height), 'black')
        self.draw = ImageDraw.Draw(self.canvas_image)
        self.font = ImageFont.truetype(self.font_path, self.ascii_font_size_width)
        
        self.frame, self.ascii_image, self.rain_ascii_image, self.rain_ascii_image_result, self.drop_of_water_image_ascii, self.erase_rain_ascii_image = None, "", "", "", "", ""
        self.ascii_column = 0
        self.ascii_row = 0
        
        if getattr(sys, 'frozen', False):
            import pyi_splash

            # Fermeture du splash screen
            pyi_splash.update_text('UI Loaded ...')
            pyi_splash.close()

        # Variables partagées entre les threads
        self.frame = None
        self.ascii_image = ""

        self.threads = []
        
        # initialisation des ascii art
        for line in range(0, 106):
            for column in range(0, 106):
                self.ascii_image += ' '
                self.rain_ascii_image += ' '
                self.rain_ascii_image_result += ' '
                self.drop_of_water_image_ascii += ' '
                self.erase_rain_ascii_image += ' '
            self.ascii_image += '\n'
            self.rain_ascii_image += '\n'
            self.rain_ascii_image_result += '\n'
            self.drop_of_water_image_ascii += '\n'
            self.erase_rain_ascii_image += '\n'

        self.resized_image = np.zeros((720, 1280), dtype=np.uint8)
        self.drop_of_water_image = self.resized_image
        self.erase_rain_image = self.resized_image
        self.virtual_frame = cv2.cvtColor(np.array(self.resized_image), cv2.COLOR_RGB2BGR)
        self.drop_positions = np.zeros(1280, dtype=int)
        self.image_updated = False
        self.buffer = None

        print("prépare les threads")
        # Lancement des threads
        self.capture_thread = QThreadPool()
        print("Multithreading with maximum %d threads" % self.capture_thread.maxThreadCount())
        self.ascii_thread = QThreadPool()
        print("Multithreading with maximum %d threads" % self.ascii_thread.maxThreadCount())
        self.image_fusion_thread = QThreadPool()
        print("Multithreading with maximum %d threads" % self.image_fusion_thread.maxThreadCount())
        self.create_rain_drops_thread = QThreadPool()
        print("Multithreading with maximum %d threads" % self.create_rain_drops_thread.maxThreadCount())
        self.create_rain_drop_of_water_thread = QThreadPool()
        print("Multithreading with maximum %d threads" % self.create_rain_drop_of_water_thread.maxThreadCount())
        self.send_virtual_camera_thread = QThreadPool()
        print("Multithreading with maximum %d threads" % self.send_virtual_camera_thread.maxThreadCount())
        self.create_virtual_camera_thread = QThreadPool()
        print("Multithreading with maximum %d threads" % self.create_virtual_camera_thread.maxThreadCount())
        
        
        self.threads = [
            self.capture_thread,
            self.ascii_thread,
            self.image_fusion_thread,
            self.create_rain_drops_thread,
            self.create_rain_drop_of_water_thread,
            self.send_virtual_camera_thread,
            self.create_virtual_camera_thread
        ]
        
        
        self.timer = QTimer()
        self.timer.setInterval(1000)
        self.timer.timeout.connect(self.recurring_timer)
        self.timer.start()
            
    def progress_fn(self, n):
        print("%d%% done" % n)

    def execute_this_fn(self, progress_callback):
        for n in range(0, 5):
            time.sleep(1)
            progress_callback.emit(n*100/4)

        return "Done."

    def print_output(self, s):
        print(s)

    def thread_complete(self):
        print("THREAD COMPLETE!")

    def oh_no(self):
        # Pass the function to execute
        worker1 = Worker(target=self.capture_frame) # Any other args, kwargs are passed to the run function
        worker1.signals.result.connect(self.print_output)
        worker1.signals.finished.connect(self.thread_complete)
        worker1.signals.progress.connect(self.progress_fn)
        
        self.capture_thread.start(worker1)
        # Execute
        self.threadpool.start(worker1)

        # Pass the function to execute
        worker2 = Worker(target=self.update_ascii_image) # Any other args, kwargs are passed to the run function
        worker2.signals.result.connect(self.print_output)
        worker2.signals.finished.connect(self.thread_complete)
        worker2.signals.progress.connect(self.progress_fn)
        # Execute
        self.ascii_thread.start(worker2)

        # Pass the function to execute
        worker3 = Worker(target=self.image_fusion) # Any other args, kwargs are passed to the run function
        worker3.signals.result.connect(self.print_output)
        worker3.signals.finished.connect(self.thread_complete)
        worker3.signals.progress.connect(self.progress_fn)
        
        # Execute
        self.image_fusion_thread.start(worker3)

        # Pass the function to execute
        worker4 = Worker(target=self.create_rain_drops) # Any other args, kwargs are passed to the run function
        worker4.signals.result.connect(self.print_output)
        worker4.signals.finished.connect(self.thread_complete)
        worker4.signals.progress.connect(self.progress_fn)
        
        # Execute
        self.create_rain_drops_thread.start(worker4)

        # Pass the function to execute
        worker5 = Worker(target=self.create_rain_drop_of_water) # Any other args, kwargs are passed to the run function
        worker5.signals.result.connect(self.print_output)
        worker5.signals.finished.connect(self.thread_complete)
        worker5.signals.progress.connect(self.progress_fn)
        
        # Execute
        self.create_rain_drop_of_water_thread.start(worker5)
        
        # Pass the function to execute
        worker6 = Worker(target=self.send_to_virtual_camera) # Any other args, kwargs are passed to the run function
        worker6.signals.result.connect(self.print_output)
        worker6.signals.finished.connect(self.thread_complete)
        worker6.signals.progress.connect(self.progress_fn)
        
        # Execute
        self.send_virtual_camera_thread.start(worker6)
        
        # Pass the function to execute
        worker7 = Worker(target=self.create_virtual_camera) # Any other args, kwargs are passed to the run function
        worker7.signals.result.connect(self.print_output)
        worker7.signals.finished.connect(self.thread_complete)
        worker7.signals.progress.connect(self.progress_fn)
        
        # Execute
        self.create_virtual_camera_thread.start(worker7)
        
    def recurring_timer(self):
        self.counter +=1
        print("Counter: %d" % self.counter)
            
    def stop(self):
        print("entre dans stop()\n")
        if self.capture:
            self.capture.release()
        # Arrêt propre du programme
        self.running = False
        sys.exit(0)
    
    
    def initUI(self):
        print("entre dans initUI()\n")
        # Créez un widget central pour contenir le contenu de la fenêtre principale
        central_widget = QWidget()
        self.setCentralWidget(central_widget)

        # Créez un layout vertical pour organiser les widgets
        self.layout = QVBoxLayout()

        # Appliquez le layout au widget central
        self.window_icon = QIcon(os.path.join(self.wd, "icon-32.png"))
        self.setWindowIcon(self.window_icon)
        central_widget.setLayout(self.layout)
        self.setWindowTitle("Matrix")
        self.setGeometry(300, 300, 1280, 720)

    def handle_camera_selected(self, selected_camera_capture):
        self.capture = selected_camera_capture

    
    def run(self):
        print("entre dans run()\n")
        # Capture the first frame outside the main loop
        #self.frame()
        self.oh_no()

        # Initialize the 'running' variable
        running = True

        while running:
            if not self.frame():
                break
            
            # Delay to slow down the loop
            time.sleep(0.1)

            # Capture a new frame before the next iteration
            self.frame()

            # if event.key() == Qt.Key_Escape:
                # self.running = False
            if self.running == False:
                running == self.running 
                break
        self.capture.release()
        cv2.destroyAllWindows()

    def closeEvent(self, event: QCloseEvent):
        print("entre dans closeEvent()\n")
        self.running = False
        self.stop()
        super(Matrix, self).closeEvent(event)
        
    def keyPressEvent(self, event: QKeyEvent):
        print("entre dans keyPressEvent()\n")
        self.running = False
        if event.key() == Qt.Key_Escape:
            self.running = False
            self.stop()
            self.closeEvent()
        else:
            super(Matrix, self).keyPressEvent(event)

    # Fonction pour convertir une intensité en caractère ASCII
    def get_character(self, intensity):
        print("entre dans get_character()\n")
        characters = self.characters
        num_levels = len(characters)
        level = intensity * (num_levels - 1) // 255
        print(characters[level])
        return characters[level] 

    # Fonction pour convertir une image en ASCII art
    def image_to_ascii(self, image):
        print("entre dans image_to_ascii()\n")
        ascii_font_size_width = self.ascii_font_size_width
        ascii_font_size_height = self.ascii_font_size_height
        if len(image.shape) > 2 and image.shape[2] == 3:
            gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        else:
            gray_image = image
        resized_image = cv2.resize(gray_image, (int(gray_image.shape[1] / (0.88 * ascii_font_size_height)), int(gray_image.shape[0] / (0.88 * ascii_font_size_width))))
        ascii_image = ""
        for i in range(resized_image.shape[0]):
            for j in range(resized_image.shape[1]):
                intensity = resized_image[i][j]
                ascii_image += self.get_character(intensity)
            ascii_image += "\n"
        print(ascii_image)
        return ascii_image

    #créer l'effets de pluie
    def create_rain_drops(self, event: QKeyEvent):
        print("entre dans create_rain_drop()\n")
        resized_image = np.zeros((720, 1280), dtype=np.uint8)
        self.drop_columns
        drop_positions = np.zeros(1280, dtype=int)
        while self.running:
            # Générer une nouvelle goutte de pluie
            if len(self.drop_columns) < 80:
                column = random.randint(0, resized_image.shape[1] - 1)  # Choix aléatoire de la colonne
                self.drop_columns.append(column)
                drop_positions[column] = 0  # Initialiser la position de la goutte à la ligne supérieure
            # Mettre à jour les positions des gouttes de pluie
            for column in self.drop_columns:
                row = drop_positions[column]
                # Réinitialiser la colonne à zéro pour effacer la goutte précédente
                if row >= resized_image.shape[0] - 1:
                    self.drop_columns.remove(column)
                    for row_to_erase in range(0, drop_positions[column]):
                        resized_image[row_to_erase][column] = 0
                else:
                    row += 1  # Descendre la goutte d'une ligne
                    drop_positions[column] = row  # Mettre à jour la position de la goutte
                    # Mettre à jour l'image avec la goutte de pluie
                    for row_line in range(0, row - 2):
                        resized_image[row_line][column] = 255 # Intensité maximale
                    # Ajouter uniquement les colonnes dans la queue
                    self.columns_launched_queue.put((column, row))
            # Mettre à jour l'affichage de l'ASCII art dans la fenêtre tkinter
            self.resized_image = resized_image
            a_image = self.image_to_ascii(resized_image)
            with self.ascii_image_lock:
                self.rain_ascii_image = a_image

            if event.key() == Qt.Key_Escape:
                self.running 
            
    def create_rain_drop_of_water(self, event: QKeyEvent):
        print("entre dans create_rain_drop_of_water()\n")
        max_rows = {}
        while self.running:  
            #with self.ascii_image_lock:
            while not self.columns_launched_queue.empty():
                # Mettre à jour les positions des gouttes de pluie
                column, row = self.columns_launched_queue.get()
                if column in max_rows:
                    max_rows[column] = max(max_rows[column], row)
                else:
                    max_rows[column] = row
            for column, row in max_rows.items():
                for row_erase in range(0, row - 10):
                    self.drop_of_water_image[row_erase][column] = 0
                for row_create in range(row - 10, row + 1):
                    self.drop_of_water_image[row_create][column] = 255
                # Mettre à jour l'affichage de l'ASCII art dans la fenêtre tkinter
                self.drop_of_water_image_ascii = self.image_to_ascii(self.drop_of_water_image)

            if event.key() == Qt.Key_Escape:
                self.running = False
                break

    # Fonction pour mettre à jour l'image capturée
    def capture_frame(self, event: QKeyEvent):
        print("entre dans capture_frame()\n")
        while self.running:
            ret, f = self.capture.read()
            cv2.waitKey(0)
            if ret:
                # Redimensionner l'image capturée pour qu'elle s'adapte aux dimensions du canevas
                resized_frame = cv2.resize(f, (self.width, self.height))
                # Créer un canevas vide
                canvas = np.zeros((self.height, self.width, 3), dtype=np.uint8)
                # Calculer les coordonnées pour placer le logo au centre du canevas
                logo_x = int((self.width - self.size1) / 2)
                logo_y = 0
                # Dessiner le logo sur le canevas
                canvas[logo_y:logo_y+self.size2, logo_x:logo_x+self.size1] = self.logo
                # Combiner le canevas avec l'image capturée redimensionnée
                combined_frame = cv2.addWeighted(resized_frame, .5, canvas, 1, 0)
                with self.frame_lock:
                    self.frame = combined_frame

            if event.key() == Qt.Key_Escape:
                self.running = False
                break

    # Fonction pour mettre à jour l'image ASCII
    def update_ascii_image(self, event: QKeyEvent):
        print("entre dans update_ascii_image()\n")
        while self.running:
            with self.frame_lock:
                f = self.frame
            if f is not None:
                self.y_image = self.image_to_ascii(f)
                with self.ascii_image_lock:
                    self.ascii_image = self.y_image
            time.sleep(0.001)  # Temps d'attente arbitraire
            print(self.ascii_image)
            if event.key() == Qt.Key_Escape:
                self.running = False
                break

    def image_fusion(self, event: QKeyEvent):
        print("entre dans image_fusion()\n")
        while self.running:
            with self.ascii_image_lock:
                self.ascii_image_cut = self.ascii_image.split("\n")
                rain_ascii_image_cut = self.rain_ascii_image.split("\n")
                rain_ascii_image_intermediate = []
                for i in range(len(self.ascii_image_cut)):
                    ascii_image_cut_line = list(self.ascii_image_cut[i])
                    rain_ascii_image_cut_line = list(rain_ascii_image_cut[i])
                    for j in range(len(rain_ascii_image_cut_line)):
                        if j < len(ascii_image_cut_line):
                            if rain_ascii_image_cut_line[j] != ' ' and rain_ascii_image_cut_line[j] in self.characters:
                                rain_ascii_image_cut_line[j] = ascii_image_cut_line[j]
                                ascii_image_cut_line[j] = ' '
                    rain_ascii_image_intermediate.append("".join(rain_ascii_image_cut_line))
                self.rain_ascii_image_result = "\n".join(rain_ascii_image_intermediate)
            time.sleep(0.001)
            if event.key() == Qt.Key_Escape:
                self.running = False
                break

    def send_to_virtual_camera(self, event: QKeyEvent):
        print("entre dans send_to_virtual_camera()\n")
        while self.running:
            # Capture the content of the canvas as an image
            canvas_image = Image.new('RGB', (self.width, self.height), 'black')
            draw = ImageDraw.Draw(canvas_image)
            font = ImageFont.truetype(self.font_path, self.ascii_font_size_width)
            draw.text((0, 0), self.ascii_image_result, fill='#008800', font=font)
            draw.text((0, 0), self.rain_ascii_image_result, fill='#00ff00', font=font)
            hex_vars = ['f', 'e', 'd', 'c', 'b', 'a', '9', '8']
            for hex_var in hex_vars:
                draw.text((0, 0), self.erase_rain_ascii_image, fill='#00'+ hex_var + hex_var + '00', font=font)
                time.sleep(0.01)
            draw.text((0, 0), self.drop_of_water_image_ascii, fill='white', font=font)
            self.virtual_frame = cv2.cvtColor(np.array(canvas_image), cv2.COLOR_RGB2BGR)

            # Affichez la miniature dans la fenêtre créée précédemment
            cv2.imshow("Matrix rain", self.virtual_frame)
        
            # Affichez la miniature dans la fenêtre créée précédemment
            # Convertir l'image OpenCV en QImage



            rgb_image = cv2.cvtColor(self.frame, cv2.COLOR_BGR2RGB)
            h, w, ch = rgb_image.shape
            bytes_per_line = ch * w
            qimage = QImage(rgb_image.data, w, h, bytes_per_line, QImage.Format_RGB888)

            # Créer un QLabel pour afficher l'image
            # Affichez la miniature dans la fenêtre créée précédemment

            image_label = QLabel()
            image_label.setPixmap(QPixmap.fromImage(qimage))
            #self.setCentralWidget(image_label)
            # Ajouter le QLabel à votre layout
            self.layout.addWidget(image_label)

            # Attendez une touche pour quitter
            if event.key() == Qt.Key_Escape:
                self.running = False
                break

        # Fermez la fenêtre et libérez les ressources
        cv2.destroyAllWindows()

    def create_virtual_camera(self, event: QKeyEvent):
        print("entre dans create_virtual_camera()\n")
        with pyvirtualcam.Camera(self.width, self.height, 30, device='/dev/video2') as cam:
            while self.running:
                # Redimensionne l'image pour qu'elle corresponde à la taille de la caméra virtuelle
                cam.send(self.virtual_frame)
                cam.sleep_until_next_frame()
                
                if event.key() == Qt.Key_Escape:
                    self.running = False
                    break

def main():
    print("entre dans main()\n")
    app = QApplication(sys.argv)
    main_window = Matrix()
    main_window.show()
    sys.exit(app.exec())
    
if __name__ == "__main__":
    main()