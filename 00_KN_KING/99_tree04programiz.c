#include<cs50.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>

/*
the purpose of this program is to create a binary tree, depth=3, and traverse it
we need to
a. create nodes, create user defined fxn
b. insert nodes, create user defined fxn
c. traverse nodes, create user defined fxn
*/

//first, the structure is defined

struct nodex
{
    int id;
    struct nodex * left;
    struct nodex * right;
};

typedef struct nodex node;


// second, write fxn to create a node

node* createnode (int number)
{   node * newnode= malloc(sizeof(node));
    newnode ->id= number;
    newnode ->left= NULL;
    newnode ->right= NULL;

    return newnode;
}

// third, write fxn to insert nodes, left and right

node * insertleft(node* root, int number)
{
        root->left = createnode(number);
        return root->left;
}

node * insertright (node * root, int number)
{
        root->right = createnode(number);
        return root->right;
}


// fourth, write fxn to traverse the tree
void traversefxn (node * root)
{   if (root==NULL){return;}
    printf("\nnode id = %d\n", root->id);
    traversefxn(root->left);
    traversefxn(root->right);
}


int main(void)
{
node * root=createnode(50);

root->left = insertleft(root, 15);
root->right = insertright(root, 35);

(root->left)->left=

traversefxn(root);

}