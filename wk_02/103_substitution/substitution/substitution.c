#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{

    int length, length_plaintext;

    string plaintext, key, key2;

    int alphabet[26];

    // create alphabet array for upper case alphabetic characters
    for(int i=0; i<26; i++)
    {
        alphabet[i]=65+i;
    }


    if(argc!=2)
    {
        if(argc==1)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        else
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    // it follows this branch when argc is 2
    else
    {

    int key_length=strlen(argv[1]);

    key2=argv[1];

    if(key_length!=26)
    {
        printf("\nKey must contain 26 characters\n");
        return 1;
    }

    else
    {
        // use for loop to check for non-alphabetic chars in key
        int key_counter=0;
        for(int i=0; i<26; i++)
        {
            if( !isalpha(key2[i]) )
            {
                key_counter++;
            }
        }


        if(key_counter>0)
        {
            printf("\nKey must contain alphabetical characters only\n");
            return 1;
        }

        // check each letter in key[26] appears only once
        else
        {
            int unique_counter[26];

            //make the counter for each char start at 0
            for(int i=0; i<26;i++)
            {
                unique_counter[i]=0;
            }

            for(int i=0; i<26; i++)
            {
                for(int j=0; j<26; j++)
                {
                    if( alphabet[i]==toupper(key2[j]) )
                    {
                        unique_counter[i]++;
                    }
                }
            }

            for(int i=0; i<26; i++)
            {
                if(unique_counter[i]>1)
                {
                    printf("\nKey must contain unique characters only\n");
                    return 1;
                }
            }
        }
    }


    plaintext= get_string("plaintext: ");
    length_plaintext=strlen(plaintext);

    // use loop to fill an array for the purpose of knowing the initial status of
    // each element in the plaintext array
    // use islower fxn to determine the status of each element initially

    int case_status[length_plaintext];

    for(int i=0; i<length_plaintext; i++)
    {
        case_status[i]=islower( plaintext[i] );
    }

/*
    for(int i=0; i<length_plaintext; i++)
    {
        printf("\ncase_status [%i] = %i", i, case_status[i]);
    }
*/

    //printf("\n");

    // make argv[1] the key
    key=argv[1];


    //make all characters of plaintext[] and key[] uppercase

    for(int i=0; i<length_plaintext; i++)
    {
        if( isalpha(plaintext[i]) )
        {        plaintext[i]=toupper( plaintext[i] );  }
    }

    for(int i=0; i<26; i++)
    {
        key[i]=toupper( key[i] );
    }


    // only alphabetical characters of plaintext[] must be ciphered

    // use 2 for loops to match char from plaintext array with char in alphabet
    // outer for loop controls position of char in plaintext, inner for loop controls comparison vs alphabet array

    // the index for key[] array and alphabet[] array are the same, both are the same length


    char ciphertext[length_plaintext];

    for(int i=0; i<length_plaintext; i++)
    {
        for(int j=0; j<26; j++)
        {

            if( isalpha(plaintext[i]) )
            {
                if( plaintext[i]==alphabet[j] )
                {
                    ciphertext[i]=key[j];
                }
            }

            else
            {
                ciphertext[i]=plaintext[i];
            }
        }
    }

    //printf("\n");

    for(int i=0; i<length_plaintext; i++)
    {
        if( case_status[i]!=0 )
        {
            ciphertext[i]=tolower( ciphertext[i] );
        }
    }


    printf("ciphertext: ");

    for(int i=0; i<length_plaintext; i++)
    {
        printf("%c", ciphertext[i]);
    }

    printf("\n");

    }

}// MAIN ends ere