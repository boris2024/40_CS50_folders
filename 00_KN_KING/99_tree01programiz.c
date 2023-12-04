#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

struct node1
{   int nodeid;
    struct node1 * left;
    struct node1 * right;
};

typedef struct node1 node;

// these is the traverse fxn
void preordertraverse(node * root)
{
    if (root==NULL) return;
    else
    {
        printf("\nnodeid = %d\n", root->nodeid);
        preordertraverse(root->left);
        preordertraverse(root->right);
    }
    
}

// create node fxn
node * createnode (value)
    {
        node * newnode = malloc (sizeof(node));

        newnode->nodeid=value;
        newnode->left=NULL;
        newnode->right=NULL;

        return newnode;
    }

// insert left field fxn

node * insertleft(node * root, int value)
{
    root->left = createnode (value);
    return root->left;
}

node * insertright(node * root, int value)
{
    root->right = createnode (value);
    return root->right;
}



int main(void)
{
node * root = createnode(1);
insertleft(root,12);
insertright(root, 9);

insertleft(root->left, 5);
insertright(root->right,6);

preordertraverse(root);


}