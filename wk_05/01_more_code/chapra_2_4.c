#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// 20230602  problem 2.4 from the numerical methods book by chapra

int factorial(int number);

int main (void)
{

    long double PI= 3.1415926535897932384626433832795028841;

    // x represents the angle in radians
    long double x=PI/4;

    printf("\nangle in radians x= %LF\nresult sin(x)= %F\n",x,sin(x));

    // n represents the nth term, starting with n=0
    int n=5;

    int number=1;

    int fac_result=factorial(number);

    //printf("\nfactorial of %d = %d\n",number,fac_result);

    int factor=1;
    long double sum=0;
    long double div=1;
    double power_number=1;
    double factorial_number=1;

    for(int i=0; i<=n; i++)
    {
        number=2*i+1;

        if(i%2==0){ factor=1;   }

        else{   factor=-1;  }

        power_number=pow(x,number);

        factorial_number=factorial(number);

        div=factor*power_number/factorial_number;

        sum=sum+div;

        printf("\nn = %d, nth term = %LF\nsum= %LF\n",i,div,sum);
    }



    printf("\nsum = %LF\n",sum);

}// MAIN ends here


int factorial(int number)
{
    int fac_result=1;
    for(int i=number; i>1; i--)
    {
        fac_result=fac_result*i;
    }

    return fac_result;
}
