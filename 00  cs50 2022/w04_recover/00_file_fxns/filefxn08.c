#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// this is an example of using fwrite

int main (void)
{
FILE * filepointer;

char * message = "I have 2 nieces and a nephew, Celeste, Miranda, Diego";

int length=0;

filepointer=fopen("04family.txt","w");

if (filepointer==NULL)  {   printf("ERROR creating the file");
                            return 1;   }

length=strlen(message);
printf("\n%d",length);

// this sentence is for writing the no. of char of message in the file

//fwrite(&length, sizeof(int), 2,filepointer);

int a=fwrite (message, sizeof(char), length, filepointer);

printf("\n%d",a);
fclose(filepointer);

}