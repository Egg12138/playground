#include "../defs.h"
#include <math.h>// using `ceil`

#define midi(len) floor(len/2) //indexing
#define midpos(len) ceil(len/2) //position = idx + 1
#define max(a) (a)[ARRSZ - 1]
#define min(a) (a)[0]
#define greater_one(a,b) ((a) > (b) ? a : b)

// the lower, higher means lower or hight in the first element
void comparing(int start_lower[], int start_higher[]) {
        assert(lenof(lower) == lenof(higher));
        size_t cnt = 0; 
        size_t cnt_target = midpos(lenof(lower));
        int lo = start_lower;
        int ilo = 0;
        int ihi = 0;
        int hi = start_higher;
        while (cnt < cnt_target) {
                if (lo[ilo] <= hi[ihi]) {
                        cnt++;
                        ilo++;
                } else {
                        swap(lo, hi);
                        swap(ilo, ihi);
                }
        }
}

int
main()
{
        int a1[ARRSZ];
        int a2[ARRSZ];
        random_init_arr(a1);
        random_init_arr(a2);

        int max1 = max(a1);
        int max2 = max(a2);
        int min1 = min(a1);
        int min2 = min(a2);

        if (max1 <= min2 || min1 >= max2)
                printf("answer: %d", greater_one(min2, min1));
        else {
                size_t counter = 0;


        }
        

        DONE
}


