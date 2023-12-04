#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//!  this is an example of call by reference,
//!..the actual address of the variable in memory is passed to the function

void swap(int*x, int*y)
{
    int temp=0;
    printf("\n");
    printf("\nbefore, inside swap fxn temp = %p",&temp);
    printf("\nbefore, inside swap fxn x    = %p",x);
    printf("\nbefore, inside swap fxn y    = %p",y);
    printf("\n");

    temp=*x;
    *x=*y;
    *y=temp;

    printf("\nafter, inside swap fxn temp = %p",&temp);
    printf("\nafter, inside swap fxn x    = %p",x);
    printf("\nafter, inside swap fxn y    = %p",y);
    printf("\n");
}


int main(void)
{   int x=12;
    int y=2345;

    printf("\n&x before= %p",&x);
    printf("\n&y before= %p",&y);

    printf("\nx=%i\ny=%i\n",x,y);

    swap(&x,&y);

    printf("\n&x after= %p",&x);
    printf("\n&y after= %p",&y);

    printf("\nx1=%i\ny1=%i\n",x,y);

    printf("\n");
}