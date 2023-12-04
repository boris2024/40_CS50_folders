#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

// C program to calculate the power using recursion

int powerf(int a, int b);


int main(void)
{
int a,b;
printf ("\nwhat is the base?\n");
scanf("%d",&a);
printf ("\nwhat is the power?\n");
scanf("%d",&b);

printf("\nbase= %d, power= %d\n",a,b);

int total = powerf(a,b);

printf("\ntotal= %d\n", total);
}


int powerf(int a, int b)
{
int x;

if(b>0) {   x=a*powerf(a,(b-1));
            return x;
        }

else    {   return 1;
        }
}
