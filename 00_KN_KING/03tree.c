#include<cs50.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>

// this example is from lecture 5, CS50 code examples

struct node1
{
    int number;
    struct node1 * left;
    struct node1 * right;
};

typedef struct node1 node;

// these ae fxn prototypes
void free_tree(node * root);
void print_tree(node * root);

int main(void)
{
    node * tree = NULL;

    // declare ptr n of type node
    node * n;
    n = malloc(sizeof(node));
    if(n==NULL){    printf("ERROR, memory was not allocated");
                    return 1;   }

    // fill the fields of node n
    n->number = 2;
    n->left = NULL;
    n->right = NULL;

    // now, pass the memory address from generic node "n" to tree ptr
    tree = n;

    printf("\naddress ptr n points to= %p", n);
    printf("\naddress ptr tree points to= %p", tree);
    printf("\nn -> number = %d", n->number);
    printf("\ntree -> number= %d\n", tree->number);

    printf("\n n->left = %p", n->left);
    printf("\n tree->left = %p\n", tree->left );


    // add left branch to tree

    // again we request memory using malloc

    n=malloc(sizeof(node));

    if(n==NULL)
        {   printf("\nERROR, memory was not allocated");
            free (tree);
            return 1;   }

    n->number = 1;
    n->left = NULL;
    n->right=NULL;

    // copy data from ptr n to ptr tree->left

    tree->left = n;

    printf("\naddress of ptr n = %p", n);
    printf("\naddress of ptr tree->left = %p\n", tree->left);

    printf("\nsize of node= %lu bytes\n", sizeof(node));


    // now to the other branch
    // add node number 3 to right branch, follow binary search tree order

    n=malloc(sizeof(node));

    if(n==NULL)
        {   printf("\nERROR, memory was not allocated");
            free (tree);
            return 1;   }

    n->number = 3;
    n->left=NULL;
    n->right=NULL;

    tree->right = n;

    printf("\naddress assigned to ptr n= %p", n);
    printf("\naddress assigned to ptr tree->right= %p\n", tree->right);

    print_tree(tree);

    free(tree->right);
    free(tree->left);

    free(tree);

return 0;
}

void print_tree(node * root)
{
    if(root==NULL){ return; }

    print_tree(root->left);

    printf("\n%d\n", root->number);

    print_tree(root->right);
}