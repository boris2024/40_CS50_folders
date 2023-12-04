#include<cs50.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>

double calcfact(int n);

int main(void)
{

int k ;
double a, b, c, nfact;

double sum=0;

for( k=0; k<12 ; k++)
{
    a= k+1;
    b= 2*k+1;
    nfact=calcfact(b);
    c= (a/nfact);

    sum=sum+c;

    printf("\nk= %d, a= %.0lf, b= %.0lf, nfact= %.0lf, c= %0.15lf, sum= %.15lf\n", k, a,b, nfact, c, 2*sum);
}

return 0;
}   // MAIN ends here



double calcfact(int n)
{
    double factresult=1;

    for(int i= n;  i>1;  i--)
    {   factresult=factresult*i;    }

    return factresult;
}
