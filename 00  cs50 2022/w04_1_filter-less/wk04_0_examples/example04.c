#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
int c,d,*pc;

c=5;
d=-15;

pc=&c;
printf("\n%i",*pc);

pc=&d;
printf("\n%i\n",*pc);

}