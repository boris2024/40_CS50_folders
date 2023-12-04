#include<stdio.h>
#include<stdlib.h>

# define MAX_SIZE 32

int main(void)
{
FILE * fileptr;
fileptr=NULL;

char buffer[MAX_SIZE]={0}   ;

printf("\nEnter your name: ");
fgets(buffer,MAX_SIZE,stdin);

fileptr=fopen("aticleworld.txt","w");

if(fileptr==NULL){   printf("\nERROR creating file");  return 1;}

fwrite(buffer, sizeof(buffer[0]), MAX_SIZE, fileptr );

fclose(fileptr);

printf("\nfile was created");

}