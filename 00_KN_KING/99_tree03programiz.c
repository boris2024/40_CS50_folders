#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

// this is a version of a program from programiz to create and traverse a tree
// each node must have 2 children, left and right

// before writing MAIN, write 3 user defined fxns
//  a. to create nodes
//  b. to insert nodes
//  c. to traverse tree nodes

// first, define the structure and use typedef

struct nodeinfo
{
    int id;
    struct nodeinfo * left;
    struct nodeinfo * right;
};

typedef struct nodeinfo node;


// a. fxn used to create nodes

node * createnode (int number)
{
    node * newnode = malloc(sizeof(node));
    newnode -> id = number;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

// b. fxn used to insert node, left and right

node * insertleft(node * root, int number)
{
    root->left =createnode(number);
    return root->left;
}

node * insertright (node * root, int number)
{
    root->right= createnode(number);
    return root->right;
}


// c. fxn to traverse the tree and print the id of each node

void traverse(node * root)
{
    if (root==NULL){return;}
    printf("\nnode->id = %d\n\n",root->id);
    traverse(root->left);
    traverse(root->right);

}



int main(void)
{
    node * root = createnode(10);

    insertleft (root, 5);
    insertright (root, 15);


}