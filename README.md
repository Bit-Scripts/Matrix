- - - -
    
# MATRIX #
  
Capture de votre WebCam vers un rendu ASCII Art dans une fenêtre Tkinter, le tout en Python.  

- - - -  
## Installation ##
  
__**Étapes nécessaires**__ pour installer Matrix sur votre ordinateur personnel.   
* Procurez-vous Python :
* **Sur Windows** : rendez-vous sur le site officiel [python.org](https://www.python.org/). 
* **Sur MacOS** : vous avez le choix entre [homebrew](https://brew.sh/index_fr) ou le site officiel [python.org](https://www.python.org/).
* **Sur Linux** : installez **Python** via votre **gestionnaire de paquets**.
* Attention au moment de l'installation uniquement depuis le site officiel n'oubliez pas de bien cocher la case ajouter **le chemin d'accès ou la variable Path** et que l'utilisation sera **disponible pour tous les utilisateurs** de votre ordinateur.  

<img src="https://linuxhint.com/wp-content/uploads/2022/09/How-to-Add-Python-to-Windows-Path-3.png" data-canonical-src="https://linuxhint.com/wp-content/uploads/2022/09/How-to-Add-Python-to-Windows-Path-3.png" width="512" height="288" />

__**Et pour Finir :**__

* Si cela n'est pas encore fait : installez Git sur votre ordinateur, plus d'info [ici](https://git-scm.com/book/fr/v2/D%C3%A9marrage-rapide-Installation-de-Git)
* Ensuite ouvrez un terminal et entrez les commandes suivantes :    
   
```bash
$ git clone https://github.com/Bit-Scripts/Matrix.git
$ cd Matrix
$ pip install -r requirements.txt
```

- - - -
## Utilisation ##
   
```bash
$ python ascii12.py #le programme se lance
```

⚠️⚠️ Si la fenêtre reste noire, regardez le fichier ascii12.py en l'ouvrant, avec un éditeur de texte par exemple le bloc-notes de Windows et changer la ligne 17 `camera = 1` (les valeurs possibles de la variable camera sont 0, 1 ou 2) (plus d'info ligne 58 on y voit la commande avec cv2 d'OpenCV pour capturer la WebCam). En effet, avec Python j'utilise ma bibliothèque OpenCV pour capturer votre WebCam, seulement les Webcam peuvent avoir le numéro 0, 1 ou 2 (par exemple 1 pour moi). Si le numéro de votre webcam n'est pas le bon cela va engendrer une imposibilité au script de fonctionner, du coup il vous faudra changer la valeur pour trouver celle qui corespond à votre matériel. ⚠️⚠️   

Voici un exemple de rendu :
   
<img src="https://cdn.discordapp.com/attachments/1077054466181832724/1077296638252568656/image.png" data-canonical-src="https://cdn.discordapp.com/attachments/1077054466181832724/1077296638252568656/image.png" width="512" height="288" />

- - - -
## Pour Contribuer ##

Nous sommes ravis de recevoir des contributions de la communauté ! Pour contribuer, veuillez suivre les étapes suivantes :

* Forker le projet
* Créer une nouvelle branche (git checkout -b feature/nom-de-la-fonctionnalité)
* Commiter vos modifications (git commit -am 'Ajout d'une nouvelle fonctionnalité')
* Pousser la branche (git push origin feature/nom-de-la-fonctionnalité)
* Créer une pull request

- - - -  
## Licence ##
  
Ce projet est sous licence GPL V3 - voir le fichier [LICENSE](./LICENSE.md) pour plus de détails.

- - - -