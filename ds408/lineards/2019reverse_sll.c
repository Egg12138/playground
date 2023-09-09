#include "../defs.h"

void reverse(SLLHeader *head);
int
main(void)
{
        //        
        return 0;
}

void reverseO1(SLLNode *seg_header, SLLNode *seg_node) {
        // required space complexity: O(1) !
        SLLNode *rest = (SLLNode *)malloc(sizeof(SLLNode));
        seg_header = NULL;
        while (seg_node->next != NULL){
                rest = seg_node->next;
                seg_header->next->next = seg_header->next;
                seg_hedaer->next = rest;
                seg_node = rest;
        }
}

void reverseOn(SLLNode *new_seg_header, SLLNode *seg_node) {
        // new segment of sll has been initialized
        while (seg_node->next) {
                new_seg_header->next->next = new_seg_header->next;
                new_seg_header->next = seg_node;
                seg_node = seg_node->next;
        }
}
