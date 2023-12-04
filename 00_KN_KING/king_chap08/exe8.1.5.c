#include<cs50.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

/* 20221130
The Fibonacci Numbers, pae 177, exercise 8.1.5
*/
int main(void)
{

int fib_numbers[40];

fib_numbers[0]=0;
fib_numbers[1]=1;

for(int i=2; i<40; i++)
{
    fib_numbers[i]=fib_numbers[i-1]+fib_numbers[i-2];

}

printf("\n");

for(int i=0;i<40; i++)
{
    printf(" %d", fib_numbers[i]);
}

printf("\n");

}