#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

//global variables
//number of char in text
int m, i;

float alphacounter=0; float spacecounter=0; float markcounter=0;


int main (void)
{
string text=get_string("\nText:");

printf("\n%s\n",text);

// m is number of char in text
// i is element number in array
// alphacounter is the number of alphabetic char in text


m=strlen(text);

for(i=0;i<m;i++)    {if (isalpha(text[i])){alphacounter++;} }

for(i=0;i<m;i++)    {if (isspace(text[i])){spacecounter++;} }

for(i=0;i<m;i++)    {if (text[i]=='.'||text[i]=='!'||text[i]=='?'){markcounter++;} }


//printf("\nm =%i\nletters= %f\nwords= %f\nsentences= %f\n",m,alphacounter,(spacecounter+1),markcounter);

int words=spacecounter+1;

float L=(alphacounter/(spacecounter+1))*100;

float S=(markcounter/(spacecounter+1))*100;

float index1 = 0.0588 * L - 0.296 * S - 15.8;
int index2=round(index1);

//printf("\nL= %f    S= %f\n",L, S);
//printf("\nindex1 = %f\n", index1);
//printf("\nindex2 = %i\n", index2);

if (index2<1){printf("\nBefore Grade 1\n");}

    else    if (1<=index2&&index2<16){printf("\nGrade %i\n", index2);}

            else    if (16<=index2){printf("\nGrade 16+\n");}

}
