#!/usr/bin/zsh

for file in $(ls ..) 
do
    echo $file
done

arg=$1
echo $arg
echo $($arg)

