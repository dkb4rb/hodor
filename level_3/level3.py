#!/usr/bin/python3
# level1.py
# Juan Duque <3428@holbertonschool.com>
""" Import libraries """
from bs4 import BeautifulSoup
import requests
import sys
import os

user_agent = ("Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:64.0) "
              "Gecko/20100101 Firefox/64.0")

header = {
    "User-Agent": user_agent,
    "referer": ""

}


data_vote = {
    'id': '',
    'holdthedoor': 'Submit',
    'key': '', }


def banner():
    print(" ___   ___   ______   ______   ______   ______       ")
    print("/__/\ /__/\ /_____/\ /_____/\ /_____/\ /_____/\      ")
    print("\::\ \\\  \ \\\:::_ \ \\\:::_ \ \\\:::_ \ \\\:::_ \ \     ")
    print(" \::\/_\ .\ \\\:\ \ \ \\\:\ \ \ \\\:\ \ \ \\\:(_) ) )_   ")
    print("  \:: ___::\ \\\:\ \ \ \\\:\ \ \ \\\:\ \ \ \\\: __  \ \  ")
    print("   \: \ \\\::\ \\\:\_\ \ \\\:\/.:| |\:\_\ \ \\\ \ \  \ \ ")
    print("    \__\/ \::\/ \_____\/ \____/_/ \_____\/ \\_\/ \_\/ ")
    print("")
    print("[!] Project Web Scrapping Hodor")
    print("\n\t [*] Elaborado por.. Juan Duque\n")


def _errnos_1():
    os.system("clear")
    print("Conexion Interrumpida")
    print("\t\n [!] Saliendo del Programa .... ")
    exit(1)


def sending(url, uid, size):
    for i in range(size):
        os.system("clear")
        banner()
        print("\n[!] Conected url : {}\n".format(URL))
        print(
            "[*] Votando ..\n\t\t ... Your ID      ... [{}]\n\t\t ... Actual Votes ... [ {} ] ".format(uid, i + 1))
        session = requests.session()
        page = session.get(url)
        soup = BeautifulSoup(page.text, "html.parser")
        hidden_value = soup.find("form", {"method": "post"})
        hidden_value = hidden_value.find("input", {"type": "hidden"})
        data_vote["key"] = hidden_value["value"]
        data_vote['id'] = uid
        header['referer'] = url
        session.post(url=url, headers=header, data=data_vote)

    return (i)


def arrgv():
    if len(sys.argv) <= 3:
        print("\n [*] Usage: <URL> <UID> <SIZE_VOTES>")
        sys.exit(1)
    if int(sys.argv[2]) < 0:
        print("size is must be > 0")
        sys.exit(1)


if __name__ == "__main__":

    try:
        arrgv()
        URL = str(sys.argv[1])
        UID = int(sys.argv[2])
        SIZE_VOTES = int(sys.argv[3])
        ACTUAL_VOTES = sending(URL, UID, SIZE_VOTES)
        print("\n\t[ & % ] Votacion Terminada\n \t\t Total Votos [ {} ]\n".format(
            ACTUAL_VOTES + 1))
    except KeyboardInterrupt:
        _errnos_1()
