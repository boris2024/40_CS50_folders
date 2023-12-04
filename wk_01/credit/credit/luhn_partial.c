#include<cs50.h>
#include<stdio.h>
#include<math.h>

int main(void)
{

unsigned long long int number=get_long("What is the number to check -> ");

    //printf("%lli\n", number);

    unsigned long long int number2=number;
    unsigned long long int number3=number;
    int a, b, c, criteria;
    int sum_even=0, sum_odd=0, sum_tot=0;

    int digits=0, digits2=0;

    for(int i=1; number>1; i++)
    {
        number=number/10;
        digits=i;
    }

    // printf("%lli\n", number);
    printf("number of digits in credit card number = %i\n", digits);

    for(int i=1; i<=digits ; i++  )
    {
        a = number2%10;

        printf("\na %i= %i",i,a);

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

        number2=number2/10;
    }

    printf("\nsum_even=%i", sum_even);

    printf("\nsum_odd=%i", sum_odd);
    printf("\n");

    sum_tot= sum_even + sum_odd;

    criteria=sum_tot%10;

    if(criteria==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}// MAIN ends here