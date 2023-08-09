#include "play.h"

int
main()
{
        int x, z;
        short y;
        x = 127;
        y = -9;
        z = x + y;
        printf("x=%x,y=%x,z=%x\n", x, y, z);
        unsigned short a = 65530;
        unsigned int b = a;
        printf("a=%x,b=%x\n", a, b );
        return 0;
}

