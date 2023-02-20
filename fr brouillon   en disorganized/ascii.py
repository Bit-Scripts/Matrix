import cv2
import tkinter
import numpy as np

# Initialiser la fenêtre tkinter
root = tkinter.Tk()

# Récupérer le flux vidéo de la webcam
cap = cv2.VideoCapture(1)

# Définir la taille de la fenêtre tkinter
root.geometry("1920x1080")

root.configure(bg="black")

# Créer une liste pour stocker les caractères
characters = []

# Boucle infinie
while True:
    # Récupérer le flux vidéo de la webcam
    ret, frame = cap.read()
    
    # Redimensionner l'image
    frame = cv2.resize(frame, (1920, 1080))

    # Diviser l'image en carrés monospace
    for i in range(0, 1920, 10):
        for j in range(0, 1080, 10):
            # Récupérer le carré monospace
            crop_frame = frame[i:i+10, j:j+10]

            # Estimer le taux de luminosité du carré
            avg_color_per_row = np.average(crop_frame, axis=0)
            avg_color = np.average(avg_color_per_row, axis=0)

            # Remplacer le carré par le caractère qui a le plus de luminosité en commun
            if avg_color[0] > 200:
                characters.append("@")
            elif avg_color[0] > 150:
                characters.append("#")
            elif avg_color[0] > 100:
                characters.append("+")
            elif avg_color[0] > 50:
                characters.append("-")
            else:
                characters.append(" ")

    # Afficher les caractères dans la fenêtre tkinter
    txt = "".join(characters)
    w = tkinter.Label(root, text=txt, fg='#fff', bg='#000')
    w.pack()

    # Vider la liste des caractères
    characters = []
    
    # Mettre à jour la fenêtre tkinter
    root.update()

    # Sortir de la boucle si la touche 'q' est enfoncée
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Libérer le flux vidéo
cap.release()

# Fermer la fenêtre tkinter
root.destroy()