#!/usr/bin/python3
#coding: utf-8

import requests, time, pytesseract, re, os, signal, sys
from PIL import Image
from pwn import *

# Variables Globales
url = "http://158.69.76.135/level3.php"
ip_cap = "http://158.69.76.135/captcha.php"


def handler(signal, frame):
	sys.exit(0)

signal.signal(signal.SIGINT, handler)

def make_request():
	s = requests.session()
	r = requests.get(ip_cap)
	captcha_img = open("captcha.png", "wb")

if __name__ == '__main__':
	make_request()
