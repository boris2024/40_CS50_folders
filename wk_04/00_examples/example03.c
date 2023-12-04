#include<cs50.h>
#include<stdio.h>

// purpose: swap two int using pointers

void swap(int *a, int *b);

int main(void)
{

    int x=get_int("enter value of x: ");
    int y=get_int("enter value of y: ");

    printf("\nx= %d , &x = %p\ny= %d, &y= %p", x, &x, y, &y);

    printf("\n\nswap fxn runs\n");

    swap(&x,&y);

    //printf("\nx= %d and y= %d\n", x,y);

    printf("\nx= %d , &x = %p\ny= %d, &y= %p\n", x, &x, y, &y);

}

void swap(int *a, int *b)
{
    // here we should swap the values, not the addresses

    int tmp=1;

    //printf("\npointer a1= %p\npointer b1= %p\n", a, b);
    //printf("\n *a1= %d", *a);

    tmp=*a;
    *a=*b;
    *b=tmp;

    //printf("\npointer a2= %p\npointer a2= %p\n", a, b);

}