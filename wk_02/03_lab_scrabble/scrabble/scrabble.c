#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner

    if(score1>score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        if(score2>score1)
        {
            printf("Player 2 wins!\n");
        }

        else
        {
            printf("Tie!\n");
        }
    }


}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    int length, sum;

    length=strlen(word);

    int char_points[length];

    int alphabet[]={97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};


    // you must consider upper and lower case letters
    // solution is to make them all lower case, use a for loop

    for(int i=0; i<length; i++)
    {
        if( isupper(word[i]) )
        {
            word[i]=tolower(word[i]);
        }
    }

    // outer for moves char position along word

    // inner for is used to check alphabet characters against each word[length] char
    // j represents the char position along the array of 26 chars in alphabet[]


    for(int i=0; i<length; i++)
    {
        for(int j=0;j<26; j++ )
        {
            if( !isalpha( word[i] ) )
            {
                char_points[i]=0;
            }

            else
            {
                if( word[i]==alphabet[j] )
                {
                    char_points[i]=POINTS[j];
                }
            }
        }
    }

    sum=0;
    for(int i=0; i<length; i++)
    {
        sum=sum+char_points[i];
    }

    //printf("score is %d\n", sum);

return sum;
}
