#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (int *a, int *b);

int main(void)
{
    int x=21023;
    int y=10;

    printf("\n1. the address of x is: %p",&x);
    printf("\n1. the address of y is: %p",&y);

    printf("\nx= %i and y= %i\n",x,y);
    swap(&x,&y);
    printf("\nx= %i and y= %i\n",x,y);

}

void swap(int *a, int *b)
{
printf("\nvariable a address before= %p",a);
printf("\nvariable b address before= %p\n",b);

printf("\nvaribale a content before= %i", *a);
printf("\nvaribale b content before= %i\n", *b);

int temp;
temp=*a;
*a=*b;
*b=temp;

printf("\nvariable a address after= %p",a);
printf("\nvariable b address after= %p\n",b);

printf("\nvariable a address after= %i", *a);
printf("\nvaribale b address after= %i\n", *b);

}