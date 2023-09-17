#include "../defs.h"

static size_t wpl = 0;  

#define isleaf(n) \
        (((n)->left == NULL) && ((n)->right == NULL))

size_t wplof(wbtnode *root) {
        if (root) {
                if (!isleaf(root)) return (root->weight + wplof(root->left) + wplof(root->right));
        }  else return 0;
}

int
main()
{
        wbtnode *root = (wbtnode *)malloc(sizeof(wbtnode));
        test_linked_bitree(root);
        wpl = wplof(root);
        dbgl(wpl);
        return 0;
       
}
 
 
