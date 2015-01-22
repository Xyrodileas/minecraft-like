#!/bin/bash

if [[ $# -eq 1 ]]
then
	goto=$1
else
	goto=.
fi

find $goto -name \*~ -exec rm \-fv {} \;
find $goto -name \*.o -exec rm \-fv {} \;
