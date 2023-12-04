#include<cs50.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>

/*
20221125
project 6.11 from KN King's "c programming, a modern approach"
*/

// factorial fxn
double factorial(int n)
{
int total=1;

for(int i=n; i>=1; i--)
{   total=total*i;  }

return total;
}


int main(void)
{
int n;            double inverse, sum=0;

printf("\nwhat is the value of n?\n");
scanf("%d",&n);

printf("\n");

for(int i=1; i<=n; i++ )
{
inverse= 1 / factorial(i);
//printf("\ninverse= %0.15lf ", inverse);
sum=sum+inverse;
printf("\nif n=%d, e= %0.15lf\n", i, sum+1);
}


printf("\n");

return 0;
}// main ends here