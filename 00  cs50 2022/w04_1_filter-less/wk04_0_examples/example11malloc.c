#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main (void)
{


int *ptr;       //!     the expression on this line declares ptr as a pointer
int n,i,sum=0;  //!     n,i and sum are just variables

printf("\nEnter number of elements:\n");
scanf("%i",&n);

ptr=(int*) malloc ( n * sizeof(int));

// if memory can't be allocated

if (ptr==NULL)
    {
        printf("Error! memory not allocated");
        exit(0);
    }

printf("\nEnter elements:\n");

for(i=0;i<n;i++)
{
    scanf("%i",ptr+i);
    sum=sum+*(ptr+i);
}

printf("Sum=%i\n",sum);

// free up memory

free (ptr);

return 0;

}