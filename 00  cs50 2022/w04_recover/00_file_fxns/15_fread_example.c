#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    // file ptr declared
    FILE * fileptr;

    // name of txt file to open: 20220921freadexample.txt

    fileptr=fopen("20220921freadexample.txt","r");

    // 201 char array declared
    char buffer[201];

    if(fileptr==NULL){  printf("\nERROR reading file, file not found\n");    return 01;  }

    else
    {   int n;
        n= fread(&buffer, sizeof(char), 20, fileptr);

        //buffer[200]=0;
        printf("\nthis is how many char were read from file: %d",n);
        printf("\n%s\n",buffer);
        fclose(fileptr);

    }

    int buffersize=sizeof(buffer);

    printf("\nsize of buffer is %d bytes\n", buffersize);

}