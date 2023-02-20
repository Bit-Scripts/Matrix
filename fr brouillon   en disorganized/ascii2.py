import numpy as np
import cv2
import tkinter as tk
from PIL import Image, ImageTk

# Définition des caractères à utiliser pour l'ASCII art
characters = np.asarray(list(' .,:;irsXA253hMHGS#9B&@'))

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

# Fonction pour mettre à jour l'affichage de l'ASCII art dans la fenêtre tkinter
def update_ascii_art():
    # Capture d'une image de la webcam
    cap = cv2.VideoCapture(1)
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
    ret, frame = cap.read()
    # Conversion de l'image en ASCII art
    ascii_image = image_to_ascii(frame)
    # Affichage de l'ASCII art dans le widget Label
    w.configure(text=ascii_image)
    w.update()
    # Planification de la prochaine mise à jour de l'affichage
    root.after(50, update_ascii_art)

# Lancement de la première mise à jour de l'affichage
update_ascii_art()

# Boucle principale de la fenêtre tkinter
root.mainloop()
