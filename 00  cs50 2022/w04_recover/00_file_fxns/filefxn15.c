#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// this is an example of the application of the fwrite fxn

int main(void)
{

    // I hereby declare and initialize an array called data

    char * data[]={"65","66"," 121"," 311"};

    printf("\n");

    for(int i=0; i<4; i++)  {   printf("%s ", data[i]);   }

    printf("\n");



    // declare a file pointer
    FILE * fileptr;

    fileptr=fopen("14_family.txt","w");

    if(fileptr==NULL){  printf("\nthere was an ERROR, file not created\n");
                        return 1;   }

    // inside the fwrite, using &data[] and data yields same result..but why ?

    for(int x=0; x<4;x++)
    {
        fwrite(data[x], sizeof(int), 1, fileptr);
    }

    //fwrite(&data, sizeof(data), 1,fileptr  );

    fclose(fileptr);


}