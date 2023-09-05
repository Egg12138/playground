#include "../defs.h"
#define ARRSIZE 11

int arr[ARRSIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

void random_arr() {
        //TODO:
}



/*
 * 0,1, ..., p-1, p, ... N;前一段长度p, 后一段长度q = N - p;
 * 实际上只要做到映射: 
 * p, ..., N => 0, 1, ... q;
 * 0...p-1  => q, q+1, ..., q+p-1 = N - 1;
 */
int
main(int argc, char *argv[]) 
{
        
        u32 p = atoi(argv[1]);
        assert(p < ARRSIZE);
        #define backward (ARRSIZE - p)
        #define new_idx(i) ((i > (p-1) ? (i - p) : (i + backward) ))
        int new[ARRSIZE] = {0};
        for (int i = 0; i < ARRSIZE; i++) {
                printf("%d -> %d\n", i, new_idx(i));
                new[new_idx(i)] = arr[i];
        }
        //dbga(arr);
        dbga(new);
        
        DONE
}
