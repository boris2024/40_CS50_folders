#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

// source programiz

// the aim of this program is to learn how to traverse a tree data structure,
// namely to visit each and every node in the tree

// to achieve our goal, we must visit the root node,
// all the nodes in the left sub tree and all the nodes in the right sub tree

// you may visit all nodes in various orders

struct node1
{
    int nodeid;
    struct node1 * left;
    struct node1 * right;
};

typedef struct node1 node;

void traversefxn (node * root)
{
    if (root==NULL){ return; }
    traversefxn(root->left);
    printf("\nnode id = %d", root->nodeid);
    traversefxn(root->right);
}

// create a node
node * createnode(value)
{
node * newnode = malloc(sizeof(node));
newnode->nodeid= value;
newnode->left=NULL;
newnode->right=NULL;

return newnode;
}

// insert on the left side of node
node * insertleft (node * root, int nodeid)
{
    root->left= createnode (nodeid);
    return root->left;
}

// insert on the right side of node
node * insertright (node * root, int nodeid)
{
    root->right= createnode (nodeid);
    return root->right;
}

int main (void)
{
    node * root = createnode (1);

    insertleft (root, 12);
    insertright (root, 9);

    insertleft (root->left, 5);
    insertright (root->right, 6);

    printf("traversal order ");
    traversefxn (root);
}