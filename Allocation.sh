#!/bin/bash

#dans l'idée d'écrire dans les fichiers protégés nous utiliserons une des commandes suivantes
#sudo bash -c 'echo "hello" > f.txt'
#or use tee
#echo "hello" | sudo tee f.txt  # add -a for append (>>)


#Pour charger les modules de programmation hardware et vérifier
#sudo modprobe msr
#tsf-geminis@tsfgeminis-Precision-7820-Tower:~$ lsmod|grep 'msr'
#
# regarder turbostat

sudo echo "MB:0=100;1=100" >> /sys/fs/resctrl/test/schemata
