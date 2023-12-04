#include<stdio.h>
#include<stdint.h>
#include<cs50.h>

int main(int argc, string argv[])
{
    if (argc!=2)
    {
        printf("\nusage:  ./example10pdf filename\n");
        return 1;
    }

    // open file: create FILE pointer and use fopen
    FILE * fileptr=fopen(argv[1],"r");

    // check if file exists
    if(fileptr==NULL)
    {
        printf("\nerror opening file\n");
        return 1;
    }

    // create buffer (temp storage), to store the first 4 int read from pdf file
    // uint8_t is the datatype for the 4 first int we will read from the pdf file

    uint8_t buffer[]={11,11,11,11};

    // this is the signature values for pdf
    uint8_t signature[]={37,80,68,70};

    fread(buffer,1,4,fileptr);



    // lets look inside the buffer array, at the content of each element

    printf("\n");

    for(int j=0; j<4; j++)
    {
        printf("buffer [%d]= %d\n",j, buffer[j]);
    }

/*

    int count=0;

    for(int i=0; i<4; i++)
    {
        if(signature[i]!=buffer[i])
        {
            count++;
        }
    }

    if(count==0)
    {
        printf("\nthis is a pdf !!\n");
    }
    else
    {
        printf("\nthis is not a PDF\n");
    }
*/
    fclose(fileptr);

} // MAIN ends here