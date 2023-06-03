import sys
import numpy as np
import cv2
import tkinter as tk
from PIL import Image, ImageFont, ImageDraw
import threading
import os
import platform
import random
import time
import pyvirtualcam
from io import BytesIO
import queue

# Définition des caractères à utiliser pour l'ASCII art
characters = np.asarray(list(' .,:;irsXA253hMHGS#9B&@'))
characters_str = ' .,:;irsXA253hMHGS#9B&@'  # Caractères ASCII, du plus foncé au plus clair
#characters_str = ' .:-=+*#%@'

# Boolean pour tout arrêter
running = True

# Camera 0, 1, ou 2 : 0 par défaut
camera = 0 # à Modifier si ne fonctionne pas

# Chemin des ressources
if getattr(sys, 'frozen', False):
    wd = sys._MEIPASS
else:
    wd = '' 

# Logo et sa modification de sa taile
logo = cv2.imread(os.path.join(wd,'.','MatrixLogo.png'))
size1 = 1280
size2 = 301
logo = cv2.resize(logo, (size1, size2))

# Phénomène de pluie
global rain_intensity
rain_intensity = 0.5  # Intensité initiale de la pluie
global last_ascii_image
last_ascii_image = ""  # Stocke l'image ASCII précédente

rain_ascii_image = ""

rain_ascii_image_cut_line = ""
ascii_image_result = ""  

columns_to_erase_queue = queue.Queue()

#add id to app to show icon in window and taskbar
#myappid = 'bit-scripts.matrix.cameraascii.twelve' # arbitrary string
#ctypes.windll.shell32.SetCurrentProcessExplicitAppUserModelID(myappid)

# Variable partagée pour signaler à un thread qu'il doit s'arrêter
stop = threading.Event()

# Fonction pour convertir une intensité en caractère ASCII
def get_character(intensity):
    global characters_str
    characters = characters_str
    #characters = ' .,:;irsXA253hMHGS#9B&@'  # Caractères ASCII, du plus foncé au plus clair
    #characters = ' .:-=+*#%@'
    num_levels = len(characters)
    level = intensity * (num_levels - 1) // 255
    return characters[level]

# Fonction pour convertir une image en ASCII art
def image_to_ascii(image):
    if len(image.shape) > 2 and image.shape[2] == 3:
        gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    else:
        gray_image = image

    resized_image = cv2.resize(gray_image, (int(gray_image.shape[1] / 8), int(gray_image.shape[0] / 16)))
    ascii_image = ""

    for i in range(resized_image.shape[0]):
        for j in range(resized_image.shape[1]):
            intensity = resized_image[i][j]
            ascii_image += get_character(intensity)
        ascii_image += "\n"

    return ascii_image

# Fonction pour simuler la chute des gouttes de pluie
def simulate_rain(resized_image, drop_positions):
    global running, last_ascii_image, rain_ascii_image
    drop_columns = []  # Liste des colonnes pour les gouttes de pluie
    drop_speed = 0.1  # Vitesse de descente des gouttes de pluie (en secondes par ligne)
    columns_to_erase = []
    
    while running:
        # Générer une nouvelle goutte de pluie
        if len(drop_columns) < 50:
            column = random.randint(0, resized_image.shape[1] - 1)  # Choix aléatoire de la colonne
            drop_columns.append(column)
            drop_positions[column] = 0  # Initialiser la position de la goutte à la ligne supérieure

        # Mettre à jour les positions des gouttes de pluie
        for column in drop_columns:
            row = drop_positions[column]
            
            # Réinitialiser la colonne à zéro pour effacer la goutte précédente
            if row >= resized_image.shape[0] - 1:
                drop_columns.remove(column)
                columns_to_erase.append((column, row))  # Ajouter la colonne à effacer à la liste
            else:
                row += 1  # Descendre la goutte d'une ligne
                drop_positions[column] = row  # Mettre à jour la position de la goutte

                # Mettre à jour l'image avec la goutte de pluie
                resized_image[row][column] = 255  # Intensité maximale

        # Effacer progressivement les colonnes
        new_columns_to_erase = []
        for column, row in columns_to_erase:
            for r in range(row, -1, -1):
                intensity = (resized_image[r][column] * 0.8).astype(np.uint8)  # Diminuer de 20%
                resized_image[r][column] = intensity
            # Ajouter la colonne à la nouvelle liste si elle n'est pas encore entièrement effacée
            if row > 0:
                new_columns_to_erase.append((column, row - 1))
        columns_to_erase = new_columns_to_erase
            
        # Mettre à jour l'affichage de l'ASCII art dans la fenêtre tkinter
        a_image = image_to_ascii(resized_image)
        with ascii_image_lock:
            rain_ascii_image = a_image
        if not running:
            break
        
