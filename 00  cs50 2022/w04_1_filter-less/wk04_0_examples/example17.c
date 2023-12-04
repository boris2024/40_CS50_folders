#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//!  this is an example of call by value,
//!..by passing a copy of a variable from MAIN to the function

void swap(n1, n2)
{   int temp=0;

    printf("\nbefore swap, inside fxn, temp = %p",&temp);
    printf("\nbefore swap, inside fxn, n1   = %p",&n1);
    printf("\nbefore swap, inside fxn, n2   = %p",&n2);

    printf("\n");
    printf("\nbefore swap, inside fxn, temp = %d",temp);
    printf("\nbefore swap, inside fxn, n1   = %d",n1);
    printf("\nbefore swap, inside fxn, n2   = %d",n2);
    printf("\n");

    temp=n1;
    n1=n2;
    n2=temp;

    printf("\nafter swap, inside fxn, temp = %p",&temp);
    printf("\nafter swap, inside fxn, n1   = %p",&n1);
    printf("\nafter swap, inside fxn, n2   = %p",&n2);

    printf("\n");
    printf("\nafter swap, inside fxn, temp = %d",temp);
    printf("\nafter swap, inside fxn, n1   = %d",n1);
    printf("\nafter swap, inside fxn, n2   = %d",n2);
    printf("\n");

}

int main(void)
{   int x, y;
    x=12;
    y=3397;

    printf("\n&x before= %p",&x);
    printf("\n&y before= %p",&y);

    printf("\nx=%i\ny=%i",x,y);
    printf("\n");

    swap(x,y);

    printf("\n&x after= %p",&x);
    printf("\n&y after= %p",&y);

    printf("\nx=%i\ny=%i",x,y);
    printf("\n");

}