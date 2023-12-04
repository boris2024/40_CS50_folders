#include<cs50.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

/*
20221130
from KN KINGS "C programming, a modern approach"
this program solves exercises 8.2.8 and 8.2.9
*/

int main(void)
{
int i=30,j=24;
float temperature_readings[i][j];
float sum=0;

// i represents each day in a 30-day month, rows
// j represents every hour each day, columns

for(i=0; i<30; i++)
{
    for(j=0; j<24; j++)
    {
        temperature_readings[i][j]=1;
    }
}

for(i=0; i<30; i++)
{
    for(j=0; j<24; j++)
    {
        sum = sum+temperature_readings[i][j];
    }
}

printf("\n");
printf("average temperature of 30_day month over 24 hrs = %0.2f",sum/720);
printf("\n");

return 0;
}// MAIN ends here