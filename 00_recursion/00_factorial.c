#include<stdio.h>
#include<cs50.h>

int factorial (int n);

int main(void)
{
    int n, result;

    n=get_int("enter value of n: ");

    result=factorial(n);

    printf("\nn!= %d\n", result);
}

int factorial (int n)
{

    if(n==1)
    {
        return 1;
    }


    return ( n * factorial(n-1) );

}