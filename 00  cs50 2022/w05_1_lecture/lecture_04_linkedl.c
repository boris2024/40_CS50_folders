#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<cs50.h>

struct node
{
    int number;
    struct node * next;
};

typedef struct node node;


int main (void)
{
// list of size 0

node  * list = NULL;

//printf("\n%p\n",list);
//int x=sizeof(list);
//printf("\n%d\n",x);

// add number to list, dynamically

node * n = malloc(sizeof(node));

// check if pc ran out of memory
if (n==NULL)    {   printf("ERROR, memory not allocated");
                    return 1;   }

n->number=1;
n->next=NULL;

printf ("\naddres of n1 in memory is = %p\n", n);

// all fields from n are passed on to list
list = n;

// add number to list
n= malloc(sizeof(node));

if (n==NULL)    {   printf("ERROR, memory not allocated");
                    free(list);
                    return 1;   }

n->number=2;
n->next= NULL;

printf ("\naddres of n2 in memory is = %p\n", n);

list ->next = n;  // why ??

// add another number to list
n=malloc (sizeof(node));

if (n==NULL){   printf("ERROR, memory not allocated");
                free(list->next);
                free(list);
                return 1;   }

n->number= 3;
n->next= NULL;

(list->next)->next = n;

printf ("\naddres of n3 in memory is = %p\n", n);

// print list, use this FOR as algorithm to print values in sll nodes

for (node * tmp= list; tmp!= NULL; tmp= (tmp->next))
{
    printf("\n%i\n", tmp->number );
}

// free list

while (list!=NULL)
{
    node * tmp = list->next;
    free(list);
    list=tmp;
}

return 0;

}