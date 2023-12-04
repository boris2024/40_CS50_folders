// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool criteria01=false, criteria02=false, criteria03=false, criteria04=false;

    int counter01=0, counter02=0, counter03=0, counter04=0;

    int length;

    length=strlen(password);

    for(int i=0; i<length; i++)
    {
        if( isdigit(password[i]) )
        {
            counter01++;
        }

        if( islower(password[i]) )
        {
            counter02++;
        }

        if( isupper(password[i]) )
        {
            counter03++;
        }

        if( !isalnum(password[i]) )
        {
            counter04++;
        }
    }


    // isdigit fxn
    if(counter01>0)
    {
        criteria01=true;
    }

    // islower fxn
    if(counter02>0)
    {
        criteria02=true;
    }

    // isupper fxn
    if(counter03>0)
    {
        criteria03=true;
    }

    // is not alphanumeric
    if(counter04>0)
    {
        criteria04=true;
    }

    if( criteria01==true && criteria02==true && criteria03== true && criteria04== true ){ return true;}

    return false;
}
