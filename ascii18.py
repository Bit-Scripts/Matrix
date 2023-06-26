import os
os.environ["OPENCV_LOG_LEVEL"]="SILENT"
import cv2
import platform
import random
import sys
import time
import numpy as np
import pyvirtualcam
from PIL import Image, ImageDraw, ImageFont, ImageFilter
from PyQt6.QtCore import Qt, QTimer
from PyQt6.QtGui import QCloseEvent, QIcon, QImage, QKeyEvent, QPixmap, QColor, QPainter, QFont, QFontDatabase
from PyQt6.QtWidgets import QApplication, QMainWindow, QLabel, QVBoxLayout, QWidget, QComboBox, QPushButton, QFrame


class CameraApp(QMainWindow):
    def __init__(self, matrix):
        self.matrix = matrix
        super().__init__()
        self.init_ui()
        if getattr(sys, 'frozen', False):
            import pyi_splash

            # Fermeture du splash screen
            pyi_splash.update_text('UI Loaded ...')
            pyi_splash.close()
            
        # print("entre dans la init de CameraApp")
        self.cap = None
        self.timer = QTimer()

    def init_ui(self):
        # print("entre dans init_ui()")
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
        
        self.find_virtual_cameras_on_linux()
        
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
        matrix.initUI()
        matrix.setCameraIndex(index)
        matrix.show() 
        # Affichage de la fenêtre Matrix
        # print("Matrix Launched")
        self.close()

    def populate_camera_selector(self):
        # print("entre dans populate_camera_selector()")
        camera_names, camera_indices = self.get_available_cameras()
        for name, index in zip(camera_names, camera_indices):
            self.camera_selector.addItem(f"{name} (Index: {index})", index)
            pass

    def get_available_cameras(self):
        # print("entre dans get_available_cameras()")
        if sys.platform.startswith("linux"):
            camera_names, camera_indices = self.get_cameras_linux()
        elif sys.platform.startswith("win32"):
            camera_names, camera_indices = self.get_cameras_windows()
        elif sys.platform.startswith("darwin"): #macOS
            camera_names, camera_indices = self.get_cameras_mac()
        else:
            # print("Plateforme non prise en charge")
            camera_names, camera_indices = [], []

        return camera_names, camera_indices


    def get_cameras_mac(self):
        # print("entre dans get_cameras_mac()")
        try:
            import Quartz
        except ImportError:
            self.label.setText("Installez pyobjc avec 'pip install pyobjc'")
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
        # print("entre dans get_cameras_windows()")
        try:
            from pygrabber.dshow_graph import FilterGraph
            
        except ImportError:
            self.label.setText("Installez pygrabber avec 'pip install pygrabber'")
            return {}

        camera_indices = []
        camera_names = []

        # Get a list of all connected HID devices
        devices = FilterGraph().get_input_devices()

        camera_names, camera_indices = [], []
        
        for device_index, device_name in enumerate(devices):
            camera_names.append(device_name)
            camera_indices.append(device_index)
            
        return camera_names, camera_indices


    def get_cameras_linux(self):
        try:
            from v4l2py import Device
        except ImportError:
            self.label.setText("Installez v4l2py avec 'pip install v4l2py'")
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
                    # print(f"Avertissement: Impossible d'ouvrir la caméra {index}")
                    pass
                time.sleep(0.1)
                index += 1
                if index > 9:
                    break
            except Exception as e:
                print(f"Erreur lors de l'ouverture des caméras: {e}")
                break
            
        for index in devices:
            # print(f"Récupération des informations de la caméra {index}")
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
    
    def find_virtual_cameras_on_linux(self):
        try:
            import pyudev
        except ImportError:
            self.label.setText("Installez v4l2py avec 'pip install v4l2py'")
            return {}
        
        context = pyudev.Context()
        devices = context.list_devices(subsystem='video4linux')
        camera_find = False
        for device in devices:
            product_id = device.get('ID_V4L_PRODUCT')
            if product_id == 'Dummy video device (0x0000)':
                self.label.setText("Camera virtuelle activée")
                camera_find = True
        if not camera_find:
            self.label.setText("Veuillez activer la camera virtuelle pour continuer")
            self.open_matrix_button.setEnabled(False)

    def closeEvent(self, event):
        # print("entre dans closeEvent()")
        if self.timer.isActive():
            self.timer.stop()


