#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

// this program calculates the number of digits in an integer

int main(void)
{
int digits=0, number;

printf("\nenter int number to determine its number of digits\n");
scanf("%d",&number);

while(1)
{   digits++;
    number= number/10;

    if(number<1){break;}
}

printf("\ndigits in number = %d\n",digits);

return 0;
}// main ends here