#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>

// 20230601

// this code is directly from lecture 5 of cs50.
// this code PREPENDS  nodes to a singly linked list using 2 pointers
// a WHILE LOOP is used to print the nodes

typedef struct node
{
    int number;
    struct node *next;
}node;

int main(int argc, char *argv[])
{

    node *list=NULL;

    for(int i=1; i<argc; i++ )
    {
        int number=atoi(argv[i]);

        // allocate node for number

        node *n=malloc(sizeof(node));

        if(n==NULL)
        {
            printf("\nERROR allocating memory\n");
            return 1;
        }

        n->number=number;
        n->next=NULL;

        n->next=list;
        list=n;

        printf("\nat the end of iteration i= %d\nlist points to %p\nn points to %p\nn->value= %d\nn->next points to %p\n",i,list,n,n->number,n->next);
    }

    // print the list
    node *ptr;
    ptr=list;

    while(ptr!=NULL)
    {
        printf("\nnode address: %p\nnode->value: %d\nnode->next: %p\n", ptr, ptr->number, ptr->next);
        ptr=ptr->next;
    }


    while(ptr!=NULL)
    {
        // there is a reason for the order in these operations
        // if you free() the ptr node first, you lose access to the next field, hence we store this first in an auxiliary node
        // and you still nedd this address to use later for the traversal
        node *auxiliary=ptr->next;
        free(ptr);
        ptr=auxiliary;
    }



}

