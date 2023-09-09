typedef struct single_linked_list {
       struct single_linked_list *next; 
       int data;
} SLLNode;

typedef struct sll_header {
        SLLNode *next;
} SLLHeader;

#define SLLTAIL(n) ((n)->next == NULL ? 1 : 0)


void init_sll(SLLHeader *head , size_t len) {
        SLLNode *cur_node = head->next; 
        for (int i = 0; i < len; i++) {
                SLLNode *node = (SLLNode *)malloc(sizeof(SLLNode));
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


#define QCAP ARRSZ
#define icr(i) (((i)+1)%QCAP)
#ifdef TAG 
#define QSZ QCAP + 1
#define MAYBEMPTY false
#define MAYBFULL true
#define v2BFull(q) (icr((q)->rear)==(q)->front)
#define EMPTY(q) (((q)->rear == (q)->front) && (q)->tag == MAYBEMPTY)
#define FULL(q) (((q)->rear == (q)->front) && (q)->tag == MAYBFULL)
#else
#define QSZ QCAP
#endif


typedef struct arr_queue {
        int q[QSZ];
        int rear_idx;
        int front_idx;
#ifdef TAG
        bool tag;
#endif
} arrq;

typedef struct queue_node {
        int data;
        struct queue_node *next; 
} slqnode;

typedef struct single_linked_queue {
        slqnode *rear; 
        slqnode *front;
        size_t len;

} slq;


typedef struct BiTreeNode {
        int data;
        struct BiTreeNode *left;
        struct BiTreeNode *right;
} btnode;



