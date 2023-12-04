#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;


int main(int argc, char *argv[])
{
    // memory for numbers

    node *list;
    list = NULL;

    // for each command line arguments you enter, do this

    for(int i=1; i<argc; i++)
    {
        // convert argument to int
        int number = atoi(argv[i]);

        // allocate node for number

        node *n;
        n=malloc(sizeof(node));

        if(n==NULL)
        {
            printf("ERROR assigning memory");
            return 1;
        }

        // number is an argument received through CLI and cnverted from "string" to int
        // n->number is a field of the struct, since n is a node of type node
        n->number= number;

        // the field next is set to point to NULL
        n->next=NULL;




    }




}