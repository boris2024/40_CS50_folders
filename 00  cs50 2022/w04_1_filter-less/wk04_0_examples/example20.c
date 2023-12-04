#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main (void)
{
    int value=0;

    //! int *pointer=5; this statement is wrong, why? Because you can't assign an int to a pointer.

    //! this statement is correct, I'm storing the address of variable "value" inside pointer "pointer"
    int *pointer=&value;

    //! in this statement I assign the variable "value" to the dereferenced pointer.
    //! the expression *pointer  works as a variable
    *pointer=value;

    printf("\n%lu\n",sizeof(*pointer));
}