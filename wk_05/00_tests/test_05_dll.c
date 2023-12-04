#include<stdio.h>
#include<stdlib.h>

// 20230521 https://www.programiz.com/dsa/linked-list-types

// from programiz, douly linked list example

    struct node
    {
        int data;

        struct node *previous;

        struct node *next;
    };

int main(void)
{
    // create and initialize nodes

    struct node *head=NULL;
    struct node *one=NULL;
    struct node *two=NULL;
    struct node *three=NULL;

    // allocate memory for each node

    one=malloc(sizeof(struct node));
    two=malloc(sizeof(struct node));
    three=malloc(sizeof(struct node));


    // fill the data field of each node
    one->data=1;
    two->data=2;
    three->data=3;


    // connect the nodes

    // note here one->previous points to NULL
    one->previous=NULL;
    one->next=two;

    two->previous=one;
    two->next=three;

    three->previous=two;
    three->next=NULL;

    head=one;


}// END of MAIN