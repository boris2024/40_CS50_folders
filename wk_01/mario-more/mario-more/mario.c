#include <cs50.h>
#include <stdio.h>

int main(void)
{
   int h=10;

   while(h<1 ||  h>8)
   {
    h=get_int("pyramid's height =");
   }

    // the outer for loop controls position of the printing along the pyramid's height
   for(int i=1; i<=h; i++)
   {
    // the inner loop controls what happens on each line, what gets printed
    // this for loop prints left side blank space
    for(int j=h-(i+1); j>=0; j--)
    {
        printf(" ");
    }

    for(int j=1; j<=i ; j++  )
    {
        printf("#");
    }

    printf("  ");

    for(int j=1; j<=i  ; j++  )
    {
        printf("#");
    }

    printf("\n");

   }
}