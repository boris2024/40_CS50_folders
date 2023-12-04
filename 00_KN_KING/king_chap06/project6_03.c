#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/*
20221124
project 6.3 from "C Programming, A Modern Approach" by K.N. King

Ask user to enter a fraction, find GCD of numerator and denominator
and reduce both to lowest terms
*/

int main (void)
{

int a, b, minimum=1, gcd=1;
printf("\nEnter numerator and denominator of fraction to reduce to minimum terms,\n[numerator] [denominator] then press ENTER\n");
scanf("%d %d", &a, &b);

printf("\nfraction =  %d / %d", a, b);

for(int i=1; (i<=a)&&(i<=b) ; i++ )
{
    if( (a%i==0)&&(b%i==0) ) {  gcd=i; }
}

printf("\ngcd = %d\n",gcd);

printf("\nfraction =  %d / %d\n", (a/gcd), (b/gcd) );

return 0;
}// MAIN ends here