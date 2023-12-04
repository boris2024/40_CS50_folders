#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    int *x=malloc(3*sizeof(int));

    x[0]=112;
    x[1]=223;
    x[2]=321;

    printf("\nx= %p",x);
    printf("\nx= %p",&x[0]);
    printf("\nx= %p",&x[1]);
    printf("\nx= %p",&x[2]);
    printf("\n");

    free(x);

}