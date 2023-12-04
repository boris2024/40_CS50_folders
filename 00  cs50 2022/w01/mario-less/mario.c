#include <cs50.h>
#include <stdio.h>

int main(void)
{
int h=0;
do{h=get_int("What is the pyramid's height?\n");} while (h<1||h>8);
//printf("\nStored: %i\n", h);

// the number of characters per line equals the line number starting from the top

// the outer FOR is used to locate the prompt on the line number
// the inner FOR is used to print the characters on each line

for(int i=1;i<=h;i++)

{   for(int k=(h-1);k>=i;k--)
    {
        printf(" ");
    }

    for(int j=1;j<=i;j++)
    {
        printf("#");
    }
    printf("\n");       // I break a new line after the chars are printed
}

}