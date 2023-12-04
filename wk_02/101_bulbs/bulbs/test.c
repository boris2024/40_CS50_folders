#include<stdio.h>
#include<cs50.h>

int main(void)
{

    int alphabet[95];

    for(int i=0; i<95; i++)
    {
        alphabet[i]=i+32;
    }

    for(int i=0; i<95; i++)
    {
        printf("\narray [%i], content = %i", i, alphabet[i]);
    }

    printf("\n\n");
}