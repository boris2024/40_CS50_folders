#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include<stdbool.h>


int main(int argc, char *argv[])
{


    if(argc!=2)
    {
        printf("\ncorrect use:./recover card.raw\n");
        return 1;
    }

    FILE *file_in=fopen(argv[1],"r");

    if(file_in==NULL)
    {
        printf("\ncould not open file to read data\n");
        return 1;
    }


    // solving the file name issue

    char *names=malloc(sizeof(char)*400);

    if(names==NULL)
    {
        printf("\nERROR during memory allocation\n");
        return 1;
    }

    for(int i=0; i<50; i++)
    {
        sprintf(names+8*i,"%03d.jpg",i);
    }
    // file names issue...solved ?


    // test[512] is the buffer into which I read data from each 512-byte block

    typedef uint8_t BYTE;

    BYTE signature[3], test[512], test2[512];

    signature[0]=255, signature[1]=216, signature[2]=255;

    bool A1=false, A2=false, B1=false, B2=false;

    int count=0,    jpeg_count=0;

    int block_size=512;

    while( fread(test,1, block_size,file_in)==block_size )
    {
        count++;

        if(test[0]==signature[0] && test[1]==signature[1] && test[2]==signature[2])
        {   A1=true;    }

        if(test[3]==224 || test[3]==225 || test[3]==226 || test[3]==227 || test[3]==228 || test[3]==229 || test[3]==230 || test[3]== 231 || test[3]==232 || test[3]==233 || test[3]==234 || test[3]==235 || test[3]==236 || test[3]==237 || test[3]==238 || test[3]==239)
        {   A2=true;    }

        if(A1==true&&A2==true)
        {
            jpeg_count++;
        }

        printf("\n512-byte block counter= %d\njpeg_count= %d\n",count,jpeg_count);

        if(jpeg_count==49)
        {
            printf("\nbreak! activated\n");
            break;
        }

    }


    free(names);
    fclose(file_in);

}// MAIN ends here