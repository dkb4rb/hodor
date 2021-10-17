#!/usr/bin/python3
#coding: utf-8

import requests
import time
import re
import os
import signal
import sys
import pytesseract
from pwn import *
try:
    import Image
except ImportError:
    from PIL import Image

# Variables Globales
url = "http://158.69.76.135/level3.php"
ip_cap = "http://158.69.76.135/captcha.php"


def handler(signal, frame):
    sys.exit(0)


signal.signal(signal.SIGINT, handler)


def make_request():
    s = requests.session()
    captcha_url = requests.get(ip_cap)
    f = open("captcha.png", "wb")
    f.write(captcha_url.content)
    f.close()

    p1 = log.progress("captcha")
    p1.status("Obteniendo valor de Captcha\n")
    time.sleep(1)

    captcha_value = pytesseract.image_to_string("captcha.png")
    os.remove("captcha.png")
    p1.success("Captcha Retornado")

    return(captcha_value)

if __name__ == '__main__':

    ocr_value = make_request()
    print("----> {:s}\n\n".format(ocr_value))
