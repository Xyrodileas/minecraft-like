#!/bin/bash

if [[ -d ./.build ]]
then
	if [[ -d ./.build/graph ]]
	then
		echo "graph est déjà installé patate"
	else 
		mkdir ./.build/graph
	fi
	if [[ -d ./.build/reseau/ ]]
	then
		echo "reseau est déjà installé patate"
	else
		mkdir ./.build/reseau
	fi
else
	mkdir ./.build
	mkdir ./.build/graph
	mkdir ./.build/reseau
	svn propset svn ignore "./.build" .
	svn propset svn ignore "./.build/*" .
	echo "--------------OK-------------"
fi
