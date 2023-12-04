#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    int data[]={65,66,67,68,69};

    FILE * fileptr;

    fileptr=fopen("001test.txt","w");

    if (fileptr==NULL){ printf("\nERROR, file was not created\n");
                        return 1;   }

    fwrite(&data, sizeof(data), 1, fileptr);

    fclose(fileptr);

}