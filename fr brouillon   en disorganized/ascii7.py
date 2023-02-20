import sys
import cv2
import queue
import threading
import concurrent.futures
import itertools
import time
from PIL import ImageFont, ImageDraw, Image
import numpy as np
from multiprocessing import Process, Queue

# Set the dimensions of the ASCII image
ASCII_WIDTH = 100
ASCII_HEIGHT = 60

# Define the ASCII characters to use
ASCII_CHARS = ["@", "#", "S", "%", "?", "*", "+", ";", ":", ",", "."]

# Set the number of threads to use for ASCII conversion
NUM_THREADS = 4

# Initialize the OpenCV window
cv2.namedWindow("ASCII Camera", cv2.WINDOW_NORMAL)

# Initialize the OpenCV video
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter("output.avi", fourcc, 20.0, (1280, 960))

# Function to capture frames from the camera
def capture_frames(frame_queue):
    cap = cv2.VideoCapture(1)
    while True:
        ret, frame = cap.read()
        if ret:
            frame_queue.put(frame)
        else:
            break
    frame_queue.put(None)

# Function to convert frames to ASCII and add to queue
def convert_and_enqueue(frame_queue, ascii_queue):
    while True:
        frame = frame_queue.get()
        if frame is None:
            # Signal the end of the queue
            ascii_queue.put((None, None))
            break
        ascii_image = convert_to_ascii(frame, ASCII_WIDTH, ASCII_HEIGHT, ASCII_CHARS)
        ascii_queue.put((frame_queue.qsize(), ascii_image))

# Function to convert the frame to ASCII
def convert_to_ascii(frame, width, height, characters):
    """Convert an image to an ASCII image."""
    image = frame
    image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    image = cv2.bitwise_not(image)
    image = cv2.resize(image, (width, height))

    # Split the image into slices for parallel processing
    slice_height = height // NUM_THREADS
    slices = []
    for i in range(NUM_THREADS):
        start = i * slice_height
        end = (i + 1) * slice_height
        slices.append(image[start:end, :])

    # Process the slices in parallel
    with concurrent.futures.ThreadPoolExecutor() as executor:
        ascii_slices = list(executor.map(convert_slice_to_ascii, slices, itertools.repeat(characters)))

    # Join the ASCII slices back into a single string
    ascii_image = "\n".join(ascii_slices)

    return ascii_image

# Function to convert a slice of an image to ASCII
def convert_slice_to_ascii(slice, characters):
    """Convert a slice of an image to an ASCII string."""
    ascii_slice = ""
    for row in slice:
        for pixel_value in row:
            ascii_character = get_ascii_character(pixel_value, characters)
            ascii_slice += ascii_character
        ascii_slice += "\n"
    return ascii_slice

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
def display_ascii(ascii_queue, display_queue):
    while True:
        pos, ascii_image = ascii_queue.get()
        if ascii_image is None:
            # Signal the end of the queue
            display_queue.put(None)
            break
        image = ascii_to_image(ascii_image)
        display_queue.put((pos, image))

# Function to convert ASCII to PIL image
def ascii_to_image(ascii_image):
    width, height = ASCII_WIDTH * 8, ASCII_HEIGHT * 12
    image = Image.new("RGB", (width, height), color=(0, 0, 0))
    draw = ImageDraw.Draw(image)
    font = ImageFont.truetype("arial.ttf", 12)
    for y, line in enumerate(ascii_image.split("\n")):
        for x, char in enumerate(line):
            if char != " ":
                draw.text((x * 8, y * 12), char, font=font, fill=(0, 255, 0))
    return image

# Function to display the PIL image
def display_image(display_queue):
    # Create a buffer to store the images
    buffer = {}
    
    # Create a lock to prevent concurrent access to the buffer
    lock = threading.Lock()

    # Create a counter to keep track of the last frame shown
    last_pos = -1

    while True:
        result = display_queue.get()
        if result is None:
            break
        pos, image = result
        if pos is not None and pos > last_pos:
            # Add the image to the buffer
            with lock:
                buffer[pos] = image
            last_pos = pos
        # Display the most recent image
        with lock:
            if last_pos in buffer:
                cv2.imshow("ASCII Camera", np.array(buffer[last_pos]))
                out.write(np.array(buffer[last_pos]))
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break


    cv2.destroyAllWindows()

# Main function
def main():
    # Create a queue for the frames
    frame_queue = Queue()

    # Create a queue for the ASCII images
    ascii_queue = Queue()

    # Create a queue for the display images
    display_queue = Queue()

    # Create threads for the video capture and ASCII conversion
    capture_thread = threading.Thread(target=capture_frames, args=(frame_queue,))
    convert_threads = []
    for i in range(NUM_THREADS):
        convert_thread = threading.Thread(target=convert_and_enqueue, args=(frame_queue, ascii_queue))
        convert_threads.append(convert_thread)

    # Create processes for the display of the ASCII images
    display_processes = []
    for i in range(4):
        display_process = Process(target=display_ascii, args=(ascii_queue, display_queue))
        display_processes.append(display_process)
    display_process = Process(target=display_image, args=(display_queue,))
    display_processes.append(display_process)

    # Start the threads and processes
    capture_thread.start()
    for convert_thread in convert_threads:
        convert_thread.start()
    for display_process in display_processes:
        display_process.start()

    # Wait for all threads and processes to finish
    capture_thread.join()
    for convert_thread in convert_threads:
        convert_thread.join()
    for display_process in display_processes:
        display_process.join()

    # Release the OpenCV video
    out.release()

if __name__ == "__main__":
    main()
