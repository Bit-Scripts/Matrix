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

from PIL import Image, ImageDraw, ImageFont

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
running = True
ascii_image = ""

# Définition des caractères à utiliser pour l'ASCII art
characters = ' ú.ù,:öøýü×ÖÅ³·ÈØÙÍÐ±´¶¹º¼Â²ÇËÒÓ¾Ú'
wd = sys._MEIPASS if getattr(sys, 'frozen', False) else ''
logo = cv2.imread(os.path.join(wd, '.', 'MatrixLogo.png'))
size1, size2 = 1280, 301
logo = cv2.resize(logo, (size1, size2))

running = True
camera = 0 # À modifier si ne fonctionne pas
frame_lock = threading.Lock()
ascii_image_lock = threading.Lock()

rain_intensity = 0.5
last_ascii_image, rain_ascii_image = "", ""
columns_to_erase_queue = queue.Queue()
columns_launched_queue = queue.Queue()
image_updated = ""

ascii_font_size_width = 20
ascii_font_size_height = ascii_font_size_width * 9 / 16

width = 1280
height = 720
font_path = os.path.join(wd, 'mtx.ttf')
canvas_image = Image.new('RGB', (width, height), 'black')
draw = ImageDraw.Draw(canvas_image)
font = ImageFont.truetype(font_path, ascii_font_size_width)

stop = threading.Event()
frame, ascii_image, rain_ascii_image, rain_ascii_image_result, drop_of_water_image_ascii, erase_rain_ascii_image = None, "", "", "", "", ""
ascii_column = 0
ascii_row = 0

# initialisation des ascii art
for line in range(0, 106):
    for column in range(0, 106):
        ascii_image += ' '
        rain_ascii_image += ' '
        rain_ascii_image_result += ' '
        drop_of_water_image_ascii += ' '
        erase_rain_ascii_image += ' '
    ascii_image += '\n'
    rain_ascii_image += '\n'
    rain_ascii_image_result += '\n'
    drop_of_water_image_ascii += '\n'
    erase_rain_ascii_image += '\n'

# Fonction pour convertir une intensité en caractère ASCII
def get_character(intensity):
    global characters
    characters = characters
    num_levels = len(characters)
    level = intensity * (num_levels - 1) // 255
    return characters[level] 

# Fonction pour convertir une image en ASCII art
def image_to_ascii(image):
    global ascii_font_size_width, ascii_font_size_height
    if len(image.shape) > 2 and image.shape[2] == 3:
        gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    else:
        gray_image = image
    resized_image = cv2.resize(gray_image, (int(gray_image.shape[1] / (0.88 * ascii_font_size_height)), int(gray_image.shape[0] / (0.88 * ascii_font_size_width))))
    ascii_image = ""
    for i in range(resized_image.shape[0]):
        for j in range(resized_image.shape[1]):
            intensity = resized_image[i][j]
            ascii_image += get_character(intensity)
        ascii_image += "\n"
    return ascii_image

#créer l'effets de pluie
def create_rain_drops(resized_image, drop_positions):
    global running, last_ascii_image, rain_ascii_image
    drop_columns = []  # Liste des colonnes pour les gouttes de pluie
    while running:
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
                columns_launched_queue.put((column, row))
        # Mettre à jour l'affichage de l'ASCII art dans la fenêtre tkinter
        a_image = image_to_ascii(resized_image)
        with ascii_image_lock:
            global ascii_image
            rain_ascii_image = a_image
        if cv2.getWindowProperty("Matrix rain", cv2.WND_PROP_VISIBLE) < 1:
            running = False        
            break
        if cv2.waitKey(1) & 0xFF == ord('q'):
            running = False
            break
        
def create_rain_drop_of_water(drop_of_water_image, columns_launched_queue):
    global running, drop_of_water_image_ascii, rain_ascii_image
    max_rows = {}
    while running:  
        while not columns_launched_queue.empty():
            # Mettre à jour les positions des gouttes de pluie
            column, row = columns_launched_queue.get()
            if column in max_rows:
                max_rows[column] = max(max_rows[column], row)
            else:
                max_rows[column] = row

        # Initialiser drop_of_water_image avec des zéros
        drop_of_water_image = np.zeros_like(drop_of_water_image)

        with ascii_image_lock:
            for column, row in max_rows.items():
                drop_of_water_image[row][column] = 255
            # Mettre à jour l'affichage de l'ASCII art dans la fenêtre tkinter
            drop_of_water_image_ascii = image_to_ascii(drop_of_water_image)
        if cv2.getWindowProperty("Matrix rain", cv2.WND_PROP_VISIBLE) < 1:
            running = False        
            break
        if cv2.waitKey(1) & 0xFF == ord('q'):
            running = False
            break

