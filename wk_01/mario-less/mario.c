#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;

    do{  h=get_int("What is the pyramid's height? ->"); } while
    ( h<=0 || h>=9 );

    //printf("\nheight= %i", h);
    //printf("\n");

    for(int i=1; i<=h; i++)
    {
        for(int j=h-i; j>=1; j--)
        {
            printf(" ");
        }

    /*
        for(int j=1; j<=i; j++)
        {
            printf("#");
        }
        printf("XXXXX\n");
    */

    }

}   // MAIN ends here