#include "../defs.h"
void enq(arrq *qref, int data);
int deq(arrq *qref);


int
main()
{
        arrq qu = (arrq)malloc(sizeof(arrq));
        qu.rear_idx = 0;
        qu.front_idx = 0;
        qu.tag = MAYBFULL;
}

void enq(arrq *qref, int data) {
        if (FULL(qref)) 
                return;
        qref->q[qref->rear] = data;
        qref->rear = icr(qref->rear);
        qref->tag = MAYBFULL;
        return;
}

int deq(arrq *qref) {
        int data;
        assert(!EMPTY(qref));
        data = qref->q[qref->front];
        qref->front = icr(qref->front);
        qref->tag = MAYBEMPTY;
        return data;
}

void 
