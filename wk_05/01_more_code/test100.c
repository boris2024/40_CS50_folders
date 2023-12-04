#include<stdio.h>
#include<stdlib.h>

// 20230530, source: https://stackoverflow.com/questions/59537801/forward-chaining-a-linked-list-in-c

// this technique is called foward chaining,
// you stitch the linked list as the FOR or WHILE loop iterates
// in this case we use 3 pointers

// this is used to APPEND (add nodes at the end of existing linked list)

struct node
{
    int data;
    struct node *next;
};

int main(void)
{
    // declare 2 pointer variables
    struct node *prev=NULL;
    struct node *p=NULL;

    int n,i;

    printf("  ENTER number of nodes to link :");
    scanf("%d",&n);

    // this is the 3rd pointer variable
    struct node *head=NULL;

    for(i=0; i<n; i++)
    {
        p=malloc(sizeof(struct node));

        printf(" Enter value for node %d: ",(i+1));
        scanf("%d",&p->data);

        p->next=NULL;

        // for the 1st node
        if(head==NULL){ head=p; }

        else
        {   prev->next=p;   }

        //this sets the address assigned to pointer var prev for next iteration
        prev=p;
    }


    struct node *ptr;
    ptr=head;

    while(ptr!=NULL)
    {
        printf("\nnode address %p\nnode->value= %d\nnode->next= %p\n",ptr,ptr->data,ptr->next);

        ptr=ptr->next;
    }


}// MAIN ends here