import sys
import numpy as np
import cv2
import tkinter as tk
from PIL import Image, ImageTk
import threading

# Définition des caractères à utiliser pour l'ASCII art
characters = np.asarray(list(' .,:;irsXA253hMHGS#9B&@'))

# Boolean pour tout arrêter
global running
running = True

# Camera 0, 1, ou 2 : 0 par défaut
global camera
camera = 1 # à Modifier si ne fonctionne pas

# Variable partagée pour signaler à un thread qu'il doit s'arrêter
stop = threading.Event()

# Fonction pour obtenir le caractère correspondant à une intensité de pixel donnée
def get_character(p):
    return characters[int(p/256 * len(characters))]

# Fonction pour convertir une image en ASCII art
def image_to_ascii(image):
    # Conversion de l'image en niveaux de gris
    gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    # Redimensionnement de l'image pour correspondre à la taille de la police de caractères utilisée
    resized_image = cv2.resize(gray_image, (int(gray_image.shape[1]/8), int(gray_image.shape[0]/16)))
    ascii_image = ""
    # Parcours de tous les pixels de l'image redimensionnée pour obtenir les caractères correspondants
    for i in range(resized_image.shape[0]):
        for j in range(resized_image.shape[1]):
            ascii_image += get_character(resized_image[i][j])
        ascii_image += "\n"
    return ascii_image

# Création de la fenêtre tkinter
root = tk.Tk()
root.configure(bg='#000')
root.geometry("1100x620")

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
    global frame
    cap = cv2.VideoCapture(camera) # ⚠️ voir ligne 17 ⚠️
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
    while running:
        ret, f = cap.read()
        with frame_lock:
            frame = f
        if not running:
            break

# Fonction pour mettre à jour l'image ASCII
def update_ascii_image():
    global ascii_image
    while running:
        with frame_lock:
            f = frame
        if f is not None:
            a_image = image_to_ascii(f)
            with ascii_image_lock:
                ascii_image = a_image
        if not running:
            break

# Fonction pour mettre à jour l'affichage de l'ASCII art dans la fenêtre tkinter
def update_tkinter():
    while running:
        with ascii_image_lock:
            a_image = ascii_image
        w.configure(text=a_image)
        w.update()
        if not running:
            break

# Lancement des threads
capture_thread = threading.Thread(target=capture_frame)
capture_thread.start()

ascii_thread = threading.Thread(target=update_ascii_image)
ascii_thread.start()

tkinter_thread = threading.Thread(target=update_tkinter)
tkinter_thread.start()

# Boucle principale de la fenêtre tkinter
root.mainloop()

# Arrêt propre du programme
running = False
stop.set()
capture_thread.join()
ascii_thread.join()
tkinter_thread.join()

sys.exit(0)