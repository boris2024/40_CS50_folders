#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int main(void)
{

/*this program calculates brokers commission and makes comparison*/

float value, commission, commission2;
int shares;
float unitprice;

printf("\nenter number of shares to buy/sell :\n");
scanf("%d", &shares);
printf("\nenter price per share in 00.00 format\n");
scanf("%f", & unitprice);

value = shares * unitprice;

// calc broker 01 commission
if(value<2500.00){  commission=30 + value*(1.7/100);
                    printf("\nbroker 01 commission = %0.2f usd\n", commission); }

if(2500<=value && value<6250)   {   commission= 56+value*(0.66/100);
                                    printf("\nbroker 01 commission = %0.2f usd\n", commission);}

if(6250<=value && value<20000)  {   commission = 76+value*(0.34/100);
                                    printf("\nbroker 01 commission = %0.2f usd\n", commission);
                                }

if(20000<=value && value<50000)
                                {   commission = 100 + value*(0.22/100);
                                    printf("\nbroker 01 commission = %0.2f usd\n", commission);
                                }


// calc broker 02 commission

if( shares < 2000)  {   commission2= 33 + shares*0.03;
                        printf("\nbroker 02 commission = %0.2f usd\n", commission2);
                    }

else    {   commission2= 33+ shares*0.02;
            printf("\nbroker 02 commission = %0.2f usd\n", commission2);
        }

return 0;
}