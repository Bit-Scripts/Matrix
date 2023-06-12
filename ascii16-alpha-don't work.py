import sys
import os
import platform
import time
import threading
import queue
import random
import curses

import cv2
import numpy as np
import pyvirtualcam

from PIL import Image, ImageDraw, ImageFont


class Matrix:
    def __init__(self):
        curses.initscr()
        
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
        
        # dimention camera et affichage
        self.width = 1280
        self.height = 720
        
        self.camera = 0
        # Ouverture de la caméra
        if platform.system() == 'Windows':
            self.capture = cv2.VideoCapture(self.camera,cv2.CAP_DSHOW)
        elif platform.system() == 'Linux':
            self.capture = cv2.VideoCapture(self.camera)
            
        self.capture.set(cv2.CAP_PROP_FRAME_WIDTH, self.width)
        self.capture.set(cv2.CAP_PROP_FRAME_HEIGHT, self.height)
        
        # Lecture de la frame
        ret, frame = self.capture.read()
        
        # Définition des caractères à utiliser pour l'ASCII art
        self.characters = ' ú.ù,:öøýü×ÖÅ³·ÈØÙÍÐ±´¶¹º¼Â²ÇËÒÓ¾Ú'
        self.wd = sys._MEIPASS if getattr(sys, 'frozen', False) else ''
        self.logo = cv2.imread(os.path.join(self.wd, '.', 'MatrixLogo.png'))
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

        # Affichage de l'image
        cv2.namedWindow("Matrix rain", cv2.WINDOW_NORMAL)
        cv2.resizeWindow("Matrix rain", 1280, 720)
        cv2.imshow("Matrix rain", frame)

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
        capture_thread = threading.Thread(target=self.capture_frame)
        ascii_thread = threading.Thread(target=self.update_ascii_image)
        image_fusion_thread = threading.Thread(target=self.image_fusion)

        resized_image = np.zeros((720, 1280), dtype=np.uint8)
        self.drop_of_water_image = resized_image
        self.erase_rain_image = resized_image
        self.virtual_frame = cv2.cvtColor(np.array(resized_image), cv2.COLOR_RGB2BGR)
        self.drop_positions = np.zeros(1280, dtype=int)

        create_rain_drops_thread = threading.Thread(target=self.create_rain_drops)
        create_rain_drop_of_water_thread = threading.Thread(target=self.create_rain_drop_of_water)
        erase_rain_columns_thread = threading.Thread(target=self.erase_rain_columns)

        self.image_updated = False
        self.buffer = None

        send_virtual_camera_thread = threading.Thread(target=self.send_to_virtual_camera)
        create_virtual_camera_thread = threading.Thread(target=self.create_virtual_camera)

        self.threads = [capture_thread, 
                        ascii_thread, 
                        image_fusion_thread, 
                        create_rain_drops_thread, 
                        create_rain_drop_of_water_thread, 
                        erase_rain_columns_thread, 
                        send_virtual_camera_thread, 
                        create_virtual_camera_thread
                        ]

        for thread in self.threads:
            thread.daemon = True
            thread.start()
    
    def stop(self):
        # Libération des ressources
        self.capture.release()
        cv2.destroyAllWindows()
        # Arrêt propre du programme
        self.running = False
        curses.endwin()
        for thread in self.threads:
            thread.join(timeout=1.0)
            time.sleep(1.001)
            sys.exit(0)


    def run(self):   
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
            if cv2.getWindowProperty("Matrix rain", cv2.WND_PROP_VISIBLE) < 1:
                self.running = False        
                break
            if cv2.waitKey(1) & 0xFF == ord('q'):
                self.running = False
                break
        self.capture.release()
        cv2.destroyAllWindows()

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
    def create_rain_drops(self):
        resized_image = np.zeros((720, 1280), dtype=np.uint8)
        columns_to_erase_queue = self.columns_to_erase_queue
        drop_columns = []
        drop_positions = np.zeros(1280, dtype=int)
        while self.running:
            # Générer une nouvelle goutte de pluie
            if len(drop_columns) < 80:
                column = random.randint(0, resized_image.shape[1] - 1)  # Choix aléatoire de la colonne
                drop_columns.append(column)
                drop_positions[column] = 0  # Initialiser la position de la goutte à la ligne supérieure
            # Mettre à jour les positions des gouttes de pluie
            for column in drop_columns:
                row = drop_positions[column]
                # Réinitialiser la colonne à zéro pour effacer la goutte précédente
                if row >= resized_image.shape[0] - 1:
                    drop_columns.remove(column)
                    columns_to_erase_queue.put((column, row)) # Ajouter la colonne à effacer à la liste
                    for row_to_erase in range(0, drop_positions[column]):
                        resized_image[row_to_erase][column] = 0
                else:
                    row += 1  # Descendre la goutte d'une ligne
                    drop_positions[column] = row  # Mettre à jour la position de la goutte
                    # Mettre à jour l'image avec la goutte de pluie
                    resized_image[row][column] = 255 # Intensité maximale
                    # Ajouter uniquement les colonnes dans la queue
                    self.columns_launched_queue.put((column, row))
            # Mettre à jour l'affichage de l'ASCII art dans la fenêtre tkinter
            self.resized_image = resized_image
            a_image = self.image_to_ascii(resized_image)
            with self.ascii_image_lock:
                self.rain_ascii_image = a_image
            if cv2.getWindowProperty("Matrix rain", cv2.WND_PROP_VISIBLE) < 1:
                self.running = False        
                break
            if cv2.waitKey(1) & 0xFF == ord('q'):
                self.running 
            
    def create_rain_drop_of_water(self):
        max_rows = {}
        while self.running:  
            while not self.columns_launched_queue.empty():
                # Mettre à jour les positions des gouttes de pluie
                column, row = self.columns_launched_queue.get()
                if column in max_rows:
                    max_rows[column] = max(max_rows[column], row)
                else:
                    max_rows[column] = row

            # Initialiser drop_of_water_image avec des zéros
            drop_of_water_image = np.zeros_like(self.resized_image)

            with self.ascii_image_lock:
                for column, row in max_rows.items():
                    drop_of_water_image[row][column] = 255
                # Mettre à jour l'affichage de l'ASCII art dans la fenêtre tkinter
                self.drop_of_water_image_ascii = self.image_to_ascii(drop_of_water_image)
            if cv2.getWindowProperty("Matrix rain", cv2.WND_PROP_VISIBLE) < 1:
                self.running = False        
                break
            if cv2.waitKey(1) & 0xFF == ord('q'):
                self.running = False
                break

    # Effacer progressivement la pluie
    def erase_rain_columns(self):
        erase_rain_image = np.zeros((720, 1280), dtype=np.uint8)
        while self.running:
            if not self.columns_to_erase_queue.empty():
                while not self.columns_to_erase_queue.empty():
                    column, row = self.columns_to_erase_queue.get()
                    for row_to_erase in range(0, self.height):
                        erase_rain_image[row_to_erase][column] = self.resized_image[row_to_erase][column]
                with self.ascii_image_lock:
                    self.erase_rain_ascii_image = self.image_to_ascii(erase_rain_image)
            if cv2.getWindowProperty("Matrix rain", cv2.WND_PROP_VISIBLE) < 1:
                self.running = False
                break
            if cv2.waitKey(1) & 0xFF == ord('q'):
                self.running = False
                break

    # Fonction pour mettre à jour l'image capturée
    def capture_frame(self):
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
            if cv2.getWindowProperty("Matrix rain", cv2.WND_PROP_VISIBLE) < 1:
                self.running = False        
                break
            if cv2.waitKey(1) & 0xFF == ord('q'):
                self.running = False
                break

    # Fonction pour mettre à jour l'image ASCII
    def update_ascii_image(self):
        while self.running:
            with self.frame_lock:
                f = self.frame
            if f is not None:
                self.y_image = self.image_to_ascii(f)
                with self.ascii_image_lock:
                    self.ascii_image = self.y_image
            time.sleep(0.001)  # Temps d'attente arbitraire
            if cv2.getWindowProperty("Matrix rain", cv2.WND_PROP_VISIBLE) < 1:
                self.running = False        
                break
            if cv2.waitKey(1) & 0xFF == ord('q'):
                self.running = False
                break

    def image_fusion(self):
        while self.running:
            with self.ascii_image_lock:
                ascii_image_cut = self.ascii_image.split("\n")
                rain_ascii_image_cut = self.rain_ascii_image.split("\n")
                drop_of_water_ascii_image_cut = self.drop_of_water_image_ascii.split("\n")
                erase_rain_ascii_image_cut = self.erase_rain_ascii_image.split("\n")
                ascii_image_intermediate = []
                rain_ascii_image_intermediate = []
                for i in range(len(ascii_image_cut)):
                    ascii_image_cut_line = list(ascii_image_cut[i])
                    rain_ascii_image_cut_line = list(rain_ascii_image_cut[i])
                    drop_of_water_ascii_image_cut_line = list(drop_of_water_ascii_image_cut[i])
                    erase_rain_ascii_image_cut_line = list(erase_rain_ascii_image_cut)
                    for j in range(len(rain_ascii_image_cut_line)):
                        if j < len(ascii_image_cut_line) and j < len(rain_ascii_image_cut_line) and j < len(drop_of_water_ascii_image_cut_line) and j < len(erase_rain_ascii_image_cut_line):
                            if (rain_ascii_image_cut_line[j] != ' ' and rain_ascii_image_cut_line[j] in self.characters):
                                if drop_of_water_ascii_image_cut_line[j] != ' ':
                                    ascii_image_cut_line[j] = ' '
                                else:
                                    rain_ascii_image_cut_line[j] = self.ascii_image_cut_line[j]
                                    ascii_image_cut_line[j] = ' '
                    ascii_image_intermediate.append("".join(ascii_image_cut_line))
                    rain_ascii_image_intermediate.append("".join(rain_ascii_image_cut_line))
            self.ascii_image_result = "\n".join(ascii_image_intermediate)
            self.rain_ascii_image_result = "\n".join(rain_ascii_image_intermediate)
            time.sleep(0.001)
            if cv2.getWindowProperty("Matrix rain", cv2.WND_PROP_VISIBLE) < 1:
                self.running = False        
                break
            if cv2.waitKey(1) & 0xFF == ord('q'):
                self.running = False
                break

    def send_to_virtual_camera(self):
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

            # Vérifiez si la fenêtre a été fermée en utilisant le bouton en croix
            if cv2.getWindowProperty("Matrix rain", cv2.WND_PROP_VISIBLE) < 1:
                self.running = False
                break

            # Attendez une touche pour quitter
            if cv2.waitKey(1) & 0xFF == ord('q'):
                self.running = False
                break

        # Fermez la fenêtre et libérez les ressources
        cv2.destroyAllWindows()

    def create_virtual_camera(self):
        with pyvirtualcam.Camera(self.width, self.height, 30) as cam:
            while self.running:
                # Redimensionne l'image pour qu'elle corresponde à la taille de la caméra virtuelle
                cam.send(self.virtual_frame)
                cam.sleep_until_next_frame()
                if cv2.getWindowProperty("Matrix rain", cv2.WND_PROP_VISIBLE) < 1:
                    self.running = False        
                    break
                if cv2.waitKey(1) & 0xFF == ord('q'):
                    self.running = False
                    break

if __name__ == "__main__":
    matrix = Matrix()
    thread_run = matrix.run()