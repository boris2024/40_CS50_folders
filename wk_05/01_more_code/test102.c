#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>

// 20230601 example code to APPEND nodes to linked list

typedef struct node
{
    int value;
    struct node *next;
}node;

int main(int argc, char *argv[])
{

    node *list=NULL;

    for(int i=1; i<argc; i++)
    {
        // convert argument to int
        int number = atoi(argv[i]);

        // allocate memory for node

        node *n=malloc(sizeof(node));

        if(n==NULL)
        {
            printf("ERROR allocating memory for node");
            return 1;
        }

        n->value=number;
        n->next=NULL;

        // this is where the difference begins, prepending vs appending
        // if the list is empty the pointer list points to NULL

        if(list==NULL)
        {
            // this statement makes pointer list and n, both point to the recently obtained address
            // the new node is the whole list
            list=n;
        }

        // if the list has more than 1 node
        else
        {
            // iterate over nodes in list
            for(node *ptr=list; ptr!=NULL; ptr=ptr->next)
            {
                // if at end of list
                if(ptr->next==NULL)
                {
                    // append node
                    ptr->next=n;
                    break;
                }
            }

        }
    }

    node *ptr=list;

    node *auxiliary=NULL;

    while(ptr!=NULL)
    {
        printf("\nnode address: %p\nnode value: %d\nnode next address: %p\n",ptr,ptr->value,ptr->next);

        auxiliary=ptr->next;
        free(ptr);
        ptr=auxiliary;
    }


}// MAIN ends here