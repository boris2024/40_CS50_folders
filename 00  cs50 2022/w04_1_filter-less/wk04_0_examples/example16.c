#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
int integers[5]={2,3,4,5,6};

int * ptr;      // here ptr has been declared as a pointer

ptr=&integers[0];

printf("\n%p",&integers[2]);
printf("\n");

printf("\n*ptr = integers[0] = %i",*ptr);
printf("\n*(ptr+1) = integers[1] = %i",*(ptr+1));
printf("\n*(ptr+2) = integers [2] = %i", *(ptr+2));
printf("\n");
}