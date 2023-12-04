#include<cs50.h>
#include<stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int wordsize = 0;

    // ensure argv[1] is either 5, 6, 7, or 8 and store that value in wordsize instead
    // TODO #2

    string k=argv[1];
    wordsize=atoi(k);

    printf("\nwordsize= %d\n", wordsize);
}