class VirtualCamera():
    def __init__(self):
        global running
        running = True
        self.running = running
    
    def run(self, virtual_frame):
        self.video_device = self.find_virtual_cameras_on_linux()
        self.virtual_frame = virtual_frame
        if self.running:
            # print("entre dans virtual_camera.create_virtual_camera()\n")
            if sys.platform.startswith("linux"):
                with pyvirtualcam.Camera(width=1280, height=720, fps=30, device=f"{self.video_device}") as cam:
                    try:
                        virtual_frame = self.virtual_frame
                        virtual_frame_resized = self.resize_image(virtual_frame, 1280, 720)
                        cam.send(virtual_frame_resized)
                        cam.sleep_until_next_frame()
                    except Exception as e:
                        print(f"Erreur dans virtual_camera.create_virtual_camera: {e}")
                        pass
            elif sys.platform.startswith("win32"): 
                with pyvirtualcam.Camera(width=1280, height=720, fps=30, backend ='unitycapture') as cam:
                    try:
                        virtual_frame = self.virtual_frame
                        virtual_frame_resized = self.resize_image(virtual_frame, 1280, 720)
                        cam.send(virtual_frame_resized)
                        cam.sleep_until_next_frame()
                    except Exception as e:
                        print(f"Erreur dans virtual_camera.create_virtual_camera: {e}")
                        pass
                    self.old_frame = virtual_frame_resized
    def resize_image(self, image, width, height):
        resized_image = cv2.resize(image, (width, height))
        return resized_image

    def find_virtual_cameras_on_linux(self):
        import pyudev
        context = pyudev.Context()
        devices = context.list_devices(subsystem='video4linux')
        video_device = ""
        for device in devices:
            product_id = device.get('ID_V4L_PRODUCT')
            if product_id == 'Dummy video device (0x0000)':
                video_device = device.device_node
        return video_device
        
    def update_frame(self, virtual_frame):
        if self.running:
            self.virtual_frame = virtual_frame
            self.old_frame = self.virtual_frame
            
    def stop(self):
        global running
        running = False
        self.running = running

class VideoTreatment():
    def __init__(self, frame, rain_00ff00_image, rain_00ee00_image, rain_00dd00_image, rain_00cc00_image, rain_00bb00_image, rain_00aa00_image, rain_009900_image, rain_008800_image, rain_007700_image, drop_of_water_image_ascii, matrix_instance):
        self.matrix_instance = matrix_instance
        self.len_array_width = 110
        self.len_array_height = 34
        super().__init__()
        self.frame = frame
        self.rain_drops = [[-1] * 110 for _ in range(2)]
        self.rain_00ff00_image = rain_00ff00_image
        self.rain_00ee00_image = rain_00ee00_image
        self.rain_00dd00_image = rain_00dd00_image
        self.rain_00cc00_image = rain_00cc00_image
        self.rain_00bb00_image = rain_00bb00_image
        self.rain_00aa00_image = rain_00aa00_image
        self.rain_009900_image = rain_009900_image
        self.rain_008800_image = rain_008800_image
        self.rain_007700_image = rain_007700_image
        self.drop_of_water_image_ascii = drop_of_water_image_ascii
        global running
        running = True
        self.running = running
        self.virtual_frame = np.zeros((480, 848, 3), dtype=np.uint8)

    def update_camera_frame(self, camera_frame):
        self.update_ascii_image(camera_frame)        


    # Fonction pour convertir une intensité en caractère ASCII
    def get_character(self, intensity):
        if self.running:
            characters = ' ú.ù,:öøýü×ÖÅ³·ÈØÙÍÐ±´¶¹º¼Â²ÇËÒÓ¾Ú'
            num_levels = len(characters)
            level = intensity * (num_levels - 1) // 255
            # level = intensity * (num_levels - 1) // 765
            return characters[level] 

        
    # Fonction pour convertir une image en ASCII artq
    def image_to_ascii(self, image):
        if self.running:
            try:
                ascii_image = []
                if len(image.shape) > 2 and image.shape[2] == 3:
                    gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
                else:
                    gray_image = image
                resized_image = cv2.resize(gray_image, (self.len_array_width, self.len_array_height))
                for i in range(resized_image.shape[0]):
                    row = []
                    for j in range(resized_image.shape[1]):
                        intensity = resized_image[i][j]
                        row.append(self.get_character(intensity))
                    ascii_image.append(row)
                return ascii_image
                
                # resized_image = cv2.resize(image, (self.len_array_width, self.len_array_height))
                # canal_bleu, canal_vert, canal_rouge = cv2.split(resized_image)
                # for i in range(resized_image.shape[0]):
                #     row = []
                #     for j in range(resized_image.shape[1]):
                #         intensity = canal_bleu[i, j] + canal_vert[i, j] + canal_rouge[i, j]
                #         row.append(self.get_character(intensity))
                #     ascii_image.append(row)
                # return ascii_image
            except Exception as e:
                print(f"Erreur dans video_treatment.image_to_ascii: {e}")

    # Fonction pour mettre à jour l'image ASCII
    def update_ascii_image(self, frame):
        if self.running:
            try:
                # print("entre dans video_treatment.update_ascii_image()\n")
                f = frame
                y_image = self.image_to_ascii(f)
                ascii_image = y_image   
                time.sleep(0.001)
                self.create_rain_drops(ascii_image)
            except Exception as e:
                print(f"Erreur dans video_treatment.update_ascii_image: {e}")

    # Créer l'effet de pluie
    def create_rain_drops(self, ascii_image):
        if self.running:
            try:
                # if len(self.drop_columns) < self.len_array_width:
                #     for _ in range(self.len_array_width - len(self.drop_columns)):
                #         column = random.randint(0, self.len_array_width - 1)
                #         self.drop_columns.append(column)
                #         print(f"\nnombre de goutte après ajout {len(self.drop_columns)}")
                for column in range(110):
                    if self.rain_drops[0][column] == -1:
                        if self.drop_of_water_image_ascii[0][column] == ' ':
                            self.rain_drops[0][column] = 0
                    else:
                        if self.rain_drops[0][column] == self.len_array_height - 1:
                            self.rain_drops[1][column] = 0

                        if self.rain_drops[1][column] == self.len_array_height - 1:
                            self.rain_drops[0][column] = 0
                            
                    column_type = column % 3
                    
                    for i in range(2):
                        row = self.rain_drops[i][column]
                        if random.randint(0, 9) % 6 == 0 and row != -1:
                            if column_type == 0:
                                row += random.randint(0, 1)
                            elif column_type == 1:
                                row += random.randint(0, 1)
                            elif column_type == 2:
                                row += random.randint(0, 1)
                                
                        self.rain_drops[i][column] = row


                        if row < self.len_array_height:
                            self.drop_of_water_image_ascii[row][column] = ascii_image[row][column]
                        if row - 1 >= 0 and row - 1 < self.len_array_height:
                            self.drop_of_water_image_ascii[row - 1][column] = ' '
                            self.rain_00ff00_image[row - 1][column] = ascii_image[row - 1][column]
                        if row - 2 >= 0 and row - 2 < self.len_array_height:
                            self.rain_00ff00_image[row - 2][column] = ' '
                            self.rain_00ee00_image[row - 2][column] = ascii_image[row - 2][column]
                        if row - 3 >= 0 and row - 3 < self.len_array_height:
                            self.rain_00ee00_image[row - 3][column] = ' '
                            self.rain_00dd00_image[row - 3][column] = ascii_image[row - 3][column]
                        if row - 4 >= 0 and row - 4 < self.len_array_height:
                            self.rain_00dd00_image[row - 4][column] = ' '
                            self.rain_00cc00_image[row - 4][column] = ascii_image[row - 4][column]
                        if row - 5 >= 0 and row - 5 < self.len_array_height:
                            self.rain_00cc00_image[row - 5][column] = ' '
                            self.rain_00bb00_image[row - 5][column] = ascii_image[row - 5][column]
                        if row - 6 >= 0 and row - 6 < self.len_array_height:
                            self.rain_00bb00_image[row - 6][column] = ' '
                            self.rain_00aa00_image[row - 6][column] = ascii_image[row - 6][column]
                        if row - 7 >= 0 and row - 7 < self.len_array_height:
                            self.rain_00aa00_image[row - 7][column] = ' '
                            self.rain_009900_image[row - 7][column] = ascii_image[row - 7][column]
                        if row - 8 >= 0 and row - 8 < self.len_array_height:
                            self.rain_009900_image[row - 8][column] = ' '
                            self.rain_008800_image[row - 8][column] = ascii_image[row - 8][column]
                        if row - 9 >= 0 and row - 9 < self.len_array_height:
                            self.rain_008800_image[row - 9][column] = ' '
                            self.rain_007700_image[row - 9][column] = ascii_image[row - 9][column]
                        if row - 10 >= 0 and row - 10 < self.len_array_height:    
                            self.rain_007700_image[row - 10][column] = ' '
                        if self.rain_00bb00_image[self.len_array_height - 1][column] != ' ':
                            self.rain_00bb00_image[self.len_array_height - 1][column] = ' '
                            self.rain_00aa00_image[self.len_array_height - 2][column] = ' '
                            self.rain_009900_image[self.len_array_height - 3][column] = ' '
                            self.rain_008800_image[self.len_array_height - 4][column] = ' '
                            self.rain_007700_image[self.len_array_height - 5][column] = ' '

                ascii_image_result = ""
                drop_of_water_image_ascii_result = ""
                rain_00ff00_image_result = ""
                rain_00ee00_image_result = ""
                rain_00dd00_image_result = ""
                rain_00cc00_image_result = ""
                rain_00bb00_image_result = ""
                rain_00aa00_image_result = ""
                rain_009900_image_result = ""
                rain_008800_image_result = ""
                rain_007700_image_result = ""

                for row in range(self.len_array_height):
                    ascii_image_row = ""
                    drop_of_water_image_ascii_row = ""
                    rain_00ff00_image_row = ""
                    rain_00ee00_image_row = ""
                    rain_00dd00_image_row = ""
                    rain_00cc00_image_row = ""
                    rain_00bb00_image_row = ""
                    rain_00aa00_image_row = ""
                    rain_009900_image_row = ""
                    rain_008800_image_row = ""
                    rain_007700_image_row = ""
                    for col in range(self.len_array_width):
                        if row < self.len_array_height and col < self.len_array_width:
                            ascii_image_row += ascii_image[row][col]
                            drop_of_water_image_ascii_row += self.drop_of_water_image_ascii[row][col]
                            rain_00ff00_image_row += self.rain_00ff00_image[row][col]
                            rain_00ee00_image_row += self.rain_00ee00_image[row][col]
                            rain_00dd00_image_row += self.rain_00dd00_image[row][col]
                            rain_00cc00_image_row += self.rain_00cc00_image[row][col]
                            rain_00bb00_image_row += self.rain_00bb00_image[row][col]
                            rain_00aa00_image_row += self.rain_00aa00_image[row][col]
                            rain_009900_image_row += self.rain_009900_image[row][col]
                            rain_008800_image_row += self.rain_008800_image[row][col]
                            rain_007700_image_row += self.rain_007700_image[row][col]

                    ascii_image_result += ascii_image_row + '\n'
                    drop_of_water_image_ascii_result += drop_of_water_image_ascii_row + '\n'
                    rain_00ff00_image_result += rain_00ff00_image_row + '\n'
                    rain_00ee00_image_result += rain_00ee00_image_row + '\n'
                    rain_00dd00_image_result += rain_00dd00_image_row + '\n'
                    rain_00cc00_image_result += rain_00cc00_image_row + '\n'
                    rain_00bb00_image_result += rain_00bb00_image_row + '\n'
                    rain_00aa00_image_result += rain_00aa00_image_row + '\n'
                    rain_009900_image_result += rain_009900_image_row + '\n'
                    rain_008800_image_result += rain_008800_image_row + '\n'
                    rain_007700_image_result += rain_007700_image_row + '\n'


                self.send_to_virtual_camera(ascii_image_result, rain_00ff00_image_result, rain_00ee00_image_result, rain_00dd00_image_result, rain_00cc00_image_result, rain_00bb00_image_result, rain_00aa00_image_result, rain_009900_image_result, rain_008800_image_result, rain_007700_image_result, drop_of_water_image_ascii_result)
                #print(f"complete : \n{ascii_image_result},\n la pluie : \n{rain_ascii_image_result},\n la goutte d'eau : \n{drop_of_water_image_ascii_result}")
                
            except Exception as e:
                print(f"Erreur dans video_treatment.create_rain_drops: {e}")

    def send_to_virtual_camera(self, ascii_image_result, rain_00ff00_image_result, rain_00ee00_image_result, rain_00dd00_image_result, rain_00cc00_image_result, rain_00bb00_image_result, rain_00aa00_image_result, rain_009900_image_result, rain_008800_image_result, rain_007700_image_result, drop_of_water_image_ascii_result):
        if self.running:
            width, height = 848, 480
            ascii_font_size_width = 16
            wd = sys._MEIPASS if getattr(sys, 'frozen', False) else ''
            font_path = os.path.join(wd, '.', 'mtx.ttf')
            font = ImageFont.truetype(font_path, ascii_font_size_width)
            colors = ['#006600', '#007700', '#008800', '#009900', '#00aa00', '#00bb00', '#00cc00', '#00dd00', '#00ee00', '#00ff00', 'white']
            images = [ascii_image_result, rain_007700_image_result, rain_008800_image_result, rain_009900_image_result,
                    rain_00aa00_image_result, rain_00bb00_image_result, rain_00cc00_image_result, rain_00dd00_image_result,
                    rain_00ee00_image_result, rain_00ff00_image_result, drop_of_water_image_ascii_result]
            try:
                canvas_image = Image.new('RGB', (width, height), 'black')
                draw = ImageDraw.Draw(canvas_image)
                for color, image in zip(colors, images):
                    draw.text((0, 0), image, fill=color, font=font)
                blurred_image = canvas_image.filter(ImageFilter.GaussianBlur(radius=5))
                draw_on_blur = ImageDraw.Draw(blurred_image)
                for color, image in zip(colors, images):
                    draw_on_blur.text((0, 0), image, fill=color, font=font)
                self.virtual_frame = cv2.cvtColor(np.array(blurred_image), cv2.COLOR_RGB2BGR)
                self.matrix_instance.update_virtual_frame(self.virtual_frame)
            
            except Exception as e:
                print(f"Erreur dans video_treatment.send_to_virtual_camera: {e}")
            
    def stop(self):
        VirtualCamera().stop()
        global running
        running = False

    
class Matrix(QMainWindow):
    def __init__(self):
        super().__init__()
        
        self.threads = []
        self.wd = sys._MEIPASS if getattr(sys, 'frozen', False) else ''
        self.running = True
        
        self.font_path = os.path.join(self.wd, '.', 'mtx.ttf')

        self.UIdefine = False
        
        global running, init_global
        running = True
        init_global = True

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
        self.timer_counter = QTimer(self)
        self.image_label = QLabel()
        self.timer_counter.timeout.connect(self.update_counter) 
        self.timer_counter.start(1000)
        
        self.cap = None
        self.timer_capture = QTimer()
        self.timer_capture.timeout.connect(self.capture_frame)
        self.timer_capture.start(33) 

        self.rain_intensity = 0.5
        self.image_updated = ""

        width, height = 848, 480

        self.ascii_font_size_width = 20
        self.ascii_font_size_height = self.ascii_font_size_width * 9 / 16
        
        self.font_path = os.path.join(self.wd, 'mtx.ttf')
        self.canvas_image = Image.new('RGB', (width, height), 'black')
        self.draw = ImageDraw.Draw(self.canvas_image)
        self.font = ImageFont.truetype(self.font_path, self.ascii_font_size_width)
            
        self.virtual_frame = np.zeros((480, 640, 3), dtype=np.uint8)
        
        frame = None
        self.len_array_width = 110
        self.len_array_height = 34
        drop_of_water_image_ascii = [[' ' for _ in range(self.len_array_width)] for _ in range(self.len_array_height)]
        rain_00ff00_image = [[' ' for _ in range(self.len_array_width)] for _ in range(self.len_array_height)]
        rain_00ee00_image = [[' ' for _ in range(self.len_array_width)] for _ in range(self.len_array_height)]
        rain_00dd00_image = [[' ' for _ in range(self.len_array_width)] for _ in range(self.len_array_height)]
        rain_00cc00_image = [[' ' for _ in range(self.len_array_width)] for _ in range(self.len_array_height)]
        rain_00bb00_image = [[' ' for _ in range(self.len_array_width)] for _ in range(self.len_array_height)]
        rain_00aa00_image = [[' ' for _ in range(self.len_array_width)] for _ in range(self.len_array_height)]
        rain_009900_image = [[' ' for _ in range(self.len_array_width)] for _ in range(self.len_array_height)]
        rain_008800_image = [[' ' for _ in range(self.len_array_width)] for _ in range(self.len_array_height)]
        rain_007700_image = [[' ' for _ in range(self.len_array_width)] for _ in range(self.len_array_height)]
        
        
        self.video_treatment = VideoTreatment(frame, rain_00ff00_image, rain_00ee00_image, rain_00dd00_image, rain_00cc00_image, rain_00bb00_image, rain_00aa00_image, rain_009900_image, rain_008800_image, rain_007700_image, drop_of_water_image_ascii, self)
        self.vitual_camera = VirtualCamera()

    def stop_virtual_camera(self):
        if self.virtual_camera is not None:
            self.virtual_camera.stop()
            self.virtual_camera.wait()
            self.virtual_camera = None

    def update_virtual_frame(self, virtual_frame):
        # print("entre dans matrix.update_virtual_frame()\n")
        self.vitual_camera.run(virtual_frame)
        self.update_image_label(virtual_frame)

    def update_image_label(self, virtual_frame):
        self.virtual_frame = virtual_frame    
        # print("entre dans matrix.update_image_label()\n")
        try:
            if not (self.image_label is None) and self.UIdefine:
                image = QImage(self.virtual_frame.data, self.virtual_frame.shape[1], self.virtual_frame.shape[0],
                            QImage.Format.Format_BGR888)

                pixmap = QPixmap.fromImage(image)

                self.image_label.setPixmap(pixmap)    
                self.image_label.update()
            pass
        except Exception as e:
            if message:
                print(f"Erreur dans matrix.update_virtual_frame: {e}")
                message = False
                
    def update_counter(self):
        # print("entre dans matrix.update_counter()\n")
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

            
        pixmap = QPixmap(1280, 720)  # Créez un QPixmap de la taille souhaitée
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

            
        # print(self.counter_txt + self.counter_string)
            
        painter.drawText(pixmap.rect(), Qt.AlignmentFlag.AlignCenter, self.counter_txt + self.counter_string)
        
        painter.end()
        # if random.randint(0, 9) % 3 == 0:
        #     self.image_label.setPixmap(pixmap)
            
    
    def setCameraIndex(self, index):
        # print("entre dans matrix.setCameraIndex()\n")
        # print(f"Caméra sélectionnée : {index}")
        self.camera_index = index
        # print(f"Setting camera with index {self.camera_index}")
        if platform.system() == 'Windows':
            self.cap = cv2.VideoCapture(self.camera_index, cv2.CAP_DSHOW)
        else:
            self.cap = cv2.VideoCapture(self.camera_index)

        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 848)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
        self.cap.set(cv2.CAP_PROP_FPS, 60)
        time.sleep(1)
        
    def stop(self):
        # print("entre dans stop()\n")
        global running
        running = False
        self.video_treatment.stop()
        # self.virtual_camera.stop()
        sys.exit(0)
    
    def closeEvent(self, event: QCloseEvent):
        global running
        # print("entre dans closeEvent()\n")
        running = False
        self.video_treatment.stop()
        # self.virtual_camera.stop()
        sys.exit(0)
        
    def keyPressEvent(self, event: QKeyEvent):
        global running
        # print("entre dans keyPressEvent()\n")
        if event.key() == Qt.Key.Key_Escape:
            running = False
            self.stop()
            self.video_treatment.stop()
            # self.virtual_camera.stop()
            self.closeEvent()
            sys.exit(0)
        else:
            super(Matrix, self).keyPressEvent(event)

    
    def initUI(self):
        if not self.UIdefine:
            # print("entre dans matrix.initUI()\n")
            self.setWindowFlags(self.windowFlags() & ~Qt.WindowType.FramelessWindowHint)
            
            frame = QFrame(self)
            frame.setFrameStyle(QFrame.Shape.NoFrame) 
            
            # Appliquez le layout au widget central
            self.window_icon = QIcon(os.path.join(self.wd, "icon-32.png"))
            self.setWindowIcon(self.window_icon)
            self.setWindowTitle("Matrix")
            self.setGeometry(300, 300, 1280, 720)
            self.setStyleSheet("background-color: black;")
            
            self.central_widget = QWidget()
            self.setCentralWidget(self.central_widget)
            self.central_widget.setStyleSheet("background-color: black;")
            
            self.layout = QVBoxLayout(self.central_widget) 
            
            self.image_label = QLabel()
            self.image_label.setStyleSheet("background-color: black;")
            self.image_label.setScaledContents(True)
            
            pixmap = QPixmap(1280, 720)
            pixmap.fill(QColor(0, 0, 0))
            
            self.image_label.setPixmap(pixmap)
            
            self.layout.addWidget(self.image_label)
            
            self.show()
            self.camera_app = CameraApp(self)
            self.camera_app.close()

            self.UIdefine = True

    # Fonction pour mettre à jour l'image capturée
    def capture_frame(self):
        cap = self.cap
        if not(cap is None):
            # print("entre dans matrix.capture_frame()\n" + str(self.running))
            wd = sys._MEIPASS if getattr(sys, 'frozen', False) else ''
            width, height = 848, 480
            logo = cv2.imread(os.path.join(wd, 'MatrixLogo.png'))
            message = True  
            get_camera = False 
            canvas = np.zeros((height, width, 3), dtype=np.uint8)
            logo_x = int((width - width) / 2)
            logo_y = 0
            canvas[logo_y:logo_y+logo.shape[0], logo_x:logo_x+logo.shape[1]] = logo
            canvas_resized = cv2.resize(canvas, (width, height))
            try:
                if not (cap is None): 
                    capture = cap
                    if not get_camera:
                        # print(f"Dans matrix.capture_frame: La camera est définit")
                        get_camera = True
                    ret, frame = capture.read()
                    if ret:
                        f = frame
                        combined_frame = cv2.addWeighted(f, .5, canvas_resized, 1, 0)
                        
                        frame = combined_frame
                        
                        self.video_treatment.update_camera_frame(frame)
                    
            except Exception as e:
                if message:
                    print(f"Erreur dans matrix.capture_frame: {e}")
                    message = False

if __name__ == "__main__":
    app = QApplication([])
    matrix = Matrix()
    camera_app = CameraApp(matrix)
    matrix.hide()
    camera_app.show()
    app.exec()