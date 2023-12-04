#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    for(int i=0; i<6; i++)
    {
        char text2[30];

        sprintf(text2, "%03d.jpg", i);

        char * filename2=text2;

        printf("%s\n", filename2);

    }
}