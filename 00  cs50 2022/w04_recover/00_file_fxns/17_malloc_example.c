#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    int * ptr;
    int i,n;

    printf("\nenter number of elements:\n");
    scanf("%d",&n);
    printf("\nnumber of elements: %d\n",n);

    ptr=(int*)malloc(n*sizeof(int));

    if (ptr==NULL)
    {   printf("\nmemory not allocated\n"); exit (0); }

    else
    {
        printf("\nmemory allocated using malloc\n");

        // assign the elements of the array
        for(i=0; i<n; i++)
        {   ptr[i]=(i+n);   }

        // print the elements of the array

        printf("\n");
        for(i=0; i<n; i++)
        {  printf("%d ",ptr[i]); }
        printf("\n");

    }

    free(ptr);
}

