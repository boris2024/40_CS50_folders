#include<cs50.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>

// write a program to create a tree and traverse it

// write a structure and 3 fxns to create nodes, insert nodes and traverse the tree

// a. create structure and use typef later

struct nodexx
{
    int nodeid;
    struct nodexx * left;
    struct nodexx * right;
};

typedef struct nodexx node;


// b. write fxn used to create nodes

node * createnode (int number)
{
    node * newnode = malloc(sizeof(node));

    newnode -> nodeid = number;
    newnode -> left = NULL;
    newnode -> right = NULL;

    return newnode;
}


// c. write fxn to insert nodes, left and right childs of root node

node * insertleft(int number, node * root)
{
    root->left = createnode(number);
    return root->left;   ;
}

node * insertright(int number, node * root)
{
    root->right = createnode(number);
    return root->right;
}

// d. write fxn to traverse all nodes and print node id's

void traverse(node * root)
{
    if (root==NULL){ return;}
    printf("\nnode id = %d\n", root->nodeid);
    traverse(root->left);
    traverse(root->right);
}

int main(void)
{
    node * root = createnode(150);

    insertleft(50, root);

    insertright(250, root);

    traverse(root);
}