#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/* write a program that finds the largest and smallest of a group of 4 integers
problem page 96, book by kn king, no. 7, chap 5.
*/

int main (void)
{

int n=1, numbers[n], nmax=1;

printf("\nenter value of n, how many integers to evaluate?\n");
scanf("%d",&n);

printf("\nwrite each number followed by ENTER\n");

for(int i=0; i<n; i++)
{
    printf("\nnumbers[%d] = ", i );
    scanf("%d",&numbers[i]);
}

printf("\n");

for(int i=0; i<n; i++)
{
    printf(" %d ",numbers[i]);
}
printf("\n");

// the following algorithm is used to find the largest number within a set of numbers,


for (int i=0; i<n; i++)
    {   int counter=0;

        nmax=numbers[i];

        for(int j=0; j<n; j++)
        {
            if( nmax >= numbers[j] )    {   counter++;   }
        }

        if (counter==n){    printf("\nnmax = %d\n", nmax); break; }
    }

//printf("\nthe greatest number in the set is %d",a );

printf("\n");

}