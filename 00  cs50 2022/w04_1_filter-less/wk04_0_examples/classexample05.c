#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{   int n,i;
    int *x=&n;
    int *y=&i;

    x=malloc(sizeof(int));
    //y=malloc(sizeof(8));

    printf("\nsize of x = %lu",sizeof(x));
    printf("\nsize of y = %lu\n",sizeof(y));

    printf("\naddress of x= %p",x);
    printf("\naddress of y= %p\n",y);

    *y=13;
    *x=22;

   //y=x;        //! in this step the content of pointer x is assigned to pointer y

    printf("\naddress of x= %p",x);
    printf("\naddress of y= %p\n",y);

    //free(x);
    //free(y);

    //!  print the content of both variables, n and i

    printf("\nthe content of var n= %d\n",*x);
    printf("\nthe content of var i= %d\n",*y);

    printf("\naddress of x= %p",x);
    printf("\naddress of y= %p\n",y);

    y=x;

    printf("\nthe content of var n= %d\n",*x);
    printf("\nthe content of var i= %d\n",*y);

    printf("\naddress of x= %p",x);
    printf("\naddress of y= %p\n",y);
}