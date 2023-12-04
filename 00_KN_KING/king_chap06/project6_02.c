#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/*
20221124
project 6.2 from KN King's "C Programming, A Modern Approach"

Find the GCD of 2 integers, NOT using Euclid's theorem
*/

int main(void)
{
    int number01, number02, minimum=1, gcd=1;
    printf("\nEnter 2 integers separated by a space to find their GCD,\nthen press ENTER\n");
    scanf("%d %d", &number01, &number02);

    //find smallest number between number01 and number02

    if ( number01<number02 ){   minimum=number01;   }

    else{   if (number01>number02){minimum= number02;}

            else{ printf("\nnumber01 = number02\n"); }
        }

    for(int i=1; i<=minimum; i++)
    {
        if((number01%i==0)&&(number02%i==0)){   gcd=i;  }
    }

    printf("\nGCD = %d\n", gcd);

return 0;
}// main ends here