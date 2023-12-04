#include<cs50.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>

// calculate factorial for a certain number

int main (void)
{
int n;

printf("\nenter number (n) whose factorial you want to calculate\n");
scanf("%d",&n);
//printf("\nn = %d\n",n);

double total=1;

for(int i=n;i>1;i--)
{
    total=total*i;
}
printf("\nn= %d, n!= %.0lf \n", n, total);

}