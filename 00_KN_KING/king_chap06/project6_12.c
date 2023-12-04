#include<cs50.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>

/*
20221126
project 6.12 from KN King's "c programming, a modern approach"
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
int n=30;            double inverse=0.0, sum=0, error;

printf("\nwhat is the value of the error?\n");
scanf("%lf",&error);
printf("\n");

for(int i=1; i<n; i++ )
{
inverse= 1 / factorial(i);
sum=sum+inverse;

printf("\ncurrent term= %0.10lf ", inverse);
printf("\nerror = %0.10lf ", error);
printf("\nn=%d, e= %0.10lf\n", i, sum+1);

if(inverse<error){  printf("\niterations stopped, current term < error\n");
                    break;}

}


printf("\n");

return 0;
}// main ends here