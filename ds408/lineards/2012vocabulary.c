#include "../defs.h"

#define offset(l1, l2) abs(l1-l2)
int
main()
{

        // puesoCode:
        SLLHeader *str1 = (SLLHeader *)malloc(sizeof(SLLHeader)); 
        SLLHeader *str2 = (SLLHeader *)malloc(sizeof(SLLHeader)) ;
        allocate();//....
        SLLNode * node1 = str1->next;
        size_t restlen1 = 23;
        SLLNode * node2 = str2->next;
        size_t restlen2 = 13;
        size_t bias = offset(restlen1, restlen2); 
        allocate();
        longer = (restlen1 > restlen2 ? node1 : node2);
        shorter = (restlen1 > restlen2 ? node2 : node1);
        for (; bias>0; bias--)                 
               longer = longer->next;         
        #define NOT_CONSISTENT (shorter != longer)
        while (NOT_CONSISTENT && NOT_TAIL) {
                // 轮流
                if (bias == 1) {
                        shorter = shorter->next;
                }  else {
                        // bias == -1
                        longer = longer->next;
                }
                bias = 0 - bias;
        }


        DONE
}
