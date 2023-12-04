#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main (void)
{
    int n;
    int arr[100];

    printf("\nEnter number of elements (1 to 100):\n");

    scanf("%i",&n);

    for(int i=0; i<n; i++)
    {
        printf("\nEnter element %i: ",i+1);
        scanf("%i",&arr[i]);
    }


    for(int i=1; i<n; i++)
    {
        if(arr[0]<arr[i]){arr[0]=arr[i];}
    }

    printf("\nThe largest element is: %i\n",arr[0]);

}