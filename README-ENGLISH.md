- - - -

# MATRIX #

Capture your WebCam in real time to an ASCII Art renderer in a Qt6 window and to a virtual webcam, all in Python.

Pour la version en français rendez-vous [ici](./README.md)

- - - -

## Installation ##

__**Steps required**__ to install Matrix on your personal computer.

* Get Python:

* **On Windows**: visit the official website [python.org](https://www.python.org/).

* **On MacOS**: choose between [homebrew](https://brew.sh/index_fr) or the official [python.org](https://www.python.org/) site.

* **On Linux** : install **Python3**(>=3.6) via your **package manager**.

* When installing from the official website only, don't forget to check the box **add path or Path variable** and that usage will be **available to all users** of your computer.

  

<img src="https://linuxhint.com/wp-content/uploads/2022/09/How-to-Add-Python-to-Windows-Path-3.png" data-canonical-src="https://linuxhint.com/wp-content/uploads/2022/09/How-to-Add-Python-to-Windows-Path-3.png" width="512" height="288" />

  

__**And finally:**__

  

* If you haven't already done so: install Git on your computer, more info [here](https://git-scm.com/book/fr/v2/D%C3%A9marrage-rapide-Installation-de-Git)

* Then open a terminal and enter the following commands:

```bash

$ git clone https://github.com/Bit-Scripts/Matrix.git

$ cd Matrix

pip install -r requirements.txt

```

  

- - - -
## Configuration ##

* **On Windows**: please follow the instructions to install 'unitycamera' [available here](https://github.com/schellingb/UnityCapture)
* **On Linux** : 
    1.  Install v4l2loopback via your package manager.
        - On Ubuntu/Debian: `sudo apt-get install v4l2loopback`
        - On Arch: `sudo pacman -S v4l2loopback`
        - On Fedora: `sudo dnf install v4l2loopback`
        - On openSUSE: `sudo zypper install v4l2loopback`
    2. After installation, ensure that the v4l2loopback module is loaded on your system by running the following command:
    ```bash
    $ lsmod | grep v4l2loopback
    ```
    3. Then activate the v4l2loopback module
    ```bash
    $ sudo modprobe v4l2loopback
    ```

## Usage ##

```bash

$ python ascii17.py #the program launches

```
I advise you to use a venv or anaconda to manage the installation of the necessary packages via pip.

Otherwise, binaries are available for direct download from the project [releases](https://github.com/Bit-Scripts/Matrix/releases). 
  

Here's an example of rendering:

<img src="./Matrix.GIF" data-canonical-src="https://cdn.discordapp.com/attachments/1077054466181832724/1077627784656080936/image.png" width="512" height="288" />

  

- - - -

## To Contribute ##

  

We welcome contributions from the community! To contribute, please follow the steps below:

* Fork the project
* Create a new branch (git checkout -b feature/feature-name)
* Commit your changes (git commit -am 'Add new feature')
* Push the branch (git push origin feature/feature-name)
* Create a pull request

- - - -  
## License ##
  
This project is licensed under the GPL V3 - see the file [LICENSE](./LICENSE.md) for more details.

- - - -