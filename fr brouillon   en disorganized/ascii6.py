import sys
import cv2
import queue
import threading
from PIL import ImageFont, ImageDraw, Image
import numpy as np

# Set the dimensions of the ASCII image
ASCII_WIDTH = 100

# Define the ASCII characters to use
ASCII_CHARS = ["@", "#", "S", "%", "?", "*", "+", ";", ":", ",", "."]

# Initialisation de la fenêtre OpenCV
cv2.namedWindow("ASCII Camera", cv2.WINDOW_NORMAL)

# Initialisation de la vidéo OpenCV
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter("output.avi", fourcc, 20.0, (1280, 960))

# Function to capture frames from the camera
def captureframes(q):
    cap = cv2.VideoCapture(1)
    while True:
        ret, frame = cap.read()
        if ret:
            q.put(frame)
        else:
            break
    cap.release()

# Function to convert the frame to ASCII
def convert_to_ascii(image, cols=120, rows=35):
    gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    resized_image = cv2.resize(gray_image, (cols, rows), interpolation=cv2.INTER_AREA)

    # Convert the grayscale image to ASCII
    ascii_chars = " .:-=+*#%@"
    ascii_image = ""
    for row in resized_image:
        for pixel in row:
            ascii_image += ascii_chars[int(pixel / 255.0 * (len(ascii_chars) - 1))]
        ascii_image += "\n"

    return ascii_image

# Function to display the ASCII image
def display_ascii(ascii_image):
    # Convertit la chaîne de caractères en un tableau numpy d'entiers
    ascii_array = np.array([list(map(int, line)) for line in ascii_image.split("\n") if line], dtype=np.uint8)

    # Convertit l'image en format BGR
    bgr_image = cv2.cvtColor(ascii_array, cv2.COLOR_GRAY2BGR)

    # Affiche l'image à l'écran
    cv2.imshow("ASCII Camera", bgr_image)
    cv2.waitKey(1)

    # Écrit l'image dans la vidéo de sortie
    out.write(bgr_image)

# Main function
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

    cv2.destroyAllWindows()
    out.release()
    sys.exit(0)


if __name__ == "__main__":
    main()
