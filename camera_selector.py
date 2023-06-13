import cv2
import platform

from PyQt6.QtWidgets import QLabel, QVBoxLayout, QWidget, QPushButton, QComboBox
from PyQt6.QtCore import pyqtSignal

class CameraSelector(QWidget):
    def __init__(self):
        super().__init__()

        self.cap = None

        self.init_ui()
        
        # Connect the on_camera_selected method to the camera_selected signal
        self.camera_selected = pyqtSignal(int)
        
    def init_ui(self):
        layout = QVBoxLayout()

        label = QLabel("Choisissez une caméra:")
        layout.addWidget(label)

        self.combo = QComboBox()
        camera_list = self.get_camera_indexes()
        self.combo.addItems(camera_list)
        layout.addWidget(self.combo)

        button = QPushButton("Ouvrir la caméra")
        button.clicked.connect(self.open_camera)
        layout.addWidget(button)

        self.setLayout(layout)
        self.setWindowTitle("Sélection de la caméra")

    def open_camera(self):
        camera_index = int(self.combo.currentText())

        self.cap = cv2.VideoCapture(camera_index)

        if not self.cap.isOpened():
            print("Erreur lors de l'ouverture de la caméra.")
        else:
            ret, frame = self.cap.read()

            if ret:
                cv2.imshow('Image', frame)
                cv2.waitKey(0)
                cv2.destroyAllWindows()
            else:
                print("Erreur lors de la capture de l'image.")

            self.cap.release()

    def get_camera_indexes(self, max_cameras=10):
        indexes = []
        for i in range(max_cameras):
            cap = cv2.VideoCapture(i)
            if cap.isOpened():
                indexes.append(str(i))
                cap.release()
        return indexes
    
    def on_camera_selected(self):
        index = self.camera_list.currentIndex()
        if index >= 0:
            self.capture = cv2.VideoCapture(index)
            self.combo.camera_selected.emit(self.cap)