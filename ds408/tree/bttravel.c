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
        =        
}
