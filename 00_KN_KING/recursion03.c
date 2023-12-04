#include<cs50.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

// C program to determine GCD of int numbers a and b


int main(void)
{
int i;
int a,b,x;
printf("\nwhat is a?\n");
scanf("%d",&a);
printf("\nwhat is b?\n");
scanf("%d",&b);

for(i=1; (i<=a)&&(i<=b);i++ )
{
if ( (a%i)==0&&(b%i)==0 ){    printf("\ni= %d\n",i);  x=i;    }
}

printf("\nGCD ( %d, %d)= %d\n",a,b,x);

}// MAIN ends here