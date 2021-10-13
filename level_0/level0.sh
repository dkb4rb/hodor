#!/bin/bash

trap ctrl_c INT

function ctrl_c(){
echo -e "\n[*] Saliendo del Programa ..."
exit 1;
}

function banner(){
echo " ___   ___   ______   ______   ______   ______       "
echo "/__/\ /__/\ /_____/\ /_____/\ /_____/\ /_____/\      "
echo "\::\ \\\  \ \\\:::_ \ \\\:::_ \ \\\:::_ \ \\\:::_ \ \     "
echo " \::\/_\ .\ \\\:\ \ \ \\\:\ \ \ \\\:\ \ \ \\\:(_) ) )_   "
echo "  \:: ___::\ \\\:\ \ \ \\\:\ \ \ \\\:\ \ \ \\\: __  \ \  "
echo "   \: \ \\\::\ \\\:\_\ \ \\\:\/.:| |\:\_\ \ \\\ \ \  \ \ "
echo "    \__\/ \::\/ \_____\/ \____/_/ \_____\/ \\_\/ \_\/ "
echo ""
echo -ne "[!] Project Web Scrapping Hodor"
echo -ne "\n\t [*] Elaborado por.. Juan Duque\n"

}

for send in $(seq 1 1024); do
	ids=3428
	curl -X POST -d "id=$ids&holdthedoor=submit" http://158.69.76.135/level0.php > /dev/null 2>&1
	clear
	banner
	echo -ne "\n[!] Tu numero de Id es: [$ids]\n"
	echo -ne "\n[!] Votando .. \n\tNum Votes [$send]"
done
echo -ne "\tFelicidades \n[!] Has Votado $send veces"
