#!/bin/bash

# this script will install the Reveil_Berry version 
# https://claudio4813.github.io/Reveil_berry/

echo "installation du Reveil_Berry"

###
# Essai de creation automatique du profil User ISEN --> No success
#
# sudo useradd ISEN --create-home -U --shell /bin/bash
# sudo passwd ISEN
# su ISEN
#
###

sudo apt-get update
sudo apt-get -y install xterm
sudo apt-get -y install build-essential
sudo apt install sox

cd
mkdir -p Reveil_Berry/{bin,src}

tar -xzvf Reveil_Berry.tar.gz -C /home/ISEN/Reveil_Berry/src

gcc /home/ISEN/Reveil_Berry/src/main.c -o /home/ISEN/Reveil_Berry/bin/main -Wall
gcc /home/ISEN/Reveil_Berry/src/reveil.c -o /home/ISEN/Reveil_Berry/bin/reveil -Wall
gcc /home/ISEN/Reveil_Berry/src/chrono.c -o /home/ISEN/Reveil_Berry/bin/chrono -Wall
gcc /home/ISEN/Reveil_Berry/src/affchro.c -o /home/ISEN/Reveil_Berry/bin/affchro -Wall
gcc /home/ISEN/Reveil_Berry/src/MinP.c -o /home/ISEN/Reveil_Berry/bin/MinP -Wall
gcc /home/ISEN/Reveil_Berry/src/MinF.c -o /home/ISEN/Reveil_Berry/bin/MinF -Wall
cp /home/ISEN/Reveil_Berry/src/mon.sh home/ISEN/Reveil_Berry/bin/mon.sh
cp /home/ISEN/Reveil_Berry/src/pan.wav home/ISEN/Reveil_Berry/bin/pan.wav



echo "S'il n'y a pas de message d'erreur, vous pouvez fermer le terminal. Sinon merci de contacter l'équipe Technique"

cd Reveil_Berry/bin
./main
