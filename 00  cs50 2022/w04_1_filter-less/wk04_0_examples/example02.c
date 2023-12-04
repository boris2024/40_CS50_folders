#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    int *pc, celeste;

    celeste=3;
    pc=&celeste;

    printf("\n%i",celeste);
    printf("\n");
    printf("\n%p",pc);
    printf("\n%i",*pc);
    printf("\n");

    celeste=30;

     printf("\n%i",celeste);
    printf("\n");
    printf("\n%p",pc);
    printf("\n%i",*pc);
    printf("\n");
}