#include "../defs.h"

#ifndef ARRSZ
#define ARRSZ 7
#endif

#define RANGE 31
#define PRESENT 1
#define MISS 0 

int
main()
{
        int array[ARRSZ];
        random_init_arr(array, RANGE, ARRSZ);
        int *table = (int *)malloc(sizeof(int) * RANGE);
        memset(table, MISS, sizeof(int) * RANGE);
        dbga(array);
        
        int min = 1;

        for (int i = 0; i < ARRSZ; i++ ) {
                if (array[i] > 0) table[array[i]] = PRESENT;
        }
        
        for (int i = 0; i < RANGE; i++) {
                if (table[i] == PRESENT) {
                        printf("answer: %d\n", i - 1);
                        break;
                }
        }
        
        DONE
}
 
