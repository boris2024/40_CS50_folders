#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

// TODO 1. measure execution time from beginning to end
// TODO 2. get timestamp of execution time every time a prime is found
// TODO 3. write primes to csv or txt file, just the primes or the pair (x,y), x=position, y=prime nuber

void prime(int a);
int primecount=0;

int main(void)
{

int n;
printf("\nfind all prime numbers less than n = \n");

scanf("%d",&n);

printf("\nthis program will find all prime numbers less than %d\n",n);

for (int x=2; x<n; x++)
{
 // call fxn to determine if x is prime or not
 prime(x);
}

return 0;
}// MAIN ends here


// user defined fxn to check if number is prime or not
void prime(int a)
{
int counter=0;

for(int i=2; i<=(a-1); i++ )
{
    if(  (a%i)==0  ) {  counter++; }
}

if (counter==0) {   primecount++;
                    printf("\nprime %d, %d is prime\n",primecount, a);
                }

//else {printf("\n%d is not prime\n",a);    }
}