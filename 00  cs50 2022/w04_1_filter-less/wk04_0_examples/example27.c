#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void set_to_zero(int *n)
{   *n = 0;
    printf("address01 is: %p\n",n);
    printf("x is %d\n", *n);

}

int main()
{
int *n; int x = 1;
printf("\naddress00 is: %p\n",&x);
printf("x is %d\n", x);

n=&x;

set_to_zero(&x);

printf("\naddress02 is: %p\n",&x);
printf("x is %d\n", x);

return 0;
}
