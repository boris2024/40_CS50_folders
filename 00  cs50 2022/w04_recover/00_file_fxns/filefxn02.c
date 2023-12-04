#include<stdio.h>
#include<stdlib.h>

int main (void)
{
char * filename="readme.txt";

FILE *fileptr;

fileptr=fopen(filename, "r");

if(fileptr==NULL){printf("\n%s does not exist\n",filename); return 1;}

//printf("\nthe file %s is open now\n", filename);

// read 1 char at a time, display output

char character01;

printf("\n");

while ( (   character01=fgetc(fileptr)     )!=EOF  ){   putchar(character01); }

printf("\n");

fclose(fileptr);

return 0;
}