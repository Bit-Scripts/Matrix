import sys
import os
import platform
import time
import threading
import queue
import random

import cv2
import numpy as np
import pyvirtualcam

from PyQt6.QtWidgets import QApplication, QMainWindow, QLabel, QVBoxLayout, QWidget, QPushButton, QComboBox
from PyQt6.QtCore import QThread, pyqtSignal, Qt, pyqtSignal
from PyQt6.QtGui import QKeyEvent, QImage, QCloseEvent, QIcon, QPixmap

from PIL import Image, ImageDraw, ImageFont

from camera_selector import CameraSelector

class Worker(QThread):
    signal = pyqtSignal(str)

    def __init__(self, text):
        super().__init__()
        self.text = text

    def run(self):
        while True:
            self.signal.emit(self.text)

class Matrix(QMainWindow):
    def __init__(self, camera_selector_instance, parent=None):
        super(Matrix, self).__init__(parent)
        
        self.wd = sys._MEIPASS if getattr(sys, 'frozen', False) else ''
        
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

        self.capture.connect(self.on_camera_selected)
        
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
            
    def start_all_thread(self):
        # Lancement des threads
        self.capture_thread = Worker("capture_thread")
        self.ascii_thread = Worker("ascii_thread")
        self.image_fusion_thread = Worker("capture_thread")
        self.create_rain_drops_thread = Worker("capture_thread")
        self.create_rain_drop_of_water_thread = Worker("capture_thread")
        self.send_virtual_camera_thread = Worker("capture_thread")
        self.create_virtual_camera_thread = Worker("capture_thread")
        
        self.capture_thread.signal.connect(target=self.capture_frame)
        self.ascii_thread.signal.connect(target=self.update_ascii_image)
        self.image_fusion_thread.signal.connect(target=self.image_fusion)

        self.resized_image = np.zeros((720, 1280), dtype=np.uint8)
        self.drop_of_water_image = self.resized_image
        self.erase_rain_image = self.resized_image
        self.virtual_frame = cv2.cvtColor(np.array(self.resized_image), cv2.COLOR_RGB2BGR)
        self.drop_positions = np.zeros(1280, dtype=int)

        self.create_rain_drops_thread.signal.connect(target=self.create_rain_drops)
        self.create_rain_drop_of_water_thread.signal.connect(target=self.create_rain_drop_of_water)

        self.image_updated = False
        self.buffer = None

        self.send_virtual_camera_thread.signal.connect(target=self.send_to_virtual_camera)
        self.create_virtual_camera_thread.signal.connect(target=self.create_virtual_camera)

        self.threads = [self.capture_thread, 
                        self.ascii_thread, 
                        self.image_fusion_thread, 
                        self.create_rain_drops_thread, 
                        self.create_rain_drop_of_water_thread, 
                        self.send_virtual_camera_thread, 
                        self.create_virtual_camera_thread
                        ]

        for thread in self.threads:
            thread.daemon = True
            thread.start()
    
    def stop(self):
        # Libération des ressources
        self.capture.release()
        # Arrêt propre du programme
        self.running = False
        for thread in self.threads:
            thread.join(timeout=1.0)
            time.sleep(1.001)
            sys.exit(0)
    
    
    def initUI(self):
        # Créez un widget central pour contenir le contenu de la fenêtre principale
        central_widget = QWidget()
        self.setCentralWidget(central_widget)

        # Créez un layout vertical pour organiser les widgets
        self.layout = QVBoxLayout()

        # Appliquez le layout au widget central
        self.setWindowIcon(self.window_icon)
        self.window_icon = QIcon(os.path.join(self.wd, "icon-32.png"))
        central_widget.setLayout(self.layout)
        self.setWindowTitle("Matrix")
        self.setGeometry(300, 300, 1280, 720)
        camera_selector = CameraSelector()
        self.setCentralWidget(camera_selector)

    def camera_selected(self):
        index = pyqtSignal(int)
        
        # Ouverture de la caméra
        if platform.system() == 'Windows':
            self.capture = cv2.VideoCapture(index,cv2.CAP_DSHOW)
        elif platform.system() == 'Linux':
            self.capture = cv2.VideoCapture(index)
            
        self.capture.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
        self.capture.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)

    def run(self, event: QKeyEvent):   
        # Capturez le premier frame en dehors de la boucle principale
        self.capture_frame()

        # Initialisez la variable 'running'
        running = True

        while running:
            if not self.capture_frame():
                break

            # Temporisation pour ralentir la boucle
            time.sleep(0.1)

            # Capturez un nouveau frame avant la prochaine itération
            self.capture_frame()

            if event.key() == Qt.Key_Escape:
                self.running = False
                break
        self.capture.release()
        cv2.destroyAllWindows()

    def closeEvent(self, event: QCloseEvent):
        self.running = False
        self.stop()
        event.accept()
        
    def keyPressEvent(self, event: QKeyEvent):
        self.running = False
        if event.key() == Qt.Key_Escape:
            self.stop()
            self.closeEvent()

        self.start_all_thread()
        self.run(event)

    # Fonction pour convertir une intensité en caractère ASCII
    def get_character(self, intensity):
        characters = self.characters
        num_levels = len(characters)
        level = intensity * (num_levels - 1) // 255
        print(characters[level])
        return characters[level] 

    # Fonction pour convertir une image en ASCII art
    def image_to_ascii(self, image):
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
            #with self.ascii_image_lock:
            self.rain_ascii_image = a_image

            if event.key() == Qt.Key_Escape:
                self.running 
            
    def create_rain_drop_of_water(self, event: QKeyEvent):
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
                #with self.frame_lock:
                self.frame = combined_frame

            if event.key() == Qt.Key_Escape:
                self.running = False
                break

    # Fonction pour mettre à jour l'image ASCII
    def update_ascii_image(self, event: QKeyEvent):
        while self.running:
            with self.frame_lock:
                f = self.frame
            if f is not None:
                self.y_image = self.image_to_ascii(f)
                #with self.ascii_image_lock:
                self.ascii_image = self.y_image
            time.sleep(0.001)  # Temps d'attente arbitraire
            print(self.ascii_image)
            if event.key() == Qt.Key_Escape:
                self.running = False
                break

    def image_fusion(self, event: QKeyEvent):
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
            # Convertir l'image OpenCV en QImage
            # height, width, channel = self.virtual_frame.shape
            # bytes_per_line = 3 * width
            # qimage = QImage(self.virtual_frame, width, height, bytes_per_line, QImage.Format_BGR888)
            qimage = QImage(canvas_image, canvas_image.width, canvas_image.height, QImage.Format_RGBA8888)
            # Créer un QLabel pour afficher l'image
            image_label = QLabel()
            image_label.setPixmap(QPixmap.fromImage(qimage))

            # Ajouter le QLabel à votre layout
            self.layout.addWidget(image_label)

            # Attendez une touche pour quitter
            if event.key() == Qt.Key_Escape:
                self.running = False
                break

        # Fermez la fenêtre et libérez les ressources
        cv2.destroyAllWindows()

    def create_virtual_camera(self, event: QKeyEvent):
        with pyvirtualcam.Camera(self.width, self.height, 30, device='/dev/video2') as cam:
            while self.running:
                # Redimensionne l'image pour qu'elle corresponde à la taille de la caméra virtuelle
                cam.send(self.virtual_frame)
                cam.sleep_until_next_frame()
                
                if event.key() == Qt.Key_Escape:
                    self.running = False
                    break

def main():
    app = QApplication(sys.argv)
    
    wd = sys._MEIPASS if getattr(sys, 'frozen', False) else ''
    window_icon = QIcon(os.path.join(wd, "icon-32.png"))
    
    camera_selector = CameraSelector()
    camera_selector.setWindowIcon(window_icon)
    camera_selector.show()

    # Wait for the CameraSelector window to close before continuing
    app.exec()

    matrix = Matrix(camera_selector.on_camera_selected)
    matrix.setWindowIcon(window_icon)
    matrix.run()
    sys.exit(app.exec())
    
if __name__ == "__main__":
    main()