def create_rain_drops(resized_image, drop_positions):
    global running, last_ascii_image, rain_ascii_image
    drop_columns = []  # Liste des colonnes pour les gouttes de pluie

    while running:
        # Générer une nouvelle goutte de pluie
        if len(drop_columns) < 50:
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
            else:
                row += 1  # Descendre la goutte d'une ligne
                drop_positions[column] = row  # Mettre à jour la position de la goutte

                # Mettre à jour l'image avec la goutte de pluie
                resized_image[row][column] = 255  # Intensité maximale
                    # Mettre à jour l'affichage de l'ASCII art dans la fenêtre tkinter
        a_image = image_to_ascii(resized_image)
        with ascii_image_lock:
            global ascii_image
            rain_ascii_image = a_image
        if not running:
            break

def erase_rain_columns(resized_image, drop_positions, columns_to_erase_queue):
    global running, last_ascii_image, rain_ascii_image
    
    while running:
        # Effacer progressivement les colonnes
        if not columns_to_erase_queue.empty():
            columns_to_erase = []
            while not columns_to_erase_queue.empty():
                column, row = columns_to_erase_queue.get()
                columns_to_erase.append((column, row))

            for column, row in columns_to_erase:
                for r in range(row, -1, -1):
                    intensity = (resized_image[r][column] * 0.8).astype(np.uint8)  # Diminuer de 20%
                    resized_image[r][column] = intensity
                
                # Ajouter la colonne à la liste d'effacement si elle n'est pas encore entièrement effacée
                if row > 0:
                    columns_to_erase_queue.put((column, row - 1))
                
        # Mettre à jour l'affichage de l'ASCII art dans la fenêtre tkinter
        a_image = image_to_ascii(resized_image)
        with ascii_image_lock:
            global ascii_image
            rain_ascii_image = a_image
        
        if not running:
            break


# Création de la fenêtre tkinter
root = tk.Tk()
root.configure(bg='#000')


sw = root.winfo_screenwidth()
sh = root.winfo_screenheight()
root.geometry("%dx%d+%d+%d" % (1100, 620, (sw-1100)/2, (sh-620)/2))
directory = os.getcwd()
#root.tk.call('wm','iconphoto',root._w,tk.PhotoImage(file=directory + "/matrix-linux.png"))

if sys.platform.startswith('win32'):
    root.iconbitmap(os.path.join(wd,'.','matrix.ico'))
elif sys.platform.startswith('linux'):
    #root.iconbitmap(os.path.join(wd,'.','matrix-linux.png'))
    root.tk.call('wm','iconphoto',root._w,tk.PhotoImage(file=os.path.join(wd,'.','matrix-linux.png')))
    pass
elif sys.platform.startswith('darwin'):
    root.iconbitmap(os.path.join(wd,'.','matrix-mac.icns'))

root.title("ASCII Camera")
if getattr(sys, 'frozen', False):
    import pyi_splash

    # Fermeture du splash screen
    pyi_splash.update_text('UI Loaded ...')
    pyi_splash.close()

# Création du widget Label pour afficher l'ASCII art
w = tk.Label(root, text="", font=("Courier New", 8), fg='#0f0', bg='#000')
w.pack()

# Variables partagées entre les threads
frame_lock = threading.Lock()
ascii_image_lock = threading.Lock()
frame = None
ascii_image = ""

# Fonction pour mettre à jour l'image capturée
def capture_frame():
    global frame, running
    if platform.system() == 'Windows':
        cap = cv2.VideoCapture(camera,cv2.CAP_DSHOW)
    elif platform.system() == 'Linux':
        cap = cv2.VideoCapture(camera)
    
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
    
    while running:
        ret, f = cap.read()
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
        if not running:
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
        time.sleep(0.004)  # Temps d'attente arbitraire
        if not running:
            break

