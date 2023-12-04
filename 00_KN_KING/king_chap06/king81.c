#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
/* example 5.2 from KN Kings's book*/

int main(void)
{

float value, commission;

printf("\nenter transaction value (usd):\n");
scanf("%f", &value);
printf("\ntransaction value is: %0.2f usd\n", value);

if(value<2500.00){  commission=30 + value*(1.7/100);
                    printf("\ncommission = %0.2f usd\n", commission); }

if(2500<=value && value<6250)   {   commission= 56+value*(0.66/100);
                                    printf("\ncommission = %0.2f usd\n", commission);}

if(6250<=value && value<20000)  {   commission = 76+value*(0.34/100);
                                    printf("\ncommission = %0.2f usd\n", commission);
                                }

if(20000<=value && value<50000) {   commission = 100 + value*(0.22/100);
                                    printf("\ncommission = %0.2f usd\n", commission);
                                }


return 0;
}


