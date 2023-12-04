#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

/*
20221220 project 9.1 from "C programming, a modern approach" by KN KING.
selection sort of array elements
*/

int main(void)
{

int n, maxposition,  k, temp;

printf("\nenter number of n elements to sort:\n");
scanf("%d",&n);

int elements[n];

for(int i=0; i<n; i++)
{
    printf("\nelements[%d]= ",i);
    scanf("%d", &elements[i]);
}

printf("\n");

for(int j=0; j<n; j++)
{
    printf(" %d",elements[j]);
}
printf("\n");

int counter=0;

// outer loop starts here

for(int i=n-1; 0<=i  ; i--)
{   counter++;

    // inner FOR loop
    int max=0;
    for(k=0; k<=i; k++)
    {
        if(max<elements[k]) {   max=elements[k];
                                maxposition=k;
                            }
    }

    temp= elements[i];
    elements[i]=elements[maxposition];
    elements[maxposition]=temp;


printf("\nit %d   ", counter);
for(int j=0; j<n; j++)
{
    printf(" %d",elements[j]);
}
printf("\n");

}// outer loop ends here


printf("\n");
printf("\n");
}// MAIN ends here
