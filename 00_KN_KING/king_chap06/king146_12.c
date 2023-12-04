#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
// program to test if number n is prime or not

int main(void)
{
int n;
int counter=0;

printf("\nenter number n to test:\n");

scanf("%d",&n);

for(int d=2; d<n; d++)
{
if(n%d==0){ counter++;
            printf("\nfound a divisor, hence n is not a prime");
            printf("\ncounter= %d\n",counter); }

}

return 0;
}