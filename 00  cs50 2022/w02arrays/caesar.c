#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include <stdlib.h>

int m;  //m length of string arg[1]
int i;  //i position of ith element along arg[1] string
int numkey; //  key as int
string plain;

int l;   //length of plaintext, it is the same length for ciphertext
int j;   //position of jth element along plaintext

int a,b;
int e,f;

char d,g;


int main (int argc, string argv[])
{
if (argc!=2){printf("\nUsage: ./caesar key\n");
                        return 1;}

    else
    {   m=strlen(argv[1]);
        string key=argv[1];

        for(i=0;i<m;i++)
        {
            if (!isdigit(key[i]))   {   printf("\nUsage: ./caesar key\n");
                                        return 1;       }
        }

        numkey=atoi(key);
        //printf("\nthe key is.. %i\n", numkey);

        plain=get_string("\nplaintext: ");
        //printf("\nplaintext:  %s",plain);

        l=strlen(plain);

        printf("\nciphertext: ");
        for (j=0;j<l;j++)
        {

        if(isalpha(plain[j]))
        {

                if(isupper(plain[j]))               //if indeed plain char is uppercase follow this branch
                {   a=plain[j];                     //cast plain[j] as an int
                    b=(((a-65)+numkey)%26)+65;
                    d=b;
                    printf("%c",d);
                }

                else                                //else, if it's lowercase, do this
                {   a=plain[j];                     //cast plain[j] as an int
                    b=(((a-97)+numkey)%26)+97;
                    d=b;
                    printf("%c",d);
                }


        }

        else
        {   d=plain[j];
            printf("%c",d);
        }

        }

        printf("\n");

    }
return 0;
}