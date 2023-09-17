#include <time.h>
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


#define QCAP 17
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

typedef struct WeightedBiTreeNode {
        int weight;
        struct WeightedBiTreeNode *left;
        struct WeightedBiTreeNode *right;
} wbtnode;

void test_linked_bitree(wbtnode *root) {
        srand(time(NULL));
        wbtnode *left = (wbtnode *)malloc(sizeof(wbtnode));
        wbtnode *right = (wbtnode *)malloc(sizeof(wbtnode));
        wbtnode *left1 = (wbtnode *)malloc(sizeof(wbtnode));
        wbtnode *left2 = (wbtnode *)malloc(sizeof(wbtnode));
        wbtnode *right1 = (wbtnode *)malloc(sizeof(wbtnode));
        wbtnode *right2 = (wbtnode *)malloc(sizeof(wbtnode));
        root->left = left;
        root->right = right;
        root->weight = rand() % 10;
        left->weight =  rand() % 10;
        right->weight = rand() % 10;
        left1->weight =  rand() % 10;
        right1->weight = rand() % 10;
        left2->weight =  rand() % 10;
        right2->weight = rand() % 10;
        //dbgi(root->weight);
        //dbgi(left->weight);
        //dbgi(left1->weight);
        //dbgi(right1->weight);
        //dbgi(right->weight);
        //dbgi(right2->weight);
        //dbgi(left2->weight);
        left->left = left1;
        left->right = right1; 
        right->right = right2;
        right->left = left2;
}

#define isleaf(n) ((n)->left == NULL && (n)->right == NULL)





