#include "../defs.h"

#define isleaf(n) ((n)->left == NULL && (n)->right == NULL)
static size_t WPL = 0;
size_t wpl_of(wbtnode *root, size_t depth) {
        assert(root != NULL);
        depth++;
        if (isleaf(root)) return depth * root->weight;
        else return (wpl_of(root->left, depth) + wpl_of(root->right, depth));
}
int
main()
{
        wbtnode *root = (wbtnode *)malloc(sizeof(wbtnode));
        test_linked_bitree(root);
        WPL = wpl_of(root, 0);
        dbgi(WPL);

        return 0;
}
 
