#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<cs50.h>

struct node1
{
    int number;
    struct node1 * left;
    struct node1 * right;
};

typedef struct node1 node;

void free_tree (node * root);
void print_tree (node * root);

int main(void)
{
    // tree of size 0
    node * tree = NULL;

    // add number to list
    node * n = malloc (sizeof(node));

    if (n==NULL)    {   printf("ERROR, memory not allocated");
                        return 1;   }

    n->number= 2;
    n->left= NULL;
    n->right= NULL;

    // copy the contents of node n into ptr node tree
    tree=n;

    // add number to list
    n= malloc(sizeof(node));
    if (n==NULL){   printf("ERROR, memory not allocated");
                    free_tree(tree);
                    return 1;   }

    n->number=1;
    n->left=NULL;
    n->right=NULL;

    // this step assigns the contents of node n into the left branch of node tree
    tree->left = n;

    // add another number to list

    n=malloc(sizeof(node));
    if (n==NULL){   printf("ERROR, memory not allocated");
                    free_tree(tree);
                    return 1;   }

    n->number=3;
    n->left=NULL;
    n->right=NULL;

    // this step assigns the contents of node n into the right branch of node tree
    tree->right = n;

    // run fxn print_tree
    print_tree(tree);

    // free tree ptr, using fxn free_tree

    free_tree(tree);
    return 0;


}


void free_tree(node * root)
{   // why is this IF necessary ?
    if (root==NULL){return; }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}


void print_tree(node * root)
{
    // why is this IF necessary ?
    if (root==NULL){return; }

    print_tree(root->left);
    print_tree(root->right);

    printf("\n%d\n", root->number);

}
