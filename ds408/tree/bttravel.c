#include "../defs.h"

void nlr(btnode *n);
void lnr(btnode *n);
void lrn(btnode *n);
void nlr_nor(btnode *n);
void lnr_nor(btnode *n);
void lrn_nor(btnode *n);

int
main()
{
         
        return 0;
}

void nlr(btnode *n) {
        if (n) {
                dgbi(n->data); 
                btnode(n->left);
                btnode(n->right);
        } 
}

void lnr(btnode *n) {
        if (n) {
                btnode(n->left);
                dbgi(n->data);
                btnode(n->right);
        } 
}

void lrn(btnode *n) {
        if (n) {
                btnode(n->left);
                btnode(n->right);
                dbgi(n->data);
        }
}

void nlr_nor(btnode *n) {
        btnode *p = n;
        initstack(s);
        while (p || !isempty(s)) {
                if (p) {
                        dbgi(p->data);
                        push(s, p);
                        p = p->left;
                } else{
                        p = pop(s);
                        p = p->right;
                }
        }
}

void lnr_nor(btnode *n) {
        btnode *p = n;
        initstack(s);
        while (p || !isempty(s)) {
                if (p) {
                push(s, p);
                p = p->left;
                } else {
                        p = pop(s);
                        dbgi(p->data);
                        p = p->right;
                }
}}

void lrn_nor(btnode *n) {
        btnode *p = n;
        initstack(s);
        btnode *recent_visited = (btnode *)malloc(sizeof(btnode));
#define NOT_ACCESS(n) ((n) != recent_visited)
        while (p || !isempty(s))  {
                if (p) {
                        push(s, p);
                        p = p->left;
                } else {
                        p = top(s);//not pop
                        if (p->right && NOT_ACCESS(p->right)) p = p->right;
                        else {
                                p = pop(s);
                                dbgi(p->data);
                                recent_visited = p;
                                p = NULL;
                        }
                }
        }
}

