#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

long int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    int n = strlen(input);

    for (int i = 0; i < n; i++)
    {
        if ( !isdigit(input[i]) )
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%li\n", convert(input));

} // MAIN ENDS here

long int convert(string input)
{
    // TODO

    int count=strlen(input);
    char word[count];
    int number[count];
    long int value=0;

    //printf("\ninput = %s\n", input);

    // remember: the number is entered by user into a string variable

    //  step 01: pass every single char from input string into word array of characters

    for(int i=0; i<count; i++)
    {
        word[i]=input[i];
    }


    // step 02: transform every character into an int

    for(int i=0; i<count; i++)
    {
        number[i]=(int)word[i];
    }

    printf("\n");


    // step 03: subtract 48 to transform back to original digit, assign to corresponding element

    for( int i=0; i<count; i++ )
    {
        number[i]=number[i]-48;
    }

/*
    for(int i=0; i<count; i++)
    {
        printf("%i", number[i]);
    }
*/

    // step 04: transform array of int into a single int value
    for(int i=0; i<count; i++)
    {
        int j=count-i-1;
        value= value+number[i]*pow(10,j);
    }

    //printf("\ncount= %i, \nvalue = %li\n", count, value);

    return value;

}