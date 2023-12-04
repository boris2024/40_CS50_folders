#include <cs50.h>
#include <stdio.h>
#include<math.h>
#include<stdbool.h>

int luhn (unsigned long long int number4, int digits);

int main(void)
{
    unsigned long long int number=get_long("What is the number to check -> ");

    //printf("%lli\n", number);

    unsigned long long int number2=number;
    unsigned long long int number3=number;
    unsigned long long int number4=number;

    // determine number of digits in number

    int digits=0;

    for(int i=1; number>1; i++)
    {
        number=number/10;
        digits=i;
    }

    // printf("%lli\n", number);
    // first, determine if cc number passes lunh's algorithm test
    // second, determine if number of digits is different from 13, 14, 15
    // third, determine if specific condition for each type of card is met

    int xxx= luhn(number4, digits);
    //printf("luhn says %i\n", xxx);

    if(xxx!=0)
    {   printf("INVALID\n");    }

    else
    {
    if( digits!=13 && digits!=15 && digits!=16 )
    {
        //printf("INVALID non 13 15 16\n");
        printf("INVALID\n");
    }

    // second condition, determine if it belongs to a known credit card company
    else
    {
        if(digits==13)
        {
            number2 = number2/pow(10,12);

            if(number2==4)
            {
                //printf("number2 = %lli",number2);
                //printf("\ndigits=13 and starts with 4, its a VISA\n");
                printf("VISA\n");
            }

            else
            {   //printf("\nINVALID 13\n");
                printf("INVALID\n");
            }
        }

        else
        {   if(digits==15)
            {
                number2 = number2/pow(10,13);

                if(number2==34 || number2==37)
                {   //printf("\ndigits=15 and starts with 34 or 37, its AMEX\n");
                    printf("AMEX\n");
                }

                else
                {   //printf("\nINVALID 15\n");
                    printf("INVALID\n");
                }
            }

            else
            {
                if(digits==16)
                {
                    number2= number2/pow(10,15);

                    if(number2==4){printf("VISA\n");}

                    else
                    {
                        number3= number3 / pow(10,14);
                        if(number3==51 || number3==52 || number3==53 || number3==54 || number3== 55 )
                        {
                            printf("MASTERCARD\n");
                        }

                        else
                        {
                            //printf("\nINVALID non MC\n");
                            printf("INVALID\n");
                        }
                    }
                }

            }
        }
    }
    }

    //printf("\n");

}// MAIN ENDS HERE


int luhn(unsigned long long int number4, int digits)
{

    int a, b, c, criteria;
    int sum_even=0, sum_odd=0, sum_tot=0;

    int digits2=0;

    for(int i=1; i<=digits ; i++  )
    {
        a = number4%10;

        //printf("\na %i= %i",i,a);

        //if position is even
        if(i%2==0)
        {
            b=2*a;
            int b1=b;
            int b2=b;

            for(int j=1; b>1; j++)
            {
                b=b/10;
                digits2=j;
            }

            for(int k=1; k<=digits; k++)
            {
                c=b1%10;
                b1=b1/10;
                sum_even = sum_even+c;
            }
        }

        // if position is odd
        if(i%2!=0)
        {
            sum_odd = sum_odd+a;
        }

        number4=number4/10;
    }

    sum_tot= sum_even + sum_odd;

    criteria=sum_tot%10;

    if(criteria==0)
    {   return 0;   }

    else
    {   return 1;   }

}



