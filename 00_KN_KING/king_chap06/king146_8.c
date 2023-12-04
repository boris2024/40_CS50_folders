#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int main (void)
{
    printf("\n");
    int sum=0;

    for(int i=0; i<10; i++)
    {   if(i%2){continue;}
        sum +=i;
    }
    printf("\n%d", sum);
    printf("\n");
}