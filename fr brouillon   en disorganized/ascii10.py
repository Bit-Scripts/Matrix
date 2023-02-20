import sys
import cv2
import numpy as np
import threading
import queue
from PIL import Image, ImageDraw, ImageFont

# Fonction pour convertir une image en une image ASCII
def image_to_ascii(image, cols, scale, more_levels):
    # Détermine les caractères ASCII à utiliser pour représenter l'image
    #ascii_chars = np.asarray(list('..,:~+=?I7$ZO8DNM@'))#[::-1]
    #ascii_chars = np.asarray(list('.,:;il!^`¨"^-~_/\|(){ }[]+x*#@ocvunxzmwqpyrjftILJCVUYXZO0QPDB8$&MWBEAS9GHKNR'))#[::-1]
    #ascii_chars = np.asarray(list('....:~+?II77$O8DNM@'))#[::-1]
    ascii_chars = np.asarray(list('.,:;irsXA253hMHGS#9B&@'))[::-1]
    # Convertit l'image en niveaux de gris
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    
    # Égalisation d'histogramme
    qgray = cv2.equalizeHist(gray)

    # Redimensionne l'image selon le nombre de colonnes et l'échelle spécifiée
    height, width = gray.shape
    w = width / cols
    h = w / scale
    
    rows = int(height / h)
    if cols > width or rows > height:
        raise ValueError("Les valeurs de cols et de scale sont trop grandes.")

    ascii_image = np.empty((rows, cols), dtype=np.dtype('U1'))

    for i in range(rows):
        for j in range(cols):
            avg = int(np.mean(image[int(i * h):min(int((i + 1) * h), height), int(j * w):min(int((j + 1) * w), width)]) / (256 / ascii_chars.size))
            ascii_image[i, j] = ' ' if avg == 0 else ascii_chars[-avg]

    return ascii_image

# Fonction pour lire la vidéo et stocker chaque trame dans une file d'attente
def video_thread(camera, queue, running):
    cap = cv2.VideoCapture(camera)
    while cap.isOpened() and running:
        ret, frame = cap.read()
        if ret:
            queue.put(frame)
        else:
            break
        if not running:
            break
    cap.release()
    camera.terminate()
    camera.stop()
    camera.kill()
    
# Fonction pour lire chaque trame de la file d'attente, la convertir en image ASCII et l'afficher
def ascii_thread(queue, cols, scale, more_levels, running):
    while running:
        frame = queue.get()
        if frame is None:
            break
        ascii_image = image_to_ascii(frame, cols, scale, more_levels)
        
        # Définir la taille de l'image
        width, height = (1600, 900)

        # Créer une image vide avec une couleur de fond blanche
        img = np.zeros((height, width, 3), np.uint8)
        img[:] = (0, 0, 0)
        
        
        # Écrire chaque ligne de la ascii_image dans l'image
        font_path = r"C:\Windows\Fonts\LiberationMono-Regular.ttf"
        Monospace  =  ImageFont.truetype ( font_path, size=8 )
        font = cv2.FONT_HERSHEY_TRIPLEX
        font_scale = .2
        thickness = 1
        color = (0, 255, 0)
        
        line_height = int(height / len(ascii_image))
        
        for i, line in enumerate(ascii_image):
            text = ''.join(line)
            text_width, text_height = cv2.getTextSize(text, font, font_scale, thickness)[0]
            x = int((width - text_width) / 2)
            y = int((i * line_height) + ((line_height + text_height) / 2))
            cv2.putText(img, text, (x, y), font, font_scale, color, thickness, cv2.LINE_AA)
            

        # Redimensionner l'image
        #img = cv2.resize(img, (640, 480))
       
        # Affiche l'image ASCII
        cv2.imshow("ASCII Camera", img) 
        
        if not running:
            break
        
        if cv2.waitKey(1) == ord('q'):
            cv2.destroyAllWindows()
            running = False
            break
    cv2.destroyAllWindows()
    sys.exit(0)

   

# Fonction principale
def main():
    # Paramètres pour la génération de l'image ASCII
    cols = 500
    scale = .4
    more_levels = False
    running = True    
    
    # Vérifier si l'utilisateur a appuyé sur la touche "q"
    if cv2.waitKey(1) == ord('q'):
        running = False
        cv2.destroyAllWindows()
        image_queue.task_done()
        camera.terminate()
        display.terminate()
        camera.stop()
        display.stop()        
        camera.kill()
        display.kill()
        sys.exit(0)

    # Créer la file d'attente pour stocker les trames vidéo
    image_queue = queue.Queue()
    image_queue.join()

    # Créer le thread pour lire la vidéo
    camera = threading.Thread(target=video_thread, args=(1,image_queue, running))
    display = threading.Thread(target=ascii_thread, args=(image_queue,cols,scale,more_levels, running))
    # Lancement des threads
    camera.start()
    display.start()
    # Attente de la fin des threads
    camera.join()
    display.join() 
    
    camera.terminate()
    display.terminate()
    camera.stop()
    display.stop()        
    camera.kill()
    display.kill()
    image_queue.task_done()
    

if __name__ == '__main__':
    # Lancement de la fonction principale
    main()
