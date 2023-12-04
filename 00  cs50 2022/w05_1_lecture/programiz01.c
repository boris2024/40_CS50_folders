#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<cs50.h>

// this program is a transcription from programiz.  My first linked list ! :-)

struct node
{
    int data;
    struct node * next;
};

typedef struct node people;


int main (void)
{
/*initialize each node, each node is a pointer structure with 2 fields*/

    people * head= NULL;
    people * one= NULL;
    people * two= NULL;
    people * three= NULL;

/* allocate memory for each node */

one =   malloc(sizeof(people));
two=    malloc(sizeof(people));
three=  malloc(sizeof(people));

/* fill values for data field in each node */

one->data = 10;
two->data = 20;
three->data = 30;

/* connect nodes using the next field in each one */

head = one;
one->next = two;
two->next = three;
three->next = NULL;

// p is a pointer of type node, with 2 fields
people * p;

p=head;

printf("\nptr head address is \n%p",head);
printf("\n");
printf("\nptr one address is \n%p",one);

while(p!=NULL)
{   printf("\n");
    printf("\nnode address is %p",p);
    printf("\np-> data: %d",p->data);
    printf("\np-> next: %p",p->next);
    p=p->next;
}

printf("\n");

}