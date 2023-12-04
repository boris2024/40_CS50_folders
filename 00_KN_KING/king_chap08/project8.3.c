#include<cs50.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<math.h>

/* 20221130
project 8.3
from KN King's "C programming, a modern approach"
*/

int main(void)
{
long int n=1, n1=1, n2=1, m;
    int length;

while(1)
{
    printf("\nWrite a positive integer n, press ENTER after\n");
    scanf("%ld",&n);

    if(n<=0){break;}

    printf("\nn = %ld\n", n);
    int digits[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //printf("\nn = %ld\n", n);

    n1=n;
    n2=n;

    length=0;
    while(n1>1)
    {   n1=n1/10;
        length++;
    }

    printf("\nn-length = %d\n", length);

//this is the array in which each digit from n will be inserted for frequency analysis
    int ndigits[length];

    for(int i=length-1; i>=0; i--)
    {   ndigits[i] = (n2%10);
        n2=n2/10;
    }

// now we need to know the frecuency of each digit (0-9) in n
    int frequency[]={0,0,0,0,0,0,0,0,0,0};

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<length; j++)
        { if(digits[i]==ndigits[j]){  frequency[i]++; }
        }
    }

printf("\nrepeated digit(s): ");


    for(int i=0; i<10; i++)
    {
        if(frequency[i]>1){ printf("%d ",i); }
    }
    printf("\n");

}

}// MAIN ends here

