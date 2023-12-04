#include <cs50.h>
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text;
    float index;
    int index2=1;
    float L=1.00, S=1.00;


    text=get_string("Text: ");

    //text="A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains." ;

    //printf("%s\n", text);

    //printf("\n\n");

    int letter_count=count_letters(text);

    //printf("no. of letters = %i\n", letter_count);


    int word_count= count_words(text);

    //printf("no. of words = %i\n", word_count);


    int sentences_count= count_sentences(text);

    //printf("no. of sentences = %i\n", sentences_count);


    // definition and calculation of L , S and index

    L=((float)letter_count/word_count)*100;

    S=((float)sentences_count/word_count)*100;

    index=0.0588*L-0.296*S-15.8;

    index2=round(index);


    //printf("\nL = %f", L);

    //printf("\nS = %f", S);

    //printf("\nindex = %i\n", index2);

    if(index2<1||index2>=16)
    {
        if(index2<1)
        {
            printf("\nBefore Grade 1\n");
        }

        else
        {
            printf("\nGrade 16+\n");
        }
    }

    else
    {
        printf("\nGrade %i\n",index2);
    }






}// MAIN ENDS here

int count_letters(string text)
{
    int counter=0;

    int text_length= strlen(text);

    for( int i=0; i<text_length; i++ )
    {
        if( isalpha(text[i]) )
        {
            counter++;
        }
    }

    //printf("\n%i\n", counter);
    return counter;

}

int count_words(string text)
{

    int words, counter=0;

    int text_length= strlen(text);

    for(int i=0; i<text_length; i++)
    {
        if( isblank(text[i]) )
        {
            counter++;
        }
    }

    words=counter+1;

    return words;
}

int count_sentences(string text)
{
    int counter=0;

    int text_length= strlen(text);

    for(int i=0; i<text_length; i++)
    {
        if( text[i]=='.'||text[i]=='!'||text[i]=='?' )
        {
            counter++;
        }
    }

    return counter;
}