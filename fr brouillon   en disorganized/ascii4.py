import cv2
from PIL import Image, ImageDraw, ImageFont
import numpy as np
import threading

# Dimensions de l'image ASCII générée
WIDTH = 1280
HEIGHT = 720

# Charger le fichier de police pour le texte ASCII
font_path = "C:\\Windows\\Fonts\\consola.ttf"
font_size = 36
font = ImageFont.truetype(font_path, font_size)

# définir les caractères ASCII et leur équivalent en intensité de pixel
ascii_chars = [' ', '.', ',', ':', ';', '!', '*', 'o', 'e', '&', '8', '#', '@']
gray_scale = [i for i in range(0, 256, 26)]

# Initialiser la capture vidéo
cap = cv2.VideoCapture(1)

# Créer l'objet d'écriture vidéo OpenCV
out = cv2.VideoWriter('output.avi', cv2.VideoWriter_fourcc(*'XVID'), 25.0, (WIDTH, HEIGHT))

# Fonction pour convertir une image en art ASCII
def convert_to_ascii(image):
    # Obtenir les dimensions de l'image
    height, width = image.shape  

    # Merge channels to create color image (3 channels)
    image //= 26

    # Calculer le ratio de conversion des dimensions de l'image
    width_ratio = width / WIDTH
    height_ratio = height / HEIGHT
    ratio = max(width_ratio, height_ratio)

    # Redimensionner l'image pour correspondre aux dimensions de l'image ASCII
    new_width = int(width / ratio)
    new_height = int(height / ratio)
    resized_image = cv2.resize(image, (new_width, new_height))

    # Convertir chaque valeur de pixel en caractère ASCII
    ascii_pixels = [[ascii_chars[pixel] for pixel in row] for row in resized_image]
    ascii_text = '\n'.join([''.join(row) for row in ascii_pixels])

    # Ajouter les caractères ASCII à l'image et la retourner
    ascii_image = Image.new('RGB', (width, height), color=(0, 0, 0))
    draw = ImageDraw.Draw(ascii_image)
    font = ImageFont.load_default()
    draw.text((0, 0), ascii_text, font=font, fill=(255, 255, 255))
    return np.array(ascii_image)

cv2.namedWindow("ASCII Camera", cv2.WINDOW_NORMAL)
cv2.resizeWindow("ASCII Camera", WIDTH, HEIGHT)
"""
# Boucle principale pour capturer des images de la captureéra, les convertir en art ASCII et les écrire dans la vidéo virtuelle
while(cap.isOpened()):
    # Capturer une image de la caméra
    ret, frame = cap.read()

    # Convertir l'image en niveaux de gris
    if ret:
        gray_image = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        ascii_image = convert_to_ascii(gray_image)
                
        # Afficher l'image ASCII
        cv2.imshow("ASCII Camera", np.array(ascii_image))
        cv2.resizeWindow("ASCII Camera", WIDTH, HEIGHT)
            
        # Rafraîchir la fenêtre
        cv2.waitKey(1)            

    # Sortir de la boucle si la touche 'q' est pressée
    if cv2.waitKey(1) & 0xFF == ord('q'):
"""

while True:
    # Capturer une image depuis la webcam
    ret, frame = cap.read()

    # Convertir l'image en niveaux de gris
    gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Redimensionner l'image pour correspondre aux dimensions de l'image ASCII
    ascii_height, ascii_width = gray_frame.shape
    ascii_width *= len(ascii_chars)
    ascii_height *= len(ascii_chars)
    ascii_image = Image.new('RGB', (ascii_width, ascii_height), color=(0, 0, 0))

    # Ajouter les caractères ASCII à l'image
    draw = ImageDraw.Draw(ascii_image)
    for y in range(gray_frame.shape[0]):
        for x in range(gray_frame.shape[1]):
            intensity = gray_frame[y, x]
            ascii_char = ascii_chars[int(intensity/255*(len(ascii_chars)-1))]
            draw.text((x*len(ascii_chars), y*len(ascii_chars)), ascii_char, font=font, fill=(255, 255, 255))

    # Afficher l'image ASCII dans une fenêtre
    cv2.imshow('ASCII Camera', np.array(ascii_image))

    # Quitter le programme si la touche 'q' est pressée
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Libérer la capture vidéo et fermer la fenêtre
cap.release()
out.release()
cv2.destroyAllWindows()