# Effacer progressivement la pluie
def erase_rain_columns():
    global running, last_ascii_image, columns_launched_queue, erase_rain_ascii_image, erase_rain_image, drop_positions, resized_image
    while running:
        if not columns_to_erase_queue.empty():
            while not columns_to_erase_queue.empty():
                column, row = columns_to_erase_queue.get()
                for row_to_erase in range(0, height):
                    erase_rain_image[row_to_erase][column] = resized_image[row_to_erase][column]
            with ascii_image_lock:
                erase_rain_ascii_image = image_to_ascii(erase_rain_image)
        if cv2.getWindowProperty("Matrix rain", cv2.WND_PROP_VISIBLE) < 1:
            running = False
            break
        if cv2.waitKey(1) & 0xFF == ord('q'):
            running = False
            break

        
# Fonction pour mettre à jour l'image capturée
def capture_frame(ret, f):
    global  frame, running, capture
    while running:
        ret, f = capture.read()
        if ret:
            # Redimensionner l'image capturée pour qu'elle s'adapte aux dimensions du canevas
            resized_frame = cv2.resize(f, (1280, 720))
            # Créer un canevas vide
            canvas = np.zeros((720, 1280, 3), dtype=np.uint8)
            # Calculer les coordonnées pour placer le logo au centre du canevas
            logo_x = int((1280 - size1) / 2)
            logo_y = 0
            # Dessiner le logo sur le canevas
            canvas[logo_y:logo_y+size2, logo_x:logo_x+size1] = logo
            # Combiner le canevas avec l'image capturée redimensionnée
            combined_frame = cv2.addWeighted(resized_frame, .5, canvas, 1, 0)
        with frame_lock:
            frame = combined_frame
        if cv2.getWindowProperty("Matrix rain", cv2.WND_PROP_VISIBLE) < 1:
            running = False        
            break
        if cv2.waitKey(1) & 0xFF == ord('q'):
            running = False
            break

# Fonction pour mettre à jour l'image ASCII
def update_ascii_image():
    global running, ascii_image
    while running and not stop.is_set():
        with frame_lock:
            f = frame
        if f is not None:
            a_image = image_to_ascii(f)
            with ascii_image_lock:
                ascii_image = a_image
                
        time.sleep(0.001)  # Temps d'attente arbitraire
        if cv2.getWindowProperty("Matrix rain", cv2.WND_PROP_VISIBLE) < 1:
            running = False        
            break
        if cv2.waitKey(1) & 0xFF == ord('q'):
            running = False
            break

def image_fusion():
    global running, characters, ascii_image_result, rain_ascii_image, drop_of_water_image_ascii, rain_ascii_image_result, erase_rain_ascii_image
    while running:
        with ascii_image_lock:
            ascii_image_cut = ascii_image.split("\n")
            rain_ascii_image_cut = rain_ascii_image.split("\n")
            drop_of_water_ascii_image_cut = drop_of_water_image_ascii.split("\n")
            erase_rain_ascii_image_cut = erase_rain_ascii_image.split("\n")
            ascii_image_intermediate = []
            rain_ascii_image_intermediate = []
            for i in range(len(ascii_image_cut)):
                ascii_image_cut_line = list(ascii_image_cut[i])
                rain_ascii_image_cut_line = list(rain_ascii_image_cut[i])
                drop_of_water_ascii_image_cut_line = list(drop_of_water_ascii_image_cut[i])
                erase_rain_ascii_image_cut_line = list(erase_rain_ascii_image_cut)
                for j in range(len(rain_ascii_image_cut_line)):
                    if j < len(ascii_image_cut_line) and j < len(rain_ascii_image_cut_line) and j < len(drop_of_water_ascii_image_cut_line) and j < len(erase_rain_ascii_image_cut_line):
                        if (rain_ascii_image_cut_line[j] != ' ' and rain_ascii_image_cut_line[j] in characters):
                            if drop_of_water_ascii_image_cut_line[j] != ' ':
                                ascii_image_cut_line[j] = ' '
                            else:
                                rain_ascii_image_cut_line[j] = ascii_image_cut_line[j]
                                ascii_image_cut_line[j] = ' '
                ascii_image_intermediate.append("".join(ascii_image_cut_line))
                rain_ascii_image_intermediate.append("".join(rain_ascii_image_cut_line))
        ascii_image_result = "\n".join(ascii_image_intermediate)
        rain_ascii_image_result = "\n".join(rain_ascii_image_intermediate)
        time.sleep(0.001)
        if cv2.getWindowProperty("Matrix rain", cv2.WND_PROP_VISIBLE) < 1:
            running = False        
            break
        if cv2.waitKey(1) & 0xFF == ord('q'):
            running = False
            break

def send_to_virtual_camera():
    global running, ascii_image_result, drop_of_water_image_ascii, wd, buffer, image_updated, virtual_frame, ascii_font_size_width, width, height, font_path, canvas_image, draw, font, erase_rain_ascii_image
    while running:
        # Capture the content of the canvas as an image
        canvas_image = Image.new('RGB', (width, height), 'black')
        draw = ImageDraw.Draw(canvas_image)
        font = ImageFont.truetype(font_path, ascii_font_size_width)
        draw.text((0, 0), ascii_image_result, fill='#008800', font=font)
        draw.text((0, 0), rain_ascii_image_result, fill='#00ff00', font=font)
        hex_vars = ['f', 'e', 'd', 'c', 'b', 'a', '9', '8']
        for hex_var in hex_vars:
            draw.text((0, 0), erase_rain_ascii_image, fill='#00'+ hex_var + hex_var + '00', font=font)
            time.sleep(0.01)
        draw.text((0, 0), drop_of_water_image_ascii, fill='white', font=font)
        virtual_frame = cv2.cvtColor(np.array(canvas_image), cv2.COLOR_RGB2BGR)

        # Affichez la miniature dans la fenêtre créée précédemment
        cv2.imshow("Matrix rain", virtual_frame)

        # Vérifiez si la fenêtre a été fermée en utilisant le bouton en croix
        if cv2.getWindowProperty("Matrix rain", cv2.WND_PROP_VISIBLE) < 1:
            running = False
            break

        # Attendez une touche pour quitter
        if cv2.waitKey(1) & 0xFF == ord('q'):
            running = False
            break

    # Fermez la fenêtre et libérez les ressources
    cv2.destroyAllWindows()


def create_virtual_camera():
    global running, virtual_frame
    width = 1280
    height = 720
    with pyvirtualcam.Camera(width, height, 30) as cam:
        while running:
            # Redimensionne l'image pour qu'elle corresponde à la taille de la caméra virtuelle
            resized_frame = cv2.resize(virtual_frame, (width, height))
            cam.send(resized_frame)
            cam.sleep_until_next_frame()
            if cv2.getWindowProperty("Matrix rain", cv2.WND_PROP_VISIBLE) < 1:
                running = False        
                break
            if cv2.waitKey(1) & 0xFF == ord('q'):
                running = False
                break

# Ouverture de la caméra
if platform.system() == 'Windows':
    capture = cv2.VideoCapture(camera,cv2.CAP_DSHOW)
elif platform.system() == 'Linux':
    capture = cv2.VideoCapture(camera)
    
capture.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
capture.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
ret, f = capture.read()

if getattr(sys, 'frozen', False):
    import pyi_splash
    # Fermeture du splash screen
    pyi_splash.update_text('UI Loaded ...')
    pyi_splash.close()

# Variables partagées entre les threads
frame = None
ascii_image = ""

# Affichage de l'image
cv2.namedWindow("Matrix rain", cv2.WINDOW_NORMAL)
cv2.resizeWindow("Matrix rain", 1280, 720)
cv2.imshow("Matrix rain", f)

buffer_thread_event = threading.Event()

# Lancement des threads
capture_thread = threading.Thread(target=capture_frame, args=(ret, f))
ascii_thread = threading.Thread(target=update_ascii_image)
image_fusion_thread = threading.Thread(target=image_fusion)

resized_image = np.zeros((720, 1280), dtype=np.uint8)
drop_of_water_image = resized_image
erase_rain_image = resized_image
virtual_frame = cv2.cvtColor(np.array(resized_image), cv2.COLOR_RGB2BGR)
drop_positions = np.zeros(1280, dtype=int)

create_rain_drops_thread = threading.Thread(target=create_rain_drops, args=(resized_image, drop_positions))
create_rain_drop_of_water_thread = threading.Thread(target=create_rain_drop_of_water, args=(drop_of_water_image, columns_launched_queue))
erase_rain_columns_thread = threading.Thread(target=erase_rain_columns, args=())

running = True
image_updated = False
buffer = None

send_virtual_camera_thread = threading.Thread(target=send_to_virtual_camera)
create_virtual_camera_thread = threading.Thread(target=create_virtual_camera)

threads = [capture_thread, ascii_thread, image_fusion_thread, create_rain_drops_thread, create_rain_drop_of_water_thread, erase_rain_columns_thread, send_virtual_camera_thread, create_virtual_camera_thread]

for thread in threads:
    thread.daemon = True
    thread.start()
    
# Boucle principale
while True:   
    # Attendez un court délai
    time.sleep(0.01)
        
    # Boucle principale de l'application
    if cv2.getWindowProperty("Matrix rain", cv2.WND_PROP_VISIBLE) < 1:
        running = False        
        break
    if cv2.waitKey(1) & 0xFF == ord('q'):
        running = False
        break
    
# Libération des ressources
capture.release()
cv2.destroyAllWindows()
# Arrêt propre du programme
running = False
stop.set()

for thread in threads:
    thread.join(timeout=1.0)
    time.sleep(1.001)

sys.exit(0)