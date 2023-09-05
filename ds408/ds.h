typedef struct single_linked_list {
       struct single_linked_list *next; 
       int data;
} SLLNode;

typedef struct sll_header {
        SLL *next;
} SLLHeader;

#define SLLTAIL(n) ((n)->next == NULL ? 1 : 0)


void init_sll(SLLHeader *head , size_t len) {
        SLLNode *cur_node = head->next; 
        for (int i = 0; i < len; i++) {
                SLLNode *node = (SLL *)malloc(sizeof(SLL));
                node->data = 0; 
                node->next = NULL;
                cur_node->next = node;
                cur_node = cur_node->next;
        }
}

int tosll(SLLHeader *head, int idx) {
        SLLNode *node = head->next;
        for (int i = 0; i < idx && node != NULL; i++) 
                node = node->next;
        
        return node->data;
}
