import cv2
import time
import sys
import os
import re
import platform

from PyQt6.QtWidgets import QLabel, QVBoxLayout, QPushButton, QComboBox, QApplication, QWidget
from PyQt6.QtCore import pyqtSignal, QTimer, Qt, pyqtSlot
from PyQt6.QtGui import QIcon, QCloseEvent, QImage, QPixmap

class CameraApp(QWidget):
    def __init__(self):
        super().__init__()

        self.init_ui()
        self.cap = None
        self.timer = QTimer()
        
        self.setWindowTitle("CameraSelector")
        self.wd = sys._MEIPASS if getattr(sys, 'frozen', False) else ''
        self.setWindowIcon(QIcon(os.path.join(self.wd, "icon-32.png")))

    def init_ui(self):
        self.layout = QVBoxLayout()

        self.camera_selector = QComboBox()
        self.populate_camera_selector()
        self.camera_selector.currentIndexChanged.connect(self.select_camera)

        self.label = QLabel("Sélectionnez une caméra pour commencer")
        
        # Créez le bouton et connectez-le à la méthode open_matrix_window
        self.open_matrix_button = QPushButton("Ouvrir Matrix")
        self.open_matrix_button.clicked.connect(self.open_matrix_window)

        # Ajoutez le bouton à votre interface utilisateur
        self.layout.addWidget(self.camera_selector)
        self.layout.addWidget(self.label)
        self.layout.addWidget(self.open_matrix_button)

        self.setLayout(self.layout)

    def populate_camera_selector(self):
        camera_names, camera_indices = self.get_available_cameras()
        for name, index in zip(camera_names, camera_indices):
            self.camera_selector.addItem(f"{name} (Index: {index})", index)

    def get_available_cameras(self):
        system = platform.system()
        if system == "Windows":
            return self.get_cameras_windows()
        elif system == "Linux":
            return self.get_cameras_linux()
        elif system == "Darwin":  # macOS
            return self.get_cameras_mac()
        else:
            raise NotImplementedError(f"Unsupported platform: {system}")

    def get_cameras_mac(self):
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

        return camera_indices, camera_names

    def get_cameras_linux(self):
        try:
            from v4l2py import Device
        except ImportError:
            print("Installez v4l2py avec 'pip install v4l2py'")
            return {}

        devices = []
        frame = None
        for i in range(10):  # Check the first 10 devices
            try:
                with Device.from_id(i) as cam:
                    frame = next(iter(cam), None)
                    if frame is not None:
                        devices.append(i)
            except Exception as e:
                continue
            
        from v4l2py.device import Device
        
        camera_names = []
        camera_indices = []
        
        for index in devices:
            try:
                cam = Device.from_id(index)
                cam.open()
                camera_name = cam.info.card
                if "infrared" in camera_name.lower() or "ir" in camera_name.lower():
                    continue  # Ignore the infrared camera
                camera_names.append(camera_name)
                camera_indices.append(index)
                cam.close()
            except Exception as e:
                continue

        return camera_names, camera_indices

    @pyqtSlot(int)
    def select_camera(self, index):
        camera_index = self.camera_selector.itemData(index)
        if self.cap is not None:
            self.cap.release()

        self.cap = cv2.VideoCapture(camera_index)
        self.timer.timeout.connect(self.update_frame)
        self.timer.start(30)

    def update_frame(self):
        ret, frame = self.cap.read()
        if ret:
            cv2.imshow("Caméra", frame)
            cv2.waitKey(1)
        else:
            print("Erreur: Impossible de lire la caméra")

    def closeEvent(self, event):
        if self.cap is not None:
            self.cap.release()
        cv2.destroyAllWindows()

    def open_matrix_window(self):
        self.matrix_window = Matrix()
        self.matrix_window.show()

if __name__ == "__main__":
    app = QApplication(sys.argv)
    camera_app = CameraApp()
    camera_app.show()
    sys.exit(app.exec())