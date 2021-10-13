#!/usr/bin/python3
# level0.py
# Juan Duque <3428@holbertonschool.com>
""" Import libraries necesary for execute program
"""
import requests
url = "http://158.69.76.135/level1.php"
data_vote = {
    'id': '26',
    'holdthedoor': 'Submit'}

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:47.0) Gecko/20100101 Firefox/47.0',
}

if __name__ == "__main__":
    requests.post(url, data=data_vote)
    print("[*] Votando [{}]".format(i))
