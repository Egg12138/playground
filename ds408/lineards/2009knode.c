#include "../defs.h"
#define SLLLEN 16

int
main(int argc, char *argv[])
{
        int k = atoi(argv[1])        ;
        (SLLHeader *) head = (SLLHeader *)malloc(sizeof(SLLHeader));
        init_sll(head, SLLLEN); // actually we don't know the valu eof SLLLEN
        int taili = k; 
        int targeti = 0;
        
        SLLNode * tailnode = tosll(head, tail);
        SLLNode * targetnode = tosll(head, targeti);

        while (!SLLTAIL(tailnode))  {
                targeti++; taili++;
                tailnode = tosll(head, tail);
                targetnode = tosll(head, targeti);
        }

        // start to tarvel the n-k, n-(k-1), n-(k-2), ...n - (k-k)
        for (; targeti != taili; targeti++) {
                printf("%d->",targetnode->data);
                targetnode = targetnode->next;
        }

        puts("\n");

        DONE
}
