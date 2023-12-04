#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main (void)
{
    int i;
    int numbers[6];
    int sum=0;

    printf("\nEnter 6 integers:\n");

    for(i=0; i<6; i++)
    {   scanf("%i",&numbers[i]);    }

    for(i=0; i<6; i++)
    {   sum=sum+numbers[i]; }

    printf("\n%i\n",sum);

}