#include "../defs.h"

#define SLLLEN 31
#ifdef RANGE
#define MAXNUM RANGE
#else
#define MAXNUM INT_MAX
#endif

#define ZERO_OFFSET ceil(MAXNUM / 2)
#define NOT_PRESENT '0'
#define PRESENT '1'
#define delnext(n) \
                if ((n)->next != NULL) {\
                        (n)->next = (n)->next->next;\
                        free((n)->next;)\
                }\
                
                

char mapping[MAXNUM] = {0};

int
main()
{
        // Still: Space -> Time!
        // Mapping makes fast
        //
        SLLHeader * head = (SLLHeader *)malloc(sizeof(SLLHeader));
        SLLNode *node = head->next;
        memset(mapping, NOT_PRESENT, MAXNUM);
        while (!SLLTAIL(node->next)) {
                int num = node->next->data;
                if (mapping[num + ZERO_OFFSET] == PRESENT) {
                       delnext(node) ;
                } else {
                        mapping[num + ZERO_OFFSET] = PRESENT
                }
        }
}
