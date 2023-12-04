#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int *x;     //! here I declare x as a pointer

    x=malloc(3*sizeof(int));

    int y=sizeof(x);

    printf("\nx= %p\n",x);
    printf("\ny= %i\n",y);

    x[1]=72;
    x[2]=73;
    x[0]=33;


    free(x);

}