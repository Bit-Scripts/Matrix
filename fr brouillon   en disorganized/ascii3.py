import cv2
from PIL import Image, ImageDraw, ImageFont
import numpy

# Dimensions de l'image ASCII générée
WIDTH = 1280
HEIGHT = 720

# Créer l'objet de capture vidéo OpenCV
capture = cv2.VideoCapture(1)

# Définir les caractères ASCII
ascii_chars = [' ', '.', '*', ':', 'o', '&', '8', '#', '@']

# Récupérer la résolution de la captureéra
width = int(capture.get(cv2.CAP_PROP_FRAME_WIDTH))
height = int(capture.get(cv2.CAP_PROP_FRAME_HEIGHT))

# Créer l'objet d'écriture vidéo OpenCV
out = cv2.VideoWriter('output.avi', cv2.VideoWriter_fourcc(*'XVID'), 25.0, (WIDTH, HEIGHT))

# Fonction pour convertir une image en art ASCII
def convert_to_ascii(image):
    # Convertir l'image en niveaux de gris
    gray_image = Image.fromarray(cv2.cvtColor(image, cv2.COLOR_BGR2GRAY))
    gray_image //= 26

    # Calculer le ratio de conversion des dimensions de l'image
    width_ratio = width / WIDTH
    height_ratio = height / HEIGHT
    ratio = max(width_ratio, height_ratio)

    # Redimensionner l'image pour correspondre aux dimensions de l'image ASCII
    new_width = int(width / ratio)
    new_height = int(height / ratio)
    resized_image = gray_image.resize((new_width, new_height))

    # Convertir chaque valeur de pixel en caractère ASCII
    ascii_pixels = [[ascii_chars[pixel] for pixel in row] for row in resized_image]
    ascii_text = '\n'.join([''.join(row) for row in ascii_pixels])

    # Ajouter les caractères ASCII à l'image et la retourner
    ascii_image = Image.new('RGB', (width, height), color=(0, 0, 0))
    draw = ImageDraw.Draw(ascii_image)
    font = ImageFont.load_default()
    draw.text((0, 0), ascii_text, font=font, fill=(255, 255, 255))
    return cv2.cvtColor(numpy.array(ascii_image), cv2.COLOR_RGB2BGR)

# Boucle principale pour capturer des images de la captureéra, les convertir en art ASCII et les écrire dans la vidéo virtuelle
while True:
    # Lire la trame vidéo de la webcapture
    ret, frame = capture.read()

    # Convertir la trame en ASCII
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    num_chars = len(ascii_chars)
    gray_adjusted = gray * (num_chars - 1) // 255
    ascii_pixels = [[ascii_chars[pixel] for pixel in row] for row in gray_adjusted]
    gray = cv2.resize(gray_adjusted, (WIDTH, HEIGHT))
    ascii_pixels = [[ascii_chars[pixel] for pixel in row] for row in gray]
    ascii_text = '\n'.join([''.join(row) for row in ascii_pixels])

    # Afficher l'ASCII dans une fenêtre
    cv2.imshow('ASCII Webcapture', gray)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Libérer les ressources de la captureéra et de la vidéo
capture.release()
out.release()
cv2.destroyAllWindows()
