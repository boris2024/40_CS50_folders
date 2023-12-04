#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

// tree traversal example from programiz

struct nodea
{
    int id;
    struct nodea * left;
    struct nodea * right;
};

typedef struct nodea node;

// user defined node traversal fxn

void traverse(node * root)
{   if(root==NULL){ return; }
    printf("\nnode id = %d\n",root->id);
    traverse(root->left);
    traverse(root->right);
}

// user defined node creation fxn
node * createnode(int number)
{   node * newnode=malloc(sizeof(node));
    newnode->id= number;
    newnode->left= NULL;
    newnode->right= NULL;

    return newnode;
    
}

// now, write 2 fxns to insert left and right childs of node
node * insertleft(node * root, int number)
{
    root->left = createnode (number);
    return root->left;
}

node * insertright(node * root, int number)
{
    root->right = createnode (number);
    return root->right;
}


int main(void)
{
    node * root= createnode(10);
    insertleft(root, 5);
    insertright(root,15);

    insertleft(root->left, 6);
    insertright(root->right,16);

    traverse(root);

}

