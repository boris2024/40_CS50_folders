#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
FILE * fileptr;

char testarray[24]={0};

fileptr=fopen("00family.txt","r");

if (fileptr==NULL){     printf("ERROR, file was not created");
                        return 1;    }

fread( &testarray, sizeof(char), 24, fileptr);

puts(testarray);

fclose(fileptr);

for(int i=0; i<=10; i++)
{
    printf("\n%c",testarray[i]);
}



}