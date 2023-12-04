#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>

typedef struct node
{
    string phrase;
    struct node *next;

} node;


int main(void)
{
    node *n=NULL;
    node *list=NULL;

    n=malloc(sizeof(node));

    if(n==NULL)
    {
        printf("ERROR allocating memory 01");
        return 1;
    }

    n->phrase="made in USA";
    n->next=NULL;

    list=n;

    // add a second node to the list

    node *n2=malloc(sizeof(node));

    if (n2==NULL)
    {
        printf("ERROR allocating memory 02");
        return 1;
    }

    n2->phrase="made in UA";
    n2->next=n;

    list=n2;

    node *ptr;
    ptr=n2;

    while(ptr!=NULL)
    {
        printf("\nphrase: %s",ptr->phrase);
        printf("\nnode address is %p",ptr);
        printf("\nnode's next field points to: %p\n",ptr->next);

        ptr=ptr->next;
    }

    free(n);
    free(n2);


}