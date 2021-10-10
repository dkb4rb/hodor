#!/usr/bin/python3
# level0.py
# Juan Duque <3428@holbertonschool.com>
""" Import libraries necesary for execute program
"""
import requests, os
url = "http://158.69.76.135/level0.php"
data_vote = { 'id':'26', 'holdthedoor':'Submit'}

if __name__ == "__main__":
    for i in range(0, 1024):
        requests.post(url, data=data_vote)
        print("[*] Se a enviado Peticion {}".format(i))
        os.system("clear")
