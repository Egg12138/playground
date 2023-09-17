#include "../defs.h"
#include <ctype.h>

#define notop(n) (isoperator((n)->token))

typedef struct node {
        char token[10];
        struct node *left, node *right;
} expr_node;

bool notoperator(const char *token) {
       int i = 0;
       while (token[i] != '\0') {
               if (!isdigit(token[i]) && !isdigit(token[i])) 
                       return false;
               i++;
       }
       return true;
}



static stack *s = (stack *)malloc(sizeof(stack));

void solution(expr_node *tree) {
       show_expr(tree);
}

void lisp_expr(expr_node *root) {
        if (expr_node) {
                if (isleaf(expr_node)) {
                        printf("%s)",expr_node->token);
                        return;
                } else {
                        printf("(%s", expr_node->token);
                        lisp_expr(expr_node->left);
                        lisp_expr(expr_node->right);
                }
        }
        else return;
}
void show_expr(expr_node *root) {
        if (expr_node == NULL) return;
        if (!isleaf(root)) {
                push(s, "(");
                show_expr(expr_node->left)
        } else {
                push()
        }
}

int
main()
{
        initstack(s);

         
}
