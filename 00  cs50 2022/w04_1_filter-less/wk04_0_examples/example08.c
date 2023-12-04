#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main (void)
{
    int x[5]={1,2,3,4,5};

    int *ptr;

    ptr=&x[2];

    printf("\n*ptr=%i",x[2]);
    printf("\n*ptr=%i",*ptr);
    printf("\n");

    printf("\n*(ptr+1)=%i",*(ptr+1));
    printf("\n*(ptr+1)=%i",x[3]);
    printf("\n");

    printf("\n*(ptr-1)=%i",*(ptr-1));
    printf("\n*(ptr-1)=%i",x[1]);
    printf("\n");
}