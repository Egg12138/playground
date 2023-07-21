#!/usr/bin/bash

echo "Starting time: $(date)"
echo "\n running $0... pid $$"

for pattern in "$@";
do 
    rg file > /dev/null 2> /dev/null
    # rediret into /dev/null
    if [[ $? -ne 0 ]]; then
        echo "No such a pattern '$pattern' in this direcotry"
        echo "# $pattern " >> "log.$pattern"
    fi
done

for 


