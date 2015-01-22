#!/bin/bash

#Permet d'eclaircir les choses avant de les debuter
clear
./pas_de_~.sh

#Compilation de tout les fichiers
make 2> .err

#Si erreurs, je les affiches
#Sinon, je lance l'executable produit
if [ $(stat --printf="%s" .err) -ne 0 ]
then
	echo -e "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nErreurs de compilation :\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
	cat .err
else

	./.build/graph/code

fi
