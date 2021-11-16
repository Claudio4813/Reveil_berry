#!/bin/bash

# this script will install the Reveil_Berry version 
# https://claudio4813.github.io/Reveil_berry/

echo "installation du Reveil_Berry"

sudo apt-get update
sudo apt-get -y install xterm
sudo apt-get -y install build-essential

cd
mkdir -p /home/ISEN/Reveil_Berry/{bin,src}

tar -xzvf Reveil_Berry.tar.gz -C /home/ISEN/Reveil_Berry/src


gcc Reveil_Berry/src/main.c -o Reveil_Berry/bin/main -Wall
gcc Reveil_Berry/src/reveil.c -o Reveil_Berry/bin/reveil -Wall
gcc Reveil_Berry/src/chrono.c -o Reveil_Berry/bin/chrono -Wall
gcc Reveil_Berry/src/affchro.c -o Reveil_Berry/bin/affchro -Wall
gcc Reveil_Berry/src/MinP.c -o Reveil_Berry/bin/MinP -Wall
gcc Reveil_Berry/src/MinF.c -o Reveil_Berry/bin/MinF -Wall


echo "S'il n'y a pas de message d'erreur, vous pouvez fermer le terminal. Sinon merci de contacter l'équipe Technique"

cd Reveil_Berry/bin
./main