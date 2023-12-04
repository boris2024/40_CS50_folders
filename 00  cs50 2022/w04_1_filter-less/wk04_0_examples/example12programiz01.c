#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    int data[5];
    printf("\nEnter elements:\n");

    //!  in this expression we scan and stored each value into the int array (data+i)
    for(int i=0; i<5; i++)
    {   scanf("%i", data+i);    }


    printf("\nYou entered: \n");

    //! in this expression we use pointer *(data+i) to print the values stored
    for(int i=0; i<5; i++)
    {   printf("\n%i",*(data+i));   }

    printf("\n");

}