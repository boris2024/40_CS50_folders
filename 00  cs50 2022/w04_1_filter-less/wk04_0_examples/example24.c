#include <stdlib.h>
#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void)
{   //int n;
    int* arrayPtr;

    arrayPtr = (int *)malloc(10 * sizeof(int));

    //arrayPtr=&n;

    printf("\nsize of arrayPtr = %lu\n",sizeof(arrayPtr));

    if(arrayPtr==NULL)
    {   printf("\nnot enough memory available\n");
        return 1;
    }

    free(arrayPtr);
}

