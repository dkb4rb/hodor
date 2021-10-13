#!/usr/bin/python3
# Juan Duque <3428@holbertonschool.com>

from bs4 import BeautifulSoup
import sys
import requests
from requests.api import get, post

url = "http://158.69.76.135/level1.php"
data_vote = {
    'id': '43',
    'holdthedoor': 'Enviar+consulta',
    'key': 'asada7ds78f7nda8sdna8n7n8as7m', }

if __name__ == "__main__":
    session = requests.session()
    print(session.headers)
    print(session.get)

    gett = requests.get(url)
    post = requests.post(url=url, data=data_vote)
    print("\n ============== GET ============== ")
    print(gett)
    print(BeautifulSoup(gett.text))
    print("\n ============== POST =============")
    print(post)
