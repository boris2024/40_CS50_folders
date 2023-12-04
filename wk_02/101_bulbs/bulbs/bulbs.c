#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include<math.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

// to do on 20230321
// a. include emoji fxn
// b. include symbols from ascii table

int main(void)
{
    // TODO

    // variables associated to decimal to binary conversion
    int xyz, remainder;
    int binary_no[]={0,0,0,0,0,0,0,0};



    int length;
    string message=get_string("what is the message to translate? ");

    // this is the message with each character translated into decimal numbers

    length= strlen(message);
    int message2[length];

    // ADJUST alpha_count as more characters are added to alpahabet[]
    int alpha_count=95;
    int alphabet[95];

    
    for(int i=0; i<95; i++)
    {
        alphabet[i]=i+32;
    }


    // outer for controls position of char along the alphabetical message
    // inner for controls comparison of message[i] against alphabet array, 1 by 1
    for(int i=0; i<length; i++)
    {
        for(int j=0; j<alpha_count; j++)
        {
            if(message[i]==alphabet[j])
            {
                message2[i]=alphabet[j];
            }
        }
    }


    printf("\n");
    for(int i=0; i<length; i++)
    {
        printf("%i ", message2[i]);
    }
    printf("\n\n");


    // decimal to binary starts here
    // use the decimal to binary conversion algorithm on each char in message2[26]

    for(int k=0; k<length; k++)
    {
        remainder=message2[k];

        for(int i=7; i>=0; i--)
        {
            xyz= pow(2,i);

            if(remainder>=xyz)
            {   binary_no[i]=1;
                remainder = (remainder%xyz);    }

            else
            {   binary_no[i]=0; }

            //printf(" %i ", binary_no[i]);

            print_bulb(binary_no[i]);
        }

        printf("\n");
    }





}// MAIN ENDS HERE



void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}




