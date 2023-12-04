#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/*20221212 problem 9.3.12 from "C programming, a modern approach" by KN KING
*/

// prototype of fxn
double inner_product(double a[], double b[],int n);

int main (void)
{
int n=100;
double a[n], b[n], total;

printf("\nenter int n, then press ENTER\n");
scanf("%d",&n);

printf("\nenter decimal numbers into a[n] array, press ENTER after each number\n");

for(int i=0; i<n; i++)
{
    printf("\ndouble a[%d] = ", i);
    scanf("%lf", &a[i]);
}

printf("\n");

printf("\nenter decimal numbers into b[n] array, press ENTER after each number\n");

for(int i=0; i<n; i++)
{
    printf("\ndouble b[%d] = ", i);
    scanf("%lf", &b[i]);
}
printf("\n");

int i=0;
while(i<n)
{
    printf("\na[%d]= %0.2f,   b[%d]= %0.2f", i, a[i],i, b[i]  );
    i++;
}
printf("\n");

// note, page 196, you don't put brackets after an array name when passin it to a fxn
total= inner_product(a, b, n);

printf("\ntotal = %0.2lf\n",total);

}// MAIN ends here


double inner_product(double a[], double b[],int n)
{
double sum=0;

for(int i=0; i<n; i++)
{
    sum=sum+a[i]*b[i];
}

return sum;
}
