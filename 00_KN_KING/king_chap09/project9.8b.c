#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>

/* 20221213
this is a test written by alvaro to determine the distribution of results when 2 dice are rolled
*/

int main(void)
{
int sum, counter=0;

int dice1[]={1,2,3,4,5,6};
int dice2[]={3,5,1,4,2,6};
int results[36];

// scores and frequency share same element index
int scores[]={2,3,4,5,6,7,8,9,10,11,12};
float frequency[11]={0};
float probability[11]={0};

for(int i=0; i<=5; i++)
{
    for(int j=0; j<=5; j++)
    {
        sum=dice1[i]+dice2[j];
        results[counter]=sum;
        counter++;
        //printf("\nroll dice %d, %d",counter, sum);
    }
}

/*
printf("\n");
for(int i=0; i<36; i++)
{printf("\n result %d = %d",i, results[i]);}
*/

// now find frequency distribution for each possible result

printf("\n");

for(int i=0; i<11;i++)
{
    for(int j=0;j<36; j++)
    {
        if(scores[i]==results[j]){frequency[i]++;}
    }
}

for(int i=0; i<11; i++)
{
    probability[i]=100*frequency[i]/36;
}


//printf("\n");
for(int i=0; i<11;i++)
{
printf("\nsum = %d, frequency[%d] = %0.0f  probability[%d] = %2.2f", scores[i], i, frequency[i], i, probability[i]);
}

printf("\n\n");

}// MAIN ends here
