import cv2
import numpy as np
import os
import time
import sys
import queue
import threading


# Initialisation de la caméra
cap = cv2.VideoCapture(1)

# Initialisation de la fenêtre OpenCV
cv2.namedWindow("ASCII Camera", cv2.WINDOW_NORMAL)

# Initialisation de la vidéo OpenCV
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter("output.avi", fourcc, 20.0, (640, 480))

# Définition de la fonction pour convertir une image en ASCII
def convert_to_ascii(image, cols=120):
    # Set up ASCII characters and find range of pixel values
    ascii_chars = [" ", ".", ":", "-", "=", "+", "*", "#", "%", "@"]
    scale = (len(ascii_chars)-1)/255.0

    try:
        if len(image.shape) == 3 and image.shape[2] == 3:
            gray_image = cv2.cvtColor(image.astype(np.uint8), cv2.COLOR_BGR2GRAY)
        else:
            gray_image = image
    except cv2.error as e:
        print(f"Error converting image to grayscale: {e}")
        return None

    (height, width) = (image.shape[0],image.shape[1])

    cell_width = width / cols
    cell_height = cell_width / 2
    rows = int(height / cell_height)

    # Create an empty image to draw ASCII characters onto
    ascii_image = np.zeros((int(rows*cell_height), int(cols*cell_width), 3), np.uint8)

    # Draw each ASCII character in the image
    for i in range(rows):
        y1 = int(i * cell_height)
        y2 = int((i + 1) * cell_height)
        if i == rows - 1:
            y2 = height
        for j in range(cols):
            x1 = int(j * cell_width)
            x2 = int((j + 1) * cell_width)
            if j == cols - 1:
                x2 = width
            cell = gray_image[y1:y2, x1:x2]
            avg = int(np.average(cell) * scale)
            # Draw the ASCII character onto the image
            cv2.putText(ascii_image, ascii_chars[avg], (x1, y2), cv2.FONT_HERSHEY_SIMPLEX, cell_width/cell_height, (255, 255, 255), lineType=cv2.LINE_AA)

    return ascii_image


# Définition de la fonction pour lire les images de la caméra
def read_frame(queue):
    global cap, out
    
    while cap.isOpened():
        # Capturer une image de la caméra
        ret, frame = cap.read()
               
        # Convertir l'image en niveaux de gris
        if ret:
            try:
                if len(frame.shape) == 3 and frame.shape[2] == 3:
                    gray_image = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
                else:
                    gray_image = frame
            except cv2.error as e:
                print(f"Error converting image to grayscale: {e}")
                return None
            ascii_image = convert_to_ascii(gray_image)

            # Ajouter l'image à la file d'attente
            queue.put(ascii_image)
            
            # Ajouter l'image à la vidéo
            out.write(convert_to_ascii(gray_image).astype(np.uint8))
        else:
            break
    
    # Libérer la capture vidéo
    cap.release()

# Définition de la fonction pour afficher l'image ASCII
def display_ascii(ascii_image):
    # Resize the image to fit the window
    (height, width, ) = ascii_image.shape
    window_width = 800
    scale = window_width / width
    window_height = int(height * scale)
    ascii_image = cv2.resize(ascii_image, (window_width, window_height))

    # Display the image
    cv2.imshow("ASCII Camera", ascii_image)
    cv2.waitKey(1)

    # Write the image to the output video
    out.write(ascii_image)


# Définition de la fonction principale
def main():
    # Create a queue for the frames
    q = queue.Queue()

    # Create a thread for the video capture
    t = threading.Thread(target=captureframes, args=(q,))
    t.daemon = True
    t.start()

    # Main loop
    while True:
        # Get the frame from the queue
        frame = q.get()

        # Convert the frame to ASCII
        ascii_image = convert_to_ascii(frame)

        # Display the ASCII image
        display_ascii(ascii_image)

        # Exit if 'q' is pressed
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break


# Définition de la fonction de capture de frames
def captureframes(q):
    while True:
        # Capture the frame
        frame = cap.read()

        # Add the frame to the queue
        q.put(frame)


# Appel de la fonction principale
main()

# Release the camera and output video
cap.release()
out.release()

# Destroy the window
cv2.destroyAllWindows()