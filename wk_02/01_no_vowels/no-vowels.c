// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace (string input);

int main(int argc, string argv[])
{
    string new_word;

    if(argc<2 || argc>2)
    {
        printf("Usage:./no-vowels word\n");
        return 1;
    }

    new_word= replace(argv[1]);

    printf("%s\n", new_word);


}

string replace (string input)
{
    string transformed;
    int length;

    //printf("the word is %s \n",input);

    length=strlen(input);

    for(int i=0; i<length; i++ )
    {
        if('a'==input[i])
        {
            input[i]='6';
        }

        else
        {
            if('e'==input[i])
            {
                input[i]='3';
            }

            else
            {
                if('i'==input[i])
                {
                    input[i]='1';
                }

                else
                {
                    if('o'==input[i])
                    {
                        input[i]='0';
                    }

                }
            }


        }

    }

    transformed=input;


    return transformed;
}
