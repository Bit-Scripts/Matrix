import os
import platform
import queue
import random
import sys
import time
import cv2
import re
import numpy as np
import pyvirtualcam
import threading
from PIL import Image, ImageDraw, ImageFont
from PyQt6.QtCore import Qt, QObject, pyqtSignal, QTimer
from PyQt6.QtGui import QCloseEvent, QIcon, QImage, QKeyEvent, QPixmap, QColor, QPainter, QFont, QFontDatabase
from PyQt6.QtWidgets import QApplication, QMainWindow, QLabel, QVBoxLayout, QWidget, QComboBox, QPushButton

class Communicator(QObject):
    update_image_label_signal = pyqtSignal(QImage)
    def __init__(self, parent=None):
        super().__init__(parent)


class CameraApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.init_ui()
        
        if getattr(sys, 'frozen', False):
            import pyi_splash

            # Fermeture du splash screen
            pyi_splash.update_text('UI Loaded ...')
            pyi_splash.close()
            
        print("entre dans la init de CameraApp")
        self.cap = None
        self.timer = QTimer()

    def init_ui(self):
        print("entre dans init_ui()")
        self.setWindowTitle("CameraSelector")
        self.setWindowFlags(self.windowFlags() & ~Qt.WindowType.FramelessWindowHint)
        self.wd = sys._MEIPASS if getattr(sys, 'frozen', False) else ''
        self.setWindowIcon(QIcon(os.path.join(self.wd, "icon-32.png")))
        self.layout = QVBoxLayout()
        self.central_widget = QWidget()
        self.camera_selector = QComboBox()
        self.camera_selector.addItem("Caméra non choisie")
        self.populate_camera_selector()

        self.label = QLabel("Sélectionnez une caméra pour commencer")

        # Créez le bouton et connectez-le à la méthode open_matrix_window
        self.open_matrix_button = QPushButton("Ouvrir Matrix")
        self.open_matrix_button.clicked.connect(self.camera_chosen)
        
        # Ajoutez le bouton à votre interface utilisateur
        self.layout.addWidget(self.camera_selector)
        self.layout.addWidget(self.label)
        self.layout.addWidget(self.open_matrix_button)
        self.central_widget.setLayout(self.layout)
        self.setCentralWidget(self.central_widget)


    def camera_chosen(self):
        index = self.camera_selector.currentIndex()
        if index == 0:
            self.label.setText("Veuillez choisir une caméra.")  # Utilise setText pour mettre à jour le texte du QLabel
            return
        if self.cap is not None:
            self.cap.release()
        camera_names, camera_indices = self.get_available_cameras()
        camera_name = camera_names[index - 1]
        index = camera_indices[index - 1]
        self.label.setText(f"Matrix Launched with {camera_name}")  # Utilise setText pour mettre à jour le texte du QLabel
        self.matrix = Matrix()
        self.matrix.setCameraIndex(index)
        self.close()
        self.matrix.show()  # Affichage de la fenêtre Matrix
        print("Matrix Launched")

    def populate_camera_selector(self):
        print("entre dans populate_camera_selector()")
        camera_names, camera_indices = self.get_available_cameras()
        for name, index in zip(camera_names, camera_indices):
            self.camera_selector.addItem(f"{name} (Index: {index})", index)
            pass

    def get_available_cameras(self):
        print("entre dans get_available_cameras()")
        if sys.platform.startswith("linux"):
            camera_names, camera_indices = self.get_cameras_linux()
        elif sys.platform.startswith("win32"):
            camera_names, camera_indices = self.get_cameras_windows()
        elif sys.platform.startswith("darwin"): #macOS
            camera_names, camera_indices = self.get_cameras_mac()
        else:
            print("Plateforme non prise en charge")
            camera_names, camera_indices = [], []

        return camera_names, camera_indices


    def get_cameras_mac(self):
        print("entre dans get_cameras_mac()")
        try:
            import Quartz
        except ImportError:
            print("Installez pyobjc avec 'pip install pyobjc'")
            return {}

        camera_indices = []
        camera_names = []
        
        for index, device in enumerate(Quartz.IORegistryIteratorCreateForMatchingService(Quartz.kIOMasterPortDefault, Quartz.CFDictionaryCreate(None, (Quartz.kIOUSBDeviceClassName,), (True,), 1))):
            camera_name = Quartz.IORegistryEntryGetName(device)
            if "infrared" in camera_name.lower() or "ir" in camera_name.lower():
                continue  # Ignore the infrared camera
            camera_names.append(camera_name)
            camera_indices.append(index)
        return camera_names, camera_indices

    def get_cameras_windows(self):
        print("entre dans get_cameras_windows()")
        try:
            from ctypes import cast, POINTER
            from comtypes import CLSCTX_ALL
            from pywinusb import hid
        except ImportError:
            print("Installez pywinusb avec 'pip install pywinusb'")
            return {}

        camera_indices = []
        camera_names = []

        # Get a list of all connected HID devices
        all_devices = hid.find_all_hid_devices()

        # Filter the devices to only get cameras
        camera_devices = [device for device in all_devices if re.search("camera|webcam", device.product_name, re.IGNORECASE)]

        for index, device in enumerate(camera_devices):
            cap = cv2.VideoCapture(index)
            if cap is None or not cap.isOpened():
                cap.release()
                continue

            camera_name = device.product_name
            if "infrared" in camera_name.lower() or "ir" in camera_name.lower():
                continue  # Ignore the infrared camera
            camera_indices.append(index)
            camera_names.append(camera_name)
            cap.release()

        return camera_names, camera_indices


    def get_cameras_linux(self):
        try:
            from v4l2py import Device
        except ImportError:
            print("Installez v4l2py avec 'pip install v4l2py'")
            return {}

        devices = []
        camera_names = []
        camera_indices = []
        index = 0

        while True:
            try:
                cap = cv2.VideoCapture(index)
                if cap.isOpened():
                    devices.append(index)
                    cap.release()
                else:
                    print(f"Avertissement: Impossible d'ouvrir la caméra {index}")
                time.sleep(0.1)
                index += 1
                if index > 9:
                    break
            except Exception as e:
                print(f"Erreur lors de l'ouverture des caméras: {e}")
                break
            
        for index in devices:
            print(f"Récupération des informations de la caméra {index}")
            try:
                with Device.from_id(index) as cam:
                    cam.open()
                    camera_name = cam.info.card
                    if camera_name not in camera_names:
                        camera_names.append(camera_name)
                        camera_indices.append(index)
                    cam.close()
            except Exception as e:
                print(f"Erreur lors de l'accès à la caméra {index}: {e}")

        return camera_names, camera_indices


    def closeEvent(self, event):
        print("entre dans closeEvent()")
        if self.timer.isActive():
            self.timer.stop()
        
