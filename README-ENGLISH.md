- - - -
    
# MATRIX #
  
Capture your WebCam in real time to an ASCII Art rendering in a Tkinter window, all in Python. 

- - - -  
## Installation ##
  
__**Steps needed**__ to install Matrix on your personal computer.   
* Get Python:
* **On Windows**: go to the official website [python.org](https://www.python.org/). 
* **On MacOS** : you can choose between [homebrew](https://brew.sh/) or the official website [python.org](https://www.python.org/).
* **On Linux** : install **Python** via your **packages manager**.
* Attention at the time of the installation only from the official site do not forget to check the box add **the path or the variable Path** and that the use will be **available for all users** of your computer.  

<img src="https://linuxhint.com/wp-content/uploads/2022/09/How-to-Add-Python-to-Windows-Path-3.png" data-canonical-src="https://linuxhint.com/wp-content/uploads/2022/09/How-to-Add-Python-to-Windows-Path-3.png" width="512" height="288" />

__**And to Finish:**__

* If you haven't already done so: install Git on your computer, more info [here](https://git-scm.com/book/fr/v2/D%C3%A9marrage-rapide-Installation-de-Git)
* Then open a terminal and enter the following commands:    
   
```bash
$ git clone https://github.com/Bit-Scripts/Matrix.git
$ cd Matrix
$ pip install -r requirements.txt
```

- - - -
## Usage ##
   
```bash
$ python ascii12.py #the program starts
```

⚠️⚠️  
If the window remains black, look at the file ascii12.py by opening it, with a text editor for example the notepad of Windows and change the line 17 `camera = 1` (the possible values of the variable camera are 0, 1 or 2) (more info line 67 we see there the command with cv2 of OpenCV to capture the WebCam) Indeed, with Python I use the OpenCV library to capture your WebCam, only the Webcam can have the number 0, 1 or 2 (for example 1 for me). If the number of your webcam is not the right one, the script will not work, so you will have to change the value to find the one that matches your hardware.   
⚠️⚠️     

Here is an example of rendering:
   
<img src="https://cdn.discordapp.com/attachments/1077054466181832724/1077627784656080936/image.png" data-canonical-src="https://cdn.discordapp.com/attachments/1077054466181832724/1077627784656080936/image.png" width="512" height="288" />

- - - -
## To Contribute ##

We welcome contributions from the community! To contribute, please follow these steps:

* Fork the project
* Create a new branch (git checkout -b feature/feature-name)
* Commit your changes (git commit -am 'Add new feature')
* Push the branch (git push origin feature/feature-name)
* Create a pull request

- - - -  
## License ##
  
This project is licensed under the GPL V3 - see the file [LICENSE](./LICENSE.md) for more details.

- - - -