#include<cs50.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<math.h>

/* 20221129
example from KN King's "C programming, a modern approach, page 166 of the book"
this was modified to find the frequency of each digit 0-9 in a given long int
*/

int main(void)
{
long int n1=1, n2=1;
int length; // int entered by the user

int digits[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

printf("\nWrite a positive integer n, press ENTER after\n");
scanf("%ld",&n1);

printf("\nn = %ld\n", n1);

n2=n1;

length=0;
while(n1>1)
{   n1=n1/10;
    length++;
}

printf("\nn-length = %d\n", length);

// this is the array in which each digit from n will be inserted for frequency analysis
int ndigits[length];

for(int i=length-1; i>=0; i--)
{   ndigits[i] = (n2%10);
    n2=n2/10;
}

printf("\n");
for(int i=0; i<length; i++)
{
    printf("%d",ndigits[i]);
}
printf("\n");

// now we need to know the frecuency of each digit (0-9) in n

int frequency[]={0,0,0,0,0,0,0,0,0,0};

for(int i=0; i<10; i++)
{
    for(int j=0; j<length; j++)
    {
        if(digits[i]==ndigits[j]){  frequency[i]++; }
    }
}

printf("\nfrecuency of each digit 0-9:\n");
for(int i=0; i<10; i++)
{
    printf("%d ",frequency[i]);
}
printf("\n");

return 0;
}// MAIN ends here