#!/usr/bin/python3
# levelo.py.py
# Juan Duque <3428@holbertonschool.com>
""" Import libraries necesary for execute program
"""
from bs4 import BeautifulSoup
import requests
import sys


url = "http://158.69.76.135/level1.php"
data_vote = {
    'id': '12',
    'holdthedoor': 'Submit',
    'key': '', }

if __name__ == "__main__":

    # requests.post(url, data=data_vote)
    ses = requests.session()
    print(ses)
    print(ses.headers)
    ses.headers['User-Agent'] = "Hola"
    print(ses.headers)
    print(ses.headers['User-Agent'])
    print(ses.hooks)
    #r = requests.get(url=url)
    #p = requests.post(url=url, data=data_vote)

    # print(data_vote['id'])
    # data_vote['key'] = "94uewud9scoxhsd9ojuhccuwbwe"
    # print(data_vote['key'])

    # print(r.text)
    # print(p.__dict__)
    print("[*] Se a enviado Peticion")
