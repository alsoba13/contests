#!/bin/bash
if [ -z $1 ]; then
   echo "give problem as param: `basename $0` <problem>"
fi
case $1 in
    A|B|C|D|E|F|G)
        folder="$1"
        file=`echo "$1" | tr "[:upper:]" "[:lower:]"`
    ;;
    a|b|c|d|e|f|g)
        folder=`echo "$1" | tr "[:lower:]" "[:upper:]"`
        file="$1"
    ;;
    *) 
        echo unknown problem id $1
        exit -1
    ;;
esac

g++ $folder/$file.cpp -o $folder/$file
if [[ $? != 0 ]]; then
    exit -1
fi
cat $folder/$file.in | ./$folder/$file 

