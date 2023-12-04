#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int main(void)
{
int sum3=0;
for(int i=1; (3*i)<1000; i++)
{
    sum3=sum3+(3*i);

}
printf("\n");

int sum5=0;
for(int i=1; (5*i)<1000; i++)
{
    sum5=sum5+(5*i);

}

int sum15=0;
for(int i=1; (15*i)<1000; i++)
{
    sum15=sum15+(15*i);

}

printf("\nsum3= %d",sum3);
printf("\nsum5= %d",sum5);
printf("\nsum15= %d",sum15);
printf("\n");
int tot= sum3+sum5-sum15;
printf("\ntotal = %d",tot);
printf("\n");

}