#include<stdio.h>
#include<stdlib.h>

int main(void)
{

// I hereby declare variable fileptr a FILE pointer
FILE * fileptr;

// I hereby declare filename as a pointer varible to a string of characters
char * filename="20220904_example.txt";

fileptr=fopen(filename,"r");

if (fileptr==NULL)  {   printf("\nfile %s does not exist\n",filename);
                        return 1;   }

// read 1 character at a time from content of text file, print to terminal
printf("\n");
char x;
while ( (   x=fgetc(fileptr)    )   !=EOF   ) putchar(x);
printf("\n");

fclose(fileptr);

}