#include "play.h"

int
main()
{

        uint8_t n = 0;
        uint8_t z = n - 1;
        uint8_t i = 0; 
        printf("n = %x, z = %x, i = %x\n", n, z, i);

        for (i; i <= z; i++) {
                printf("%x, ");
        }
        return 0;
}

