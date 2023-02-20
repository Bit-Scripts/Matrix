import cv2
import numpy as np
import argparse
import os
import sys
from queue import Queue
from threading import Thread

# Fonction pour convertir une image en ASCII art
def image_to_ascii(image, cols, scale, moreLevels):
    # Définir les caractères ASCII utilisés pour le rendu
    asciiChars = np.asarray(list(' .,:irs?@9B&#')) if moreLevels else np.asarray(list(' .,:;irsXA253hMHGS#9B&@'))

    # Convertir l'image en niveaux de gris
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Redimensionner l'image en fonction du nombre de colonnes et de l'échelle souhaitée
    h, w = image.shape[:2]
    w = w * scale
    h = h * scale
    rows = int(h / w * cols)
    dim = (cols, rows)
    resized_gray = cv2.resize(gray, dim, interpolation = cv2.INTER_AREA)

    # Diviser l'intensité des pixels en fonction du nombre de niveaux ASCII disponibles
    levels = 255 if moreLevels else 16
    division = np.linspace(0, 255, levels + 1)
    charBins = np.int0(np.linspace(0, levels, len(asciiChars)))

    # Mapper chaque intensité de pixel à un niveau ASCII disponible
    asciiImage = ""
    for i in range(rows):
        for j in range(cols):
            grayPixel = resized_gray[i][j]
            binIdx = np.digitize(grayPixel, division)
            char = asciiChars[charBins[binIdx]-1]
            asciiImage += char
        asciiImage += "\n"
    return asciiImage

# Fonction pour ajouter des images ASCII à la queue
def queue_ascii_images(frames, ascii_queue, cols, scale, moreLevels):
    for frame in frames:
        ascii_frame = image_to_ascii(frame, cols, scale, moreLevels)
        ascii_queue.put(ascii_frame)

# Fonction pour afficher les images ASCII de la queue
def display_ascii_image(ascii_queue):
    while True:
        ascii_frame = ascii_queue.get()
        os.system('cls' if os.name == 'nt' else 'clear')
        print(ascii_frame)

# Fonction pour charger les images à partir de la vidéo
def load_video_frames(filename):
    video = cv2.VideoCapture(filename)
    frames = []
    while True:
        ret, frame = video.read()
        if not ret:
            break
        frames.append(frame)
    video.release()
    return frames

# Fonction principale
def main(filename, cols, scale, moreLevels):
    # Charger les images depuis la vidéo
    frames = load_video_frames(filename)

    # Créer une queue pour stocker les images ASCII
    ascii_queue = Queue()

    # Créer un thread pour ajouter des images ASCII à la queue
    ascii_thread = Thread(target=queue_ascii_images, args=(frames, ascii_queue, cols, scale, moreLevels))
    ascii_thread.daemon = True
    ascii_thread.start()

    # Afficher les images ASCII à partir de la queue
    display_ascii_image(ascii_queue)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Webcam ASCII art')
    parser.add_argument('filename', help='./example.png')
    parser.add_argument('-c', '--cols', type=int, default=80, help='120')
    parser.add_argument('--font', type=str, default='courier_new.ttf', help='arial.ttf')
    parser.add_argument('--scale', type=float, default=0.43, help='.43')
    parser.add_argument('--delay', type=int, default=30, help='40')
    parser.add_argument('--morelevels', action='store_true', help=False)
    args = parser.parse_args()
    main(args.filename, args.cols, args.scale, args.morelevels)
    
    
    
