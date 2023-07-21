#!/usr/bin/awk -f


BEGIN {
        print "Lines containing the word 'fine':"
}

/fine/ {
        print
}
