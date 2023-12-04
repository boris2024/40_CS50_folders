#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 20230529 this is the linked list example from carter's section
// 25:26 in the video

typedef struct node
{
    string phrase;
    struct node *next;

}node;

#define LIST_SIZE 2


int main(void)
{

   node *list=NULL;

   // add items to list

   for(int i=0; i<LIST_SIZE; i++)
   {
        string text=get_string("\nenter phrase to store in each node: \n");

        node *n=malloc(sizeof(node));

        if(n==NULL)
        {
            printf("ERROR allocating memory");
            return 1;
        }

        n->phrase=text;

        // why take this step ?
        n->next=list;

        // with the following step the address stored in n is pasted into list,
        // they both point to same address, list is the head of the linked list
        list=n;


   }

}