class Matrix(QMainWindow):
    def __init__(self):
        super().__init__()
        self.threads = []
        self.wd = sys._MEIPASS if getattr(sys, 'frozen', False) else ''
        
        self.running = True
        
        self.font_path = os.path.join(self.wd, '.', 'mtx.ttf')
        
        # Créez une file d'attente pour chaque variable partagée
        global columns_launched_queue, frame_queue, ascii_image_result_queue, rain_ascii_image_queue, drop_of_water_image_ascii_queue, virtual_frame_queue, running
        columns_launched_queue = queue.Queue()
        frame_queue = queue.Queue()
        ascii_image_result_queue = queue.Queue()
        rain_ascii_image_queue = queue.Queue()
        drop_of_water_image_ascii_queue = queue.Queue()
        virtual_frame_queue = queue.Queue()
        self.queues = [columns_launched_queue, frame_queue, ascii_image_result_queue, rain_ascii_image_queue, drop_of_water_image_ascii_queue, virtual_frame_queue]
        
        running = True
        
        self.communicator = Communicator()
        self.communicator.update_image_label_signal.connect(self.update_image_label)
        
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
            
        self.counter = 0
        self.timer = QTimer(self)
        self.image_label = QLabel()
        self.timer.timeout.connect(self.update_counter) 
        self.timer.start(1000)

        # Définition des caractères à utiliser pour l'ASCII art  
        #characters = ' ú.ù,:öøýü×ÖÅ³·ÈØÙÍÐ±´¶¹º¼Â²ÇËÒÓ¾Ú'

        self.rain_intensity = 0.5
        self.image_updated = ""

        width, height = 854, 480

        self.ascii_font_size_width = 20
        self.ascii_font_size_height = self.ascii_font_size_width * 9 / 16
        
        self.font_path = os.path.join(self.wd, 'mtx.ttf')
        self.canvas_image = Image.new('RGB', (width, height), 'black')
        self.draw = ImageDraw.Draw(self.canvas_image)
        self.font = ImageFont.truetype(self.font_path, self.ascii_font_size_width)
                
        # Variables partagées entre les threads
        self.ascii_image = ""
        ascii_image_result, rain_ascii_image, rain_ascii_image_result, drop_of_water_image_ascii = "", "","", ""
        # initialisation des ascii art
        for line in range(0, 106):
            for column in range(0, 106):
                ascii_image_result += ' '
                rain_ascii_image += ' '
                rain_ascii_image_result += ' '
                drop_of_water_image_ascii += ' '
            ascii_image_result += '\n'
            rain_ascii_image += '\n'
            rain_ascii_image_result += '\n'
            drop_of_water_image_ascii += '\n'
    
    def update_counter(self):
        print("entre dans update_counter()\n")
        self.counter += 1
        self.counter_string = str(self.counter)
        
        if random.randint(0, 9) % 2 == 0:
            self.counter_string = self.counter_string.replace("0", "¦")
        if random.randint(0, 9) % 2 == 0:
            self.counter_string = self.counter_string.replace("1","§")
        if random.randint(0, 9) % 2 == 0:
            self.counter_string = self.counter_string.replace("2", "¨")
        if random.randint(0, 9) % 2 == 0:
            self.counter_string = self.counter_string.replace("3", "©")
        if random.randint(0, 9) % 2 == 0:
            self.counter_string = self.counter_string.replace("4", "ª")
        if random.randint(0, 9) % 2 == 0:
            self.counter_string = self.counter_string.replace("5", "«")
        if random.randint(0, 9) % 2 == 0:
            self.counter_string = self.counter_string.replace("6", "¬")
        if random.randint(0, 9) % 2 == 0:
            self.counter_string = self.counter_string.replace("8", "®")
        if random.randint(0, 9) % 2 == 0:
            self.counter_string = self.counter_string.replace("9", "¯")

            
        pixmap = QPixmap(854, 480)  # Créez un QPixmap de la taille souhaitée
        pixmap.fill(QColor(0,0,0))  # Remplissez-le avec une couleur transparente

        painter = QPainter(pixmap)
        
        font_id = QFontDatabase.addApplicationFont(self.font_path)
        if font_id < 0: print("Error")
        families = QFontDatabase.applicationFontFamilies(font_id)
        painter.setFont(QFont(families[0], 40))
        painter.setPen(QColor("#008800"))
        
        self.counter_txt = "C O M P T E U R : "
        
        if random.randint(0, 9) % 2 == 0:
            self.counter_txt = self.counter_txt.replace("C", "Ý")
        if random.randint(0, 9) % 2 == 0:
            self.counter_txt = self.counter_txt.replace("M", "ç")
        if random.randint(0, 9) % 2 == 0:
            self.counter_txt = self.counter_txt.replace("P", "ê")
        if random.randint(0, 9) % 2 == 0:
            self.counter_txt = self.counter_txt.replace("T", "î")
        if random.randint(0, 9) % 2 == 0:
            self.counter_txt = self.counter_txt.replace("E", "ß")
        if random.randint(0, 9) % 2 == 0:
            self.counter_txt = self.counter_txt.replace("U", "ï")
        if random.randint(0, 9) % 2 == 0:
            self.counter_txt = self.counter_txt.replace("R", "ì")

            
        print(self.counter_txt + self.counter_string)
            
        painter.drawText(pixmap.rect(), Qt.AlignmentFlag.AlignCenter, self.counter_txt + self.counter_string)
        
        painter.end()
        if random.randint(0, 9) % 3 == 0:
            self.image_label.setPixmap(pixmap)
    
    def launch_multithread(self):
        print("entre dans launch_multithread()\n")
        self.methods = [
            self.update_ascii_image,
            self.create_rain_drops,
            self.send_to_virtual_camera,
            self.create_virtual_camera
        ]
        
        # Lancement des threads
        count = 1
        for method in self.methods:
            thread = threading.Thread(target=method)
            thread.start()
            print(f"{method.__name__} dans le thread {count}\n")
            self.threads.append(thread)
            count += 1
            
        self.initUI()
            
            
    def setCameraIndex(self, index):
        global cap
        print("entre dans setCameraIndex()\n")
        print(f"Caméra sélectionnée : {index}")
        self.camera_index = index
        print(f"Setting camera with index {self.camera_index}")

        # Create a new instance of cv2.VideoCapture with the selected camera index
        # Open the camera
        if platform.system() == 'Windows':
            self.cap = cv2.VideoCapture(self.camera_index, cv2.CAP_DSHOW)
        else:
            self.cap = cv2.VideoCapture(self.camera_index)

        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 854)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
        self.capture_fps = 30
        cap = self.cap
        self.thread_capture_frame = threading.Thread(target=self.capture_frame)
        self.thread_capture_frame.start()
        
        self.threads.append(self.thread_capture_frame)
        
        self.launch_multithread()  # Lancement des threads
        

    def stop(self):
        print("entre dans stop()\n")
        global running
        running = False
        for queue in self.queues:
            for _ in range(3):
                queue.put(None)
            queue.queue.clear()
        #print("Toutes les Files d'Attentes ont étées vidées\n")
        for thread in self.threads:
            thread.join(timeout=.25)
            time.sleep(.251)
        #print("Tous les Multiples Threads ont étés arrêtées\n")
        sys.exit(0)
        
    def update_image_label(self, qimage):
        self.image_label.setPixmap(QPixmap.fromImage(qimage))
    
    def initUI(self):
        print("entre dans initUI()\n")
        self.setWindowFlags(self.windowFlags() & ~Qt.WindowType.FramelessWindowHint)
        
        # Appliquez le layout au widget central
        self.window_icon = QIcon(os.path.join(self.wd, "icon-32.png"))
        self.setWindowIcon(self.window_icon)
        self.setWindowTitle("Matrix")
        self.setGeometry(300, 300, 854, 480)
        
        # Créez une instance de QWidget
        self.central_widget = QWidget()
        # Définissez le widget central
        self.setCentralWidget(self.central_widget)
        
        
        # Utilisez le QWidget central comme parent pour le QVBoxLayout
        self.layout = QVBoxLayout(self.central_widget) 
        
        # Instanciez QLabel et assignez-le à self.image_label
        self.image_label = QLabel()

        # Créez une QPixmap vide de taille 854x480
        pixmap = QPixmap(854, 480)
        pixmap.fill(QColor(0, 0, 0))
        
        # Attribuez la QPixmap au QLabel
        self.image_label.setPixmap(pixmap)

        # Ajoutez le QLabel image_label au layout
        self.layout.addWidget(self.image_label)
        
        # self.setLayout(self.layout)

        #self.launch_multithread()
        self.show()
        self.camera_app = CameraApp()
        self.camera_app.close()

    def closeEvent(self, event: QCloseEvent):
        global running
        print("entre dans closeEvent()\n")
        running = False
        for queue in self.queues:
            for _ in range(3):
                queue.put(None)
            queue.queue.clear()
        #print("Toutes les Files d'Attentes ont étées vidées\n")
        for thread in self.threads:
            thread.join(timeout=.25)
            time.sleep(.251)
        #print("Tous les Multiples Threads ont étés arrêtées\n")
        sys.exit(0)
        
    def keyPressEvent(self, event: QKeyEvent):
        global running
        print("entre dans keyPressEvent()\n")
        if event.key() == Qt.Key.Key_Escape:
            running = False
            self.stop()
            self.closeEvent()
        else:
            super(Matrix, self).keyPressEvent(event)

    # Fonction pour convertir une intensité en caractère ASCII
    def get_character(self, intensity):
        characters = ' ú.ù,:öøýü×ÖÅ³·ÈØÙÍÐ±´¶¹º¼Â²ÇËÒÓ¾Ú'
        num_levels = len(characters)
        level = intensity * (num_levels - 1) // 255
        return characters[level] 

    # Fonction pour convertir une image en ASCII artq
    def image_to_ascii(self, image):
        ascii_font_size_width = 8
        ascii_font_size_height = ascii_font_size_width * 9 / 16
        ratio = 1.725
        try:
            if len(image.shape) > 2 and image.shape[2] == 3:
                gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
            else:
                gray_image = image
            resized_image = cv2.resize(gray_image, (int(gray_image.shape[1] / (ratio * ascii_font_size_height)), int(gray_image.shape[0] / (ratio * ascii_font_size_width))))
            ascii_image = ""
            for i in range(resized_image.shape[0]):
                for j in range(resized_image.shape[1]):
                    intensity = resized_image[i][j]
                    ascii_image += self.get_character(intensity)
                ascii_image += "\n"
            return ascii_image
        except Exception as e:
            print(f"Erreur dans image_to_ascii: {e}")

    # créer l'effets de pluie
    def create_rain_drops(self):
        global rain_ascii_image_queue, drop_of_water_image_ascii_queue, running
        print("on rentre dans rain_drops()")
        drop_positions = np.zeros(854, dtype=int)
        drop_of_water_image = np.zeros((480, 854), dtype=np.uint8)
        blank_image = np.zeros((480, 854), dtype=np.uint8)
        drop_columns = []
        try:
            while running:
                if len(drop_columns) < 80:
                    column = random.randint(0, blank_image.shape[1] - 1)
                    drop_columns.append(column)
                    drop_positions[column] = 0
                for column in drop_columns:
                    row = drop_positions[column]
                    if row >= blank_image.shape[0] - 1:
                        drop_columns.remove(column)
                        for row_to_erase in range(0, row):
                            if row_to_erase < 480:
                                blank_image[row_to_erase][column] = 0
                    else:
                        row += 1
                        drop_positions[column] = row
                        for row_line in range(0, row):
                            blank_image[row_line][column] = 255
                        row_drop = row + 2
                        if row_drop < 480:
                            for row_erase in range(0, row_drop):
                                drop_of_water_image[row_erase][column] = 0
                            for row_create in range(row_drop-2, row_drop + 5):
                                if row_create < 480:
                                    drop_of_water_image[row_create][column] = 255

                rain_ascii_image = self.image_to_ascii(blank_image)
                drop_of_water_image_ascii = self.image_to_ascii(drop_of_water_image)

                drop_of_water_image_ascii_queue.put(drop_of_water_image_ascii)                
                rain_ascii_image_queue.put(rain_ascii_image)

        except Exception as e:
            print(f"Erreur dans create_rain_drops: {e}")

    # Fonction pour mettre à jour l'image capturée
    def capture_frame(self):
        global frame_queue, cap, running
        capture = cap
        print("entre dans capture_frame()\n" + str(running))
        wd = sys._MEIPASS if getattr(sys, 'frozen', False) else ''
        width, height = 854, 480
        logo = cv2.imread(os.path.join(wd, 'MatrixLogo.png'))
        size1, size2 = 854, 150
        logo = cv2.resize(logo, (size1, size2))       
        while running:
            try:
                self.communicator.update_image_label_signal.connect(self.update_image_label)
                ret, frame = capture.read()
                f = frame
                if ret:
                    # Redimensionner l'image capturée pour qu'elle s'adapte aux dimensions du canevas
                    resized_frame = cv2.resize(f, (width, height))
                    # Créer un canevas vide
                    canvas = np.zeros((height, width, 3), dtype=np.uint8)
                    # Calculer les coordonnées pour placer le logo au centre du canevas
                    logo_x = int((width - size1) / 2)
                    logo_y = 0
                    # Dessiner le logo sur le canevas
                    canvas[logo_y:logo_y+size2, logo_x:logo_x+size1] = logo
                    # Combiner le canevas avec l'image capturée redimensionnée
                    combined_frame = cv2.addWeighted(resized_frame, .5, canvas, 1, 0)
                    
                    frame = combined_frame
                    frame_queue.put(frame)
                    
            except Exception as e:
                print(f"Erreur dans capture_frame: {e}")

    # Fonction pour mettre à jour l'image ASCII
    def update_ascii_image(self):
        global frame_queue, ascii_image_result_queue, running
        frame = None
        try:
            print("entre dans update_ascii_image()\n" + str(running))
            while running:    
                if not frame_queue.empty():
                    while not frame_queue.empty():
                        frame = frame_queue.get()   
                else:
                    pass
                f = frame
                if f is not None:
                    y_image = self.image_to_ascii(f)
                    ascii_image_result = y_image   
                    ascii_image_result_queue.put(ascii_image_result)
                time.sleep(0.001)
        except Exception as e:
            print(f"Erreur dans update_ascii_image: {e}")
            
    def send_to_virtual_camera(self):
        global ascii_image_result_queue, rain_ascii_image_queue, drop_of_water_image_ascii_queue, virtual_frame_queue, running
        width, height = 854, 480
        ascii_font_size_width = 16
        wd = sys._MEIPASS if getattr(sys, 'frozen', False) else ''
        font_path = os.path.join(wd, '.', 'mtx.ttf')
        
        # Initialisez les variables avec des valeurs par défaut
        ascii_image_result = ""
        rain_ascii_image = ""
        drop_of_water_image_ascii = ""
        
        try:
            print("entre dans send_to_virtual_camera()\n" + str(running))
            while running:
                if not ascii_image_result_queue.empty():
                    while not ascii_image_result_queue.empty():
                        ascii_image_result = ascii_image_result_queue.get()
                else:
                    pass
                
                if not drop_of_water_image_ascii_queue.empty():
                    drop_of_water_image_ascii = drop_of_water_image_ascii_queue.get()
                else:
                    pass
                
                if not rain_ascii_image_queue.empty():
                    rain_ascii_image = rain_ascii_image_queue.get()
                else:
                    pass

                canvas_image = Image.new('RGB', (width, height), 'black')
                draw = ImageDraw.Draw(canvas_image)
                font = ImageFont.truetype(font_path, ascii_font_size_width)
                draw.text((0, 0), ascii_image_result, fill='#006600', font=font)
                draw.text((0, 0), rain_ascii_image, fill='#00ff00', font=font)
                draw.text((0, 0), drop_of_water_image_ascii, fill='white', font=font)
                virtual_frame = cv2.cvtColor(np.array(canvas_image), cv2.COLOR_RGB2BGR)

                rgb_image = cv2.cvtColor(virtual_frame, cv2.COLOR_BGR2RGB)
                h, w, ch = rgb_image.shape
                bytes_per_line = ch * w
                qimage = QImage(rgb_image.data, w, h, bytes_per_line, QImage.Format.Format_RGB888)
                
                self.communicator.update_image_label_signal.emit(qimage)

                virtual_frame = virtual_frame
                virtual_frame_queue.put(virtual_frame)

        except Exception as e:
            print(f"Erreur dans send_to_virtual_camera: {e}")

    def create_virtual_camera(self):
        global virtual_frame_queue, running
        print("entre dans create_virtual_camera()\n")
        virtual_frame = np.zeros((480, 854, 3), dtype=np.uint8)
        old_virtual_frame = virtual_frame
        while running:
            try:
                if sys.platform.startswith("linux"):
                    with pyvirtualcam.Camera(width=854, height=480, fps=30, device='/dev/video4') as cam:
                        if not virtual_frame_queue.empty():
                            while not virtual_frame_queue.empty():
                                virtual_frame = virtual_frame_queue.get()
                            cam.send(virtual_frame)
                            cam.sleep_until_next_frame()
                        else:
                            virtual_frame = old_virtual_frame
                            cam.send(virtual_frame)
                            cam.sleep_until_next_frame()
                            # raise ValueError("virtual_frame n'est pas encore disponible")
                else:                
                    with pyvirtualcam.Camera(width=854, height=480, fps=30) as cam:
                        if not virtual_frame_queue.empty():
                            while not virtual_frame_queue.empty():
                                virtual_frame = virtual_frame_queue.get()
                            cam.send(virtual_frame)
                            cam.sleep_until_next_frame()
                        else:
                            virtual_frame = old_virtual_frame
                            cam.send(virtual_frame)
                            cam.sleep_until_next_frame()
                            #raise ValueError("virtual_frame n'est pas encore disponible")
                old_virtual_frame = virtual_frame
            except Exception as e:
                print(f"Erreur dans create_virtual_camera: {e}")
                pass

if __name__ == "__main__":
    app = QApplication([])
    camera_app = CameraApp()
    camera_app.show()
    app.exec()