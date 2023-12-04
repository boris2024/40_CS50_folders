#include<cs50.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

/* 20221206 project 8.16 from "C programming, a modern approach" by KN KING
*/

int main(void)
{
int anagram=0, length=1;
char word[length], word2[length];

printf("\nwrite FIRST word to analyze, then press ENTER\n");
scanf("%s",word);

length=strlen(word);

printf("\nwrite SECOND word to analyze, then press ENTER\n");
scanf("%s",word2);

char alphabet[]=
{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int frequency[26]={0};

// analysis of word1
for(int i=0; i<length; i++)
{
    for(int j=0; j<26; j++)
    {
        if( isalpha(word[i])==0 ){continue;}

        else
        {   if( isupper(word[i]) )
            {   if (( tolower(word[i])==alphabet[j] )  ){frequency[j]++;}   }

            else{   if(word[i]==alphabet[j]){frequency[j]++;}   }
        }
    }
}

printf("\n");

// analysis of word2
for(int i=0; i<length; i++)
{
    for(int j=0; j<26; j++)
    {
        if( isalpha(word2[i])==0 ){continue;}

        else
        {   if( isupper(word2[i]) )
            {   if (( tolower(word2[i])==alphabet[j] )  ){ frequency[j]--; }   }

            else{   if(word2[i]==alphabet[j]){ frequency[j]--; }   }
        }
    }
}

printf("\n");

for(int i=0; i<26; i++)
{
    if(frequency[i]>0){anagram++;}
}


if (anagram==0){printf("yes, word1 and word2 are anagrams!");}

else{printf("word1 and word2 ARE NOT anagrams!");}

printf("\n\n");

}// MAIN ends here