#include<cs50.h>
#include<stdio.h>
#include<string.h>

void swap(int *n1, int *n2);

int main (void)
{
    int num01=5;
    int num02=100;

    //!  address of num01 and num02 is passed to swap function

    printf("\nnum01=%i",num01);
    printf("\nnum02=%i",num02);
    printf("\n");

    //!  what is stored in var num01 and num02 is swapped,
    //! swap fxn does not send any data back to MAIN
    swap( &num01, &num02);

    printf("\nnum01=%i",num01);
    printf("\nnum02=%i",num02);
    printf("\n");

}

void swap (int*n1,int*n2)
{
int temporary;
temporary=*n1;
*n1=*n2;
*n2=temporary;
}