#include<cs50.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

// aim: change array size using realloc

int main(void)
{
    int * list = malloc (3 * sizeof(int));

    if (list == NULL)
        {   printf("\nERROR, memory not allocated\n");
            return 1;   }

    list[0]=1;
    list[1]=2;
    list[2]=3;

// resize list to be of size 4

    int * temp = realloc (list, 4*sizeof(int));

    if (temp==NULL)
        {
            printf("\nERROR, memory not allocated\n");
            return 1;
        }

    list = temp;

   list[3]=4;

   for(int i=0; i<4; i++)
   {
        printf("\nlist[%d]= %d", i, list[i]);
   }

    free(list);

}