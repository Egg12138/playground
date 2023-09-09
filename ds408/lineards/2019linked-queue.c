#include "../defs.h"

void initq(slq *a);
void enslq(slq *q, int data);
int deqls(slq *q);


#define SLQEMPTY(q) ((q)->len==0)

int
main(void)
{
           
        return 0;
}

void initq(slq *q) {
        size_t rest = q->len;
        slqnode *cur_node = q->rear;
        while (rest > 0 cur_node == q->front) {
                cur_node == cur_node->next;

        }
}

void enslq(slq *q, int data) {
        slqnode *node = (slqnode *)malloc(sizeof(slqnode));
        node->data = data;
        q->rear->next = node;
        q->rear = q->rear->next;
        q->len++;
}

int deqls(slq *q) {

        assert(!SLQEMPTY(q));
        int data;
        data = q->front->data;
        q->front = q->front->next;
        q->len--;
        return data; 
}

