#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

// this is a fixed size array

int main (void)
{
int list [3];

list[0]=1;
list[1]=2;
list[2]=3;

int * x,y,z;

x=list;

int i;

printf("\n");

for(i=0; i<3; i++)
{
    printf("list[%d] = %d\n", i, list[i]);
    printf("pointer for list[%d]= %p\n", i, &list[i]);
}

for(i=0; i<3; i++)
{
    printf("size of list[%d] = %lu\n", i, sizeof(list[i]));
}

}