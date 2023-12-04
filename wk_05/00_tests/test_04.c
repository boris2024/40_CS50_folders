#include<stdlib.h>
#include<stdio.h>

// 20230520  learning about linked lists, https://www.programiz.com/dsa/linked-list-operations

// this is an example of hot to TRAVERSE a linkedin list

struct node
{
    int data;
    struct node *next;
};


int main(void)
{
    // initialize nodes, declare the address for each node, initially all set to NULL

    struct node *head=NULL;         struct node *one=NULL;

    struct node *two=NULL;          struct node *three=NULL;

    struct node *four=NULL;

    // allocate memory for each node, except for the head ??

    // REMEMBER : since an address was allocated for this type to a
    // certain pointer, then you have access to the fields of this data type

    // remember to check for NULL

    one=malloc(sizeof(struct node));
    two=malloc(sizeof(struct node));
    three=malloc(sizeof(struct node));
    four=malloc(sizeof(struct node));

    // assign data values, use the pointer who has received a memory address
    // since it has gotten a memory address, you have access to the fields of the data type

    one->data=1;    two->data=2;    three->data=3;      four->data=4;

    // connect nodes

    head=one;
    one->next= two;             two->next= three;
    three->next= four;          four->next= NULL;

    // save address of the first node in pointer head

    struct node *temp=NULL;

    temp=head;

    printf("\nThe elements that make up the linked list are...\n");

    printf("\nnode head address= %p\nnode one address= %p\n",head,one);

    while(temp!=NULL)
    {
        printf("\nnode address = %p\nnode data= %d\nnext node address = %p\n", temp,temp->data,temp->next);

        temp=temp->next;
    }

    //free(one);
    //free(two);
    //free(three);
    //free(four);

}

/*
    printf("\n00 address of node head = %p\n",head);
    printf("\n01 address of node one = %p\n",one);
    printf("\n02 one->next = %p\n",one->next);
    printf("\n03 address of node four = %p\n",four);
    printf("\n04 address of four->next = %p\n", four->next);
    printf("\n05 address of node two = %p\n", two);
    printf("\n06 address of two->next = %p\n", two->next);
    printf("\n07 address of node three = %p\n",three);
    printf("\n08 address of three->next = %p\n",three->next);


*/