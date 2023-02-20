# Function to convert the frame to ASCII
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
def convert_to_ascii(frame, width, characters):
    """Convertit une image en une image ASCII."""
    image = frame
    height = round(width / image.size[0] * image.size[1] * 2)
    image = image.resize((width, height))
    image = image.convert("L")
    ascii_image = ""
    for y in range(height):
        for x in range(width):
            pixel_value = image.getpixel((x, y))
            ascii_character = get_ascii_character(pixel_value, characters)
            ascii_image += ascii_character
        ascii_image += "\n"
    return ascii_image

# Function to get the ASCII character for a given pixel value
def get_ascii_character(pixel_value, characters):
    # Determine the range of pixel values per character
    range_per_char = 255 / (len(characters) - 1)

    # Find the index of the character to use for the pixel value
    char_index = round(pixel_value / range_per_char)

    # Ensure that the index is within the range of characters
    char_index = min(char_index, len(characters) - 1)

    # Return the ASCII character for the pixel value
    return characters[char_index]

# Function to display the ASCII image
def display_ascii(ascii_image):
    for line in ascii_image.split("\n"):
        for char in line:
            if char != "\n" and not char.isdigit():
                print(f"Invalid character: {char}")
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
        ascii_image = convert_to_ascii(frame, ASCII_WIDTH, ASCII_CHARS)

        # Display the ASCII image
        display_ascii(ascii_image)

        # Exit if 'q' is pressed
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # Release the video writer and destroy the OpenCV window
    cv2.destroyAllWindows()
    out.release()
    sys.exit(0)

if __name__ == "__main__":
    main()

# Function to get the ASCII character for a given pixel value
def get_ascii_character(pixel_value, characters):
    # Determine the range of pixel values per character
    range_per_char = 255 / (len(characters) - 1)

    # Find the index of the character to use for the pixel value
    char_index = round(pixel_value / range_per_char)

    # Ensure that the index is within the range of characters
    char_index = min(char_index, len(characters) - 1)

    # Return the ASCII character for the pixel value
    return characters[char_index]

# Function to display the ASCII image
def display_ascii(ascii_image):
    for line in ascii_image.split("\n"):
        for char in line:
            if char != "\n" and not char.isdigit():
                print(f"Invalid character: {char}")
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
        ascii_image = convert_to_ascii(frame, ASCII_WIDTH, ASCII_CHARS)

        # Display the ASCII image
        display_ascii(ascii_image)

        # Exit if 'q' is pressed
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # Release the video writer and destroy the OpenCV window
    cv2.destroyAllWindows()
    out.release()
    sys.exit(0)

if __name__ == "__main__":
    main()
