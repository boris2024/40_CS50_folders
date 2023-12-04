#include<cs50.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

//this is an example of how to traverse and print the elements of a linked list

//first, to make them globally available, declare and define the structure
// use typedef to reduce length of data type

struct node1
{   int number;
    struct node1 * next;
};

typedef struct node1 node;

int main (void)
{
// declare the ptr names that represent the nodes

node * head=NULL;
node * node1=NULL;
node * node2=NULL;
node * node3=NULL;

// now, dynamically allocate memory to each pointer,
// check memory was allocated after each malloc operation
// if PC ran out of memory, then the ptr was assigned NULL address

//head = malloc(sizeof(node));
//if (head==NULL){    printf("\nERROR, pc ran out of memory\n");
//                    return 1; }

node1= malloc(sizeof(node));
if (node1== NULL) { printf("\nERROR, pc ran out of memory\n");
                    free(head);
                    return 1;   }

node2= malloc(sizeof(node));
if (node2== NULL) { printf("\nERROR, pc ran out of memory\n");
                    free(head);
                    free(node1);
                    return 1;   }


node3= malloc(sizeof(node));
if (node3== NULL) { printf("\nERROR, pc ran out of memory\n");
                    free(head);
                    free(node1);
                    free(node2);
                    return 1;   }

// assign values to each field of the structure
node1->number=10;
node2->number=20;
node3->number=30;

// connect the nodes, assign values to the next field

node1->next=    node2;
node2->next=    node3;
node3->next=    NULL;

// by definition the head ptr aims at the first node of the linked list
//head= node1;


// now, lets traverse the linked list, from beginning to end

// first, create a temporary ptr variable to be used in traverse mechanism
node * temp=NULL;

// initial condition
//temp=head;

// set up the traverse mechanism

/*
while(temp != NULL)

    {   printf("\nnode value is: %d\n",temp->number );
        temp= temp->next;
    }
*/


//free (head);


//printf("\nsize of node = %lu bytes\n", sizeof(node));
//printf("\nsize of number field = %lu bytes\n", sizeof( node1->number ) );
//printf("\nsize of ptr next field = %lu bytes\n", sizeof( node1->next )  );

node * node4=malloc(sizeof(node));

if (node4==NULL)    {   printf("\nERROR, memory was not allocated\n");
                        return 1;
                    }

node4->number= 40;

node4->next= node1;
head=node4;
temp=head;

while(temp != NULL)

    {   printf("\nnode value is: %d\n",temp->number );
        temp= temp->next;
    }

free (node1);
free (node2);
free (node3);
free (node4);

}

