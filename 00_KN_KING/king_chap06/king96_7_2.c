#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/* write a program that finds the largest and smallest of a group of 4 integers
problem page 96, book by kn king, no. 7, chap 5.
*/

int main (void)
{

int n=100, numbers[n], nmax=1;

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

// the following algorithm is used to find the largest number within the set of numbers,

for (int i=0; i<(n) ; i++)
{
    if(numbers[i]>nmax) {   nmax=numbers[i];}
}

printf("\nlargest number is: %d\n",nmax);

return 0;

} // MAIN endes here