# Fonction pour mettre à jour l'affichage de l'ASCII art dans la fenêtre tkinter
def update_tkinter():
    global running, ascii_image_result, characters_str
    while running:
        rain_ascii_image_cut_line = ""
        ascii_image_result = ""        
        with ascii_image_lock:
            ascii_image_cut = ascii_image.split("\n")
            rain_ascii_image_cut = rain_ascii_image.split("\n")
            ascii_image_result = ""

            for i in range(len(ascii_image_cut)):
                ascii_image_cut_line = list(ascii_image_cut[i])
                rain_ascii_image_cut_line = list(rain_ascii_image_cut[i])
                
                for j in range(len(ascii_image_cut_line)):
                    if rain_ascii_image_cut_line[j] != ' ' and rain_ascii_image_cut_line[j] in characters:
                        index_rain = characters_str.index(rain_ascii_image_cut_line[j])
                        index_ascii = characters_str.index(ascii_image_cut_line[j])
                        
                        if index_rain > index_ascii:
                            ascii_image_cut_line[j] = rain_ascii_image_cut_line[j]
                
                ascii_image_result += "".join(ascii_image_cut_line) + "\n"

            a_image = ascii_image_result
        tkinter_thread_event.set()
        w.configure(text=a_image)
        w.update()
        tkinter_thread_event.clear()
        if not running:
            break

def send_to_virtual_camera():
    global running, ascii_image_result, wd

    # Paramètres de l'image, 
    output_width = 1100
    output_height = 620
    font_size = 12

    # Chargez une police pour afficher les caractères
    font = ImageFont.truetype(os.path.join(wd,'.','courier-new.ttf'), font_size)

    # Créez une nouvelle image avec les dimensions souhaitées et remplissez-la de blanc
    image = Image.new('RGB', (output_width, output_height), color='white')
    draw = ImageDraw.Draw(image)

    # Divisez le texte en lignes
    lines = ascii_image_result.split('\n')

    # Calculez la position de départ pour centrer le texte dans l'image
    start_x = (output_width - len(lines[0]) * font_size) // 2
    start_y = (output_height - len(lines) * font_size) // 2

    # Dessinez chaque ligne de texte sur l'image
    for i, line in enumerate(lines):
        draw.text((start_x, start_y + i * font_size), line, fill='black', font=font)
        
    image_data = BytesIO()
    image.save(image_data, format='PNG')
    
    # Choisissez la largeur et la hauteur de la caméra virtuelle
    width = 640
    height = 480

    # Créez un tampon pour stocker les images
    buffer = np.zeros((height, width, 3), dtype=np.uint8)

    # Créez et démarrez la caméra virtuelle
    with pyvirtualcam.Camera(width, height, 30) as cam:
        while running:
            # (À FAIRE : Attendez ici pour que l'image ASCII soit mise à jour)
            tkinter_thread_event.wait()  # Si vous utilisez un Event pour signaler la mise à jour de l'image ASCII

            # Convertissez le texte ASCII en image à l'aide de Pillow
            img_pil = Image.new('RGBA', (output_width, output_height), (0, 0, 0, 255))
            draw = ImageDraw.Draw(img_pil)
            draw.text((0, 0), ascii_image_result, font=font, fill=(0, 255, 0, 255))
            
            # Redimensionnez l'image PIL avant de la convertir en tableau NumPy
            img_resized = img_pil.resize((width, height), resample=Image.LANCZOS)
            img_np = np.array(img_resized)

            # Copiez l'image PIL dans le tampon NumPy
            buffer[:, :] = img_np[:, :, :3]

            # Envoyez le tampon à la caméra virtuelle
            cam.send(buffer)

            # Attendez un peu pour éviter de surcharger le CPU
            cam.sleep_until_next_frame()
            if not running:
                break

tkinter_thread_event = threading.Event()

# Lancement des threads
capture_thread = threading.Thread(target=capture_frame)

ascii_thread = threading.Thread(target=update_ascii_image)

tkinter_thread = threading.Thread(target=update_tkinter)

# Création de l'image et des positions initiales pour la simulation de pluie
resized_image = np.zeros((720, 1280), dtype=np.uint8)
drop_positions = np.zeros(1280, dtype=int)

create_rain_drops_thread = threading.Thread(target=create_rain_drops, args=(resized_image, drop_positions))
erase_rain_columns_thread = threading.Thread(target=erase_rain_columns, args=(resized_image, drop_positions, columns_to_erase_queue))

virtual_camera_thread = threading.Thread(target=send_to_virtual_camera)

threads = [capture_thread, ascii_thread, tkinter_thread, create_rain_drops_thread, erase_rain_columns_thread, virtual_camera_thread]

for thread in threads:
    thread.daemon = True
    thread.start()

# Boucle principale de la fenêtre tkinter
root.mainloop()

# Arrêt propre du programme
running = False
stop.set()

for thread in threads:
    thread.join(timeout=1.0)
    time.sleep(1.001)

sys.exit(0)