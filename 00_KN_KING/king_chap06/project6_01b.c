#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/*
20221123
This program finds the largest number from a set of float numbers entered by the user.
Enter zero or a negative number to stop the process and find the largest number entered so.
Arrays are not used in this exercise.
 */

int main(void)
{

float candidate=0, nmax=0;

printf("\nWrite a set of decimal numbers. Enter each number and then press ENTER.\nProgram will return the largest number. \nTest will end when the user enters a number equal to o less than 0\n");

while(1)
{
    printf("\nEnter float number, then press ENTER\n");
    scanf("%f", &candidate);

    if (candidate<=0){  printf("\nnmax = %0.2f\n",nmax );
                        break; }

    else{   if(candidate>nmax){nmax=candidate;}
        }
}

return 0;

}// main ends here