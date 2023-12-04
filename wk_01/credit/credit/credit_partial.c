#include <cs50.h>
#include <stdio.h>
#include<math.h>
#include<stdbool.h>

//void luhn (unsigned long long int number, int digits);

int main(void)
{
    unsigned long long int number=get_long("What is the number to check -> ");

    //printf("%lli\n", number);

    unsigned long long int number2=number;
    unsigned long long int number3=number;

    // determine number of digits in number

    int digits=0;

    for(int i=1; number>1; i++)
    {
        number=number/10;
        digits=i;
    }

    // printf("%lli\n", number);
    printf("number of digits in credit card number = %i\n", digits);

    // first condition, determine if number of digits is different from 13, 14, 15
    // if in fact it is different, then that number is invalid

    if( digits!=13 && digits!=15 && digits!=16 )
    {
        printf("INVALID non 13 15 16\n");
    }

    // second condition, determine if it belongs to a known credit card company
    else
    {
        if(digits==13)
        {
            number2 = number2/pow(10,12);

            if(number2==4)
            {
                printf("number2 = %lli",number2);
                printf("\ndigits=13 and starts with 4, its a VISA\n");
            }

            else
            {
                printf("\nINVALID 13\n");
            }
        }

        else
        {   if(digits==15)
            {
                number2 = number2/pow(10,13);

                if(number2==34 || number2==37)
                {   printf("\ndigits=15 and starts with 34 or 37, its AMEX\n");
                }

                else
                {   printf("\nINVALID 15\n");
                }
            }

            else
            {
                if(digits==16)
                {
                    number2= number2/pow(10,15);

                    if(number2==4){printf("\nthis is a VISA\n");}

                    else
                    {
                        number3= number3 / pow(10,14);
                        if(number3==51 || number3==52 || number3==53 || number3==54 || number3== 55 )
                        {
                            printf("\nthis is a MC\n");
                        }

                        else
                        {
                            printf("\nINVALID non MC\n");
                        }
                    }
                }


            }
        }
    }

}// MAIN ENDS HERE

/*
luhn(number, digits)
{

    unsigned long long int number2=number;
    unsigned long long int number3=number;

    printf("number = %lli\n", number);
    printf("number of digits in credit card number = %i\n", digits);
    printf("digits = %i\n", digits);
}
*/
