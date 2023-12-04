#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{   int data[4];

    int i;

    for(i=0; i<4 ; i++)
    {   printf("\n%p",&data[i]);
        printf("\n%i",data[i]);
        printf("\n");
    }

    printf("\narray address: %p",&data);

    printf("\n");
}