#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// reading files using fread and txt files

int main(void)
{

    FILE * fileptr;

    char * filename="20220921_04_sample.txt";

    fileptr=fopen("20220921_04_sample.txt","r");


    char * buffer[200];

    for( int i=0; i<200;i++)
    {
        buffer[i]="a";
    }

    printf("\n");
    for(int i=0; i<20;i++)
    {printf("%s",buffer[i]);}
    printf("\n");

    if(fileptr==NULL)   {   printf("\nERROR, file was not read\n");
                            return 1;   }


    for(int i=0; i<20; i++)
    {
        fread(&buffer, sizeof(char), 1, fileptr);
    }


    fclose(fileptr);

    printf("\n");
    for(int i=0; i<20;i++)
    {printf("%s",buffer[i]);}
    printf("\n");

}