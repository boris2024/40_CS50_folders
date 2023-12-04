#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    int celeste, *pc;

    celeste=3;
    pc=&celeste;    //! per this expression, the address of celeste and pc are the same

    printf("\n%i",celeste);
    printf("\n%i",*pc);

    *pc=35;  //!    this expression represents the assignment
             //!    of 35 to the value stored in that pointer

    printf("\n%i",*pc);
    printf("\n%i",celeste);
    printf("\n");
}