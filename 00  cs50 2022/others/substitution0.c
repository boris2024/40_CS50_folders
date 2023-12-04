#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

string key, keyprime, plain;
    int m,j,k,i,t, counter;

int lowerplain, lowerkey;

//  m is total number of char in key
//  j is element position along the string key

//  k is element position along the char array alphabet
//  counter is times a certain char is present in key, all char must exist only once

//  t is total length of plaintext
//  i is the element position along array of char plaintext

int main(int argc, string argv[])
{

    char alphabet[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //1. check the number of arguments entered through command line
    if(argc!=2) {printf("\nUsage: ./substitution KEY\n");}

    else
    {   m=strlen(argv[1]);
        key=argv[1];
        keyprime=argv[1];
                                            //check 1
        if(m!=26)   {   printf("\nmust be 26 char long\n"); return  1;  }

        else
        {
        for(j=0;j<m;j++)                    //check 2
        if(!isalpha(key[j])){   printf("\nkey must only contain alphabetic characters\n");
                                return 1;   }

        else                                //check 3 look for duplicate char in key
        {
        for(k=0;k<26;k++)
        {
        counter=0;
        for(j=0;j<m;j++)
        {
            if(islower(key[j])) { key[j]=toupper(key[j]); }
                                                            //printf("\n%c\n",key[j]);
                                                            //printf("%c",key[j]);
            if( key[j]==alphabet[k] )
            {
                counter++;
                //printf("\n%i\n",counter);
                if(counter>1){  printf("\nKey must not contain repeated characters\n");
                                return 1;}
            }
                else        {    }
        }   //  inner for1
        }   //  external for1
        }   // check 3 look for duplicate char ends here

        }


        plain=get_string("\nplaintext: ");      //the cipher step starts here

        t=strlen(plain);

        printf("\nciphertext:");

        for(i=0;i<t;i++)
        {
        for(k=0;k<26;k++)
        {   int a=plain[i];
            int b=alphabet[k];
            if(a==b)

            {j=k;

                printf("%c",keyprime[j]);
            }

        }
        }

        printf("\n");


    }   // first IF ends here


}