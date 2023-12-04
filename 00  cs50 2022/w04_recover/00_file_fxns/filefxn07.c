#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// this is an example of using fprint

int main(void)
{
FILE * fileptr;

char * message= "I have 2 nieces and a nephew";

int length= 0;

fileptr =fopen ("01family.txt","w");

if(fileptr==NULL){  printf("\nERROR creatig file");
                    return 1;   }

length=strlen(message);

fprintf(fileptr, "\n%d\n%s",length, message);

fclose(fileptr);



}