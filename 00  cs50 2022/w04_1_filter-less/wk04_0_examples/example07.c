#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    int i;
    int x[6];
    int sum=0;

    for(i=0;i<6;i++)
    {   scanf("%i",x+i);
        sum=sum + *(x+i);
    }

    printf("\nsum=%i\n",sum);
}