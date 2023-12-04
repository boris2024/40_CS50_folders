#include<stdio.h>
#include<math.h>
#include<cs50.h>

    // calculate decimal expression of a binary number with x number of binary digits (bits)
    // in this example x is assigned to i

int main(void)
{
    int sum=0;

    for(int i=0; i<=32; i++)
    {
        sum= sum + pow(2,i);

        printf("\ni= %d, pow (2, %d)= %0.0f, total = %d", i, i, pow(2,i), sum);
    }

    printf("\n");
}