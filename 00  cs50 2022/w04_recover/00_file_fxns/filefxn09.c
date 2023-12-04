#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
int data=654566;

FILE * fileptr;

fileptr=fopen("06family.txt","w");

if (fileptr==NULL){ printf("\nERROR creating file\n");    return 1;   }

int w=fwrite(&data, sizeof(data),1,fileptr);

printf("%d",w);

fclose(fileptr);
}