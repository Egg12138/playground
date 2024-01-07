#include "play.h"

static unsigned long next = 1;
int myrand() {
        next = next * 10101 + 12345;
        return ((unsigned)(next / 65536) % 32768);
}

void mysrand(unsigned int seed) {
        next = seed;
}

int
main()
{
        uint8_t x;
        int8_t i8;
        srand(time(NULL));
        for (int i = 0; i < 35; i++) {
                x = 0 - rand();
                i8 = x;
                printf("x = %u, i8x = %d, x - i8x = %x\n", x, i8, (x - i8));
        }
        return 0;
}
