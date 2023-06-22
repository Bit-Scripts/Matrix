
- - - -

# MATRIX #

Capture de votre WebCam en temps réel vers un rendu ASCII Art dans une fenêtre Qt6 et vers une webcam virtuelle, le tout en Python.

For English version go to [here](./README-ENGLISH.md)

- - - -

## Installation ##

__**Étapes nécessaires**__ pour installer Matrix sur votre ordinateur personnel.

* Procurez-vous Python :

*  **Sur Windows** : rendez-vous sur le site officiel [python.org](https://www.python.org/).

*  **Sur MacOS** : vous avez le choix entre [homebrew](https://brew.sh/index_fr) ou le site officiel [python.org](https://www.python.org/).

*  **Sur Linux** : installez **Python3**(>=3.6) via votre **gestionnaire de paquets**.

* Attention au moment de l'installation uniquement depuis le site officiel n'oubliez pas de bien cocher la case ajouter **le chemin d'accès ou la variable Path** et que l'utilisation sera **disponible pour tous les utilisateurs** de votre ordinateur.

  

<img  src="https://linuxhint.com/wp-content/uploads/2022/09/How-to-Add-Python-to-Windows-Path-3.png"  data-canonical-src="https://linuxhint.com/wp-content/uploads/2022/09/How-to-Add-Python-to-Windows-Path-3.png"  width="512"  height="288"  />

  

__**Et pour Finir :**__

  

* Si cela n'est pas encore fait : installez Git sur votre ordinateur, plus d'info [ici](https://git-scm.com/book/fr/v2/D%C3%A9marrage-rapide-Installation-de-Git)

* Ensuite ouvrez un terminal et entrez les commandes suivantes :

```bash

$  git  clone  https://github.com/Bit-Scripts/Matrix.git

$  cd  Matrix

$  pip  install  -r  requirements.txt

```

  

- - - -
## Configuration ##

*  **Sur Windows** : je vous invite à suivre les instrutions pour installer 'unitycamera' [disponible ici.](https://github.com/schellingb/UnityCapture)
*  **Sur Linux** : 
    1.  Installez v4l2loopback via votre gestionnaire de paquets.
        -   Sur Ubuntu/Debian : `sudo apt-get install v4l2loopback`
        -   Sur Arch : `sudo pacman -S v4l2loopback`
        -   Sur Fedora : `sudo dnf install v4l2loopback`
        -   Sur openSUSE : `sudo zypper install v4l2loopback`
    2. Après l'installation, assurez-vous que le module v4l2loopback est chargé sur votre système en exécutant la commande suivante :
    ```bash
    $ lsmod | grep v4l2loopback
    ```
    3. Ensuite activé le module v4l2loopback
    ```bash
    $ sudo modprobe v4l2loopback
    ```

## Utilisation ##

```bash

$  python  ascii17.py  #le programme se lance

```
Je vous conseil de passé par un venv ou anaconda pour gérer l'installation des paquets nécessaires via pip.

Sinon des binaires sont disponibles directement à télécharger sur les [releases](https://github.com/Bit-Scripts/Matrix/releases) du projet. 
  

Voici un exemple de rendu :

<img  src="./Matrix.GIF"  data-canonical-src="https://cdn.discordapp.com/attachments/1077054466181832724/1077627784656080936/image.png"  width="512"  height="288"  />

  

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