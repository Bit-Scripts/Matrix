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
if sys.platform == 'win32' or sys.platform == 'darwin': 
    import qdarktheme

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
        
        if sys.platform.startswith("linux"):
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
        try:
            from AVFoundation import AVCaptureDevice
            
        except ImportError:
            self.label.setText("Installez pyobjc avec 'pip install pyobjc'")
            return {}

        camera_indices = []
        camera_names = []
        
        devices = AVCaptureDevice.devicesWithMediaType_('vide')
        for device_index, device_name in enumerate(devices):
            camera_name = device_name.localizedName().cString()
            camera_names.append(camera_name)
            camera_indices.append(device_index)

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
        if sys.platform.startswith("linux"):
            self.video_device = self.find_virtual_cameras_on_linux()
        self.virtual_frame = virtual_frame
        if self.running:
            # print("entre dans virtual_camera.create_virtual_camera()\n")
            if sys.platform.startswith("linux"):
                with pyvirtualcam.Camera(width=1080, height=720, fps=30, device=f"{self.video_device}") as cam:
                    try:
                        virtual_frame = self.virtual_frame
                        virtual_frame_resized = self.resize_image(virtual_frame, 1080, 720)
                        cam.send(virtual_frame_resized)
                        cam.sleep_until_next_frame()
                    except Exception as e:
                        print(f"Erreur dans virtual_camera.create_virtual_camera: {e}")
                        pass
            elif sys.platform.startswith("win32"): 
                with pyvirtualcam.Camera(width=1080, height=720, fps=30, backend ='unitycapture') as cam:
                    try:
                        virtual_frame = self.virtual_frame
                        virtual_frame_resized = self.resize_image(virtual_frame, 1080, 720)
                        cam.send(virtual_frame_resized)
                        cam.sleep_until_next_frame()
                    except Exception as e:
                        print(f"Erreur dans virtual_camera.create_virtual_camera: {e}")
                        pass
            elif sys.platform.startswith("darwin"): 
                with pyvirtualcam.Camera(width=1080, height=720, fps=30) as cam:
                    try:
                        virtual_frame = self.virtual_frame
                        virtual_frame_resized = self.resize_image(virtual_frame, 1080, 720)
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
    def __init__(self, frame, rain_00ff00_image, rain_00bb00_image, rain_008800_image, rain_006600_image, drop_of_water_image_ascii, matrix_instance):
        self.matrix_instance = matrix_instance
        self.len_array_width = 147
        self.len_array_height = 45
        super().__init__()
        self.frame = frame
        self.rain_00ff00_image = rain_00ff00_image
        self.rain_00bb00_image = rain_00bb00_image
        self.rain_008800_image = rain_008800_image
        self.rain_006600_image = rain_006600_image
        self.drop_of_water_image_ascii = drop_of_water_image_ascii
        global running
        running = True
        self.running = running
        
        self.characters = ' úù_.-,`;:ö+/\'=Åa~^³xwvu%sc*><onø÷"ÖÈÊe|ÄrÃ±iÉz\m)(¹l¡»·ãI}{][ýÙÐ§1jÔÍ¾ÂætL!ÌÁÀº¸´Ëy?Òþ¶qg¨p2ÑÏ¼²TfCJäÝ7Óü×©3YØÎ°Õ½«5Zóõ¿Ç£ôíSÆµ6¬¢kdûbîàªF4òXhÚ¯9êP$#GáßEÛA¤VðïU&éOÞåKD®8âHÜìRBëQW¦0@ñMèNç¥'
        # self.characters = " úù_.-,`;:ö+/\'=Åa~1jÔÍ¾ÂætL!ÌÁÀº¸´ËSÆµ6¬¢kdûbîàªF4òXhÚ¯9êP$#GáßE&éOÞåKD®8âHÜìRBëQW¦0@ñMèNç¥"
        self.ascii_cache = {}
        
        self._char_lut = np.array(list(self.characters), dtype='<U1')
        
        self.w = self.len_array_width
        self.h = self.len_array_height

        # 2 gouttes max par colonne comme toi, mais stockées proprement
        self.drop_y = np.full((2, self.w), -1, dtype=np.int16)

        # vitesse par colonne (un peu de vie)
        self.drop_speed = np.random.randint(1, 3, size=(2, self.w), dtype=np.int16)

        # pour une "densité" réglable
        self.spawn_prob = 0.08  # 8% par frame environ, ajuste

        # cache utile
        self.space = " "
        
        # --- Rendu (créé une seule fois = beaucoup plus veloce) ---
        # Calcul de la largeur réelle basée sur la police Matrix.ttf
        self.ascii_font_size_width = 9
        
        wd = sys._MEIPASS if getattr(sys, 'frozen', False) else ''
        font_path = os.path.join(wd, 'mtx.ttf')
        self.font = ImageFont.truetype(font_path, self.ascii_font_size_width)
        
        # MESURE EXACTE : Créer une ligne de test avec le bon nombre de caractères
        test_line = "M" * self.len_array_width  # 147 caractères
        
        # Mesurer la largeur réelle de cette ligne avec la police
        # Créer un canvas temporaire pour mesurer
        temp_img = Image.new('RGB', (1, 1))
        temp_draw = ImageDraw.Draw(temp_img)
        bbox = temp_draw.textbbox((0, 0), test_line, font=self.font)
        measured_width = bbox[2] - bbox[0]
        
        # Utiliser la largeur mesurée exacte
        self.width = measured_width
        self.height = 480

        self.canvas = Image.new('RGB', (self.width, self.height), '#001100')
        self.draw = ImageDraw.Draw(self.canvas)
        
        # Créer le buffer avec les bonnes dimensions
        self.virtual_frame = np.zeros((self.height, self.width, 3), dtype=np.uint8)

        
    def update_camera_frame(self, camera_frame):
        self.update_ascii_image(camera_frame)        

    # Fonction pour convertir une image en ASCII art
    def image_to_ascii(self, image):
        if self.running:
            try:
                image = cv2.resize(image, (self.len_array_width, self.len_array_height))
                rgb_sum = np.sum(image, axis=2)
                indices = np.clip(np.floor_divide(rgb_sum, 765 / len(self.characters)), 0, len(self.characters) - 1).astype(int)
                ascii_art = []
                for row in indices:
                    ascii_row = []
                    for index in row:
                        if index in self.ascii_cache:
                            char = self.ascii_cache[index]
                        else:
                            char = self.characters[index]
                            self.ascii_cache[index] = char
                        ascii_row.append(char)
                    ascii_art.append(ascii_row)
                return ascii_art
                
            except Exception as e:
                print(f"Erreur dans video_treatment.image_to_ascii: {e}")

    def _update_drops(self):
        # spawn: seulement sur la goutte 0 (la 2e sert de "relai" plus bas)
        spawn_mask = (self.drop_y[0] < 0) & (np.random.random(self.w) < self.spawn_prob)
        self.drop_y[0, spawn_mask] = 0
        self.drop_speed[0, spawn_mask] = np.random.randint(1, 3, size=np.count_nonzero(spawn_mask))

        # avance les gouttes existantes
        for i in (0, 1):
            active = self.drop_y[i] >= 0
            self.drop_y[i, active] += self.drop_speed[i, active]

            # si la première arrive vers le bas, on déclenche la seconde
            trigger = (i == 0) & (self.drop_y[0] == (self.h - 12))
            if np.any(trigger):
                self.drop_y[1, trigger] = 0
                self.drop_speed[1, trigger] = np.random.randint(1, 3, size=np.count_nonzero(trigger))

            # reset quand c'est sorti
            out = self.drop_y[i] >= self.h
            self.drop_y[i, out] = -1

    def _build_layers(self, cam_ascii):
        # fond: tout l'ascii camera
        bg_rows = ["".join(row) for row in cam_ascii]
        bg_text = "\n".join(bg_rows)

        # couches vides pour head / trail
        head = [[self.space] * self.w for _ in range(self.h)]
        trail = [[self.space] * self.w for _ in range(self.h)]

        xs = np.arange(self.w, dtype=np.int16)

        for i in (0, 1):
            ys = self.drop_y[i]
            active = ys >= 0
            if not np.any(active):
                continue

            x = xs[active]
            y = ys[active]

            # tête
            for xi, yi in zip(x.tolist(), y.tolist()):
                if 0 <= yi < self.h:
                    head[yi][xi] = cam_ascii[yi][xi]

            # traînée: quelques pixels au-dessus (plus douce)
            for dt in (1, 3, 6):
                yy = y - dt
                for xi, yi in zip(x.tolist(), yy.tolist()):
                    if 0 <= yi < self.h:
                        trail[yi][xi] = cam_ascii[yi][xi]

        head_text = "\n".join("".join(r) for r in head)
        trail_text = "\n".join("".join(r) for r in trail)

        return bg_text, head_text, trail_text

    # Fonction pour mettre à jour l'image ASCII
    def update_ascii_image(self, frame):
        if not self.running:
            return

        try:
            # base camera ascii (H x W) en liste de listes de caractères
            cam_ascii = self.image_to_ascii(frame)

            # update positions des gouttes
            self._update_drops()

            # construit 2 couches: fond + gouttes + traînée
            bg_text, head_text, trail_text = self._build_layers(cam_ascii)

            # rend 3 couches (fond sombre, traînée, tête brillante)
            self.send_to_virtual_camera(bg_text, head_text, trail_text)

        except Exception as e:
            print(f"Erreur update_ascii_image: {e}")

    def image_to_ascii_text(self, image_bgr):
        # Reprend ton algo: resize + indices -> caractères
        img = cv2.resize(image_bgr, (self.len_array_width, self.len_array_height),
                interpolation=cv2.INTER_AREA)

        # luminance normalisée 0..1
        lum = np.sum(img, axis=2).astype(np.float32) / 765.0

        # contraste / éclaircissement
        gamma = 0.6   # 0.5 = très clair, 0.7 = plus doux
        lum = np.power(lum, gamma)

        idx = (lum * (len(self.characters) - 1)).astype(np.int32)
        idx = np.clip(idx, 0, len(self.characters) - 1)

        chars = self._char_lut[idx]
        return [row.tolist() for row in chars]

    def send_to_virtual_camera(self, bg_text, head_text, trail_text):
        if not self.running:
            return

        try:
            self.draw.rectangle((0, 0, self.width, self.height), fill='#000000')

            self.draw.text((0, 0), bg_text,   fill='#00aa00', font=self.font)
            self.draw.text((0, 0), trail_text, fill='#00dd00', font=self.font)
            self.draw.text((0, 0), head_text,  fill='#66ff66', font=self.font)

            frame_bgr = cv2.cvtColor(np.array(self.canvas), cv2.COLOR_RGB2BGR)
            # frame_bgr = cv2.GaussianBlur(frame_bgr, (3, 3), 0)
            frame_bgr = cv2.GaussianBlur(frame_bgr, (1, 1), 0) 

            self.matrix_instance.update_virtual_frame(frame_bgr)

        except Exception as e:
            print(f"Erreur send_to_virtual_camera: {e}")


                
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
            
        self.cap = None
        self.timer_capture = QTimer()
        self.timer_capture.timeout.connect(self.capture_frame)
        self.timer_capture.start(33) 

        self.rain_intensity = 0.5
        self.image_updated = ""

        width, height = 848, 480

        self.ascii_font_size_width = 12
        self.ascii_font_size_height = self.ascii_font_size_width * 9 / 16
        
        self.font_path = os.path.join(self.wd, 'mtx.ttf')
        self.canvas_image = Image.new('RGB', (width, height), 'black')
        self.draw = ImageDraw.Draw(self.canvas_image)
        self.font = ImageFont.truetype(self.font_path, self.ascii_font_size_width)
            
        self.virtual_frame = np.zeros((480, 848, 3), dtype=np.uint8)
        
        frame = None
        self.len_array_width = 260
        self.len_array_height = 70
        drop_of_water_image_ascii = [[' ' for _ in range(self.len_array_width)] for _ in range(self.len_array_height)]
        rain_00ff00_image = [[' ' for _ in range(self.len_array_width)] for _ in range(self.len_array_height)]
        rain_00bb00_image = [[' ' for _ in range(self.len_array_width)] for _ in range(self.len_array_height)]
        rain_008800_image = [[' ' for _ in range(self.len_array_width)] for _ in range(self.len_array_height)]
        rain_006600_image = [[' ' for _ in range(self.len_array_width)] for _ in range(self.len_array_height)]
        
        self.video_treatment = VideoTreatment(frame, rain_00ff00_image, rain_00bb00_image, rain_008800_image, rain_006600_image, drop_of_water_image_ascii, self)
        self.vitual_camera = VirtualCamera()
        
        # Récupérer les dimensions réelles calculées par VideoTreatment
        self.actual_width = self.video_treatment.width
        self.actual_height = self.video_treatment.height

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
        self.cap.set(cv2.CAP_PROP_FPS, 30)
        
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
            self.setStyleSheet("background-color: black;")
            
            frame = QFrame(self)
            frame.setFrameStyle(QFrame.Shape.NoFrame) 
            
            # Appliquez le layout au widget central
            self.window_icon = QIcon(os.path.join(self.wd, "icon-32.png"))
            self.setWindowIcon(self.window_icon)
            self.setWindowTitle("Matrix")
            # CORRECTION: Utiliser les dimensions réelles calculées par VideoTreatment
            # Utiliser setFixedSize pour éviter le redimensionnement
            self.setFixedSize(self.actual_width, self.actual_height)
            self.setStyleSheet("background-color: black;")
            
            self.central_widget = QWidget()
            self.setCentralWidget(self.central_widget)
            self.central_widget.setStyleSheet("background-color: black;")
            
            self.layout = QVBoxLayout(self.central_widget)
            # Supprimer les marges du layout pour un ajustement parfait
            self.layout.setContentsMargins(0, 0, 0, 0)
            self.layout.setSpacing(0)
            
            self.image_label = QLabel()
            self.image_label.setStyleSheet("background-color: black;")
            self.image_label.setScaledContents(True)
            # Forcer les dimensions exactes du label basées sur le rendu réel
            self.image_label.setFixedSize(self.actual_width, self.actual_height)
            
            # CORRECTION: Créer le pixmap avec les bonnes dimensions
            pixmap = QPixmap(self.actual_width, self.actual_height)
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
    if sys.platform == 'win32': 
        qdarktheme.setup_theme("auto", custom_colors={"primary": "#00B294"})
    if sys.platform == 'darwin':
        qdarktheme.setup_theme("auto")
    matrix = Matrix()
    camera_app = CameraApp(matrix)
    matrix.hide()
    camera_app.show()
    app.exec()