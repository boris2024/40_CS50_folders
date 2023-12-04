#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <string.h>

typedef uint8_t BYTE;

int main(int argc, char * argv[])
{
    // Check usage
    if (argc != 2)  {   printf("\nUsage: ./recover IMAGE\n");
                        return 1;   }

    char * filename= argv[1];

    FILE * fileptr = fopen(filename, "r");


    // here I check the return value, make sure you don't get NULL
    if (fileptr==NULL)      {       printf("\ncan't open file\n");
                                    return 1;   }

    // the number of bytes to read in each block  is 512 bytes
    // hereby I declare an array, elements type BYTE.
    const int BLOCK_SIZE = 512;
    BYTE buffer[BLOCK_SIZE];

    //  this variables are just to count within certain conditions,
    //  and check if the code is doig what I want

    int     totalblocks=0;
    int     njpeg=0;
    int     noheaderblock=0;

    // string where I plant to store name to assign to jpeg files


    FILE * currentfile= NULL;

    while(  fread(&buffer, sizeof(BYTE), BLOCK_SIZE, fileptr)==BLOCK_SIZE )
    {

    if  ( ( buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff) &&
        ( (buffer[3] & 0xf0) == 0xe0 )  )
        {
            char text[10];

            // if this is the first jpg file
            if(njpeg==0)
            {
                sprintf(text, "%03d.jpg", njpeg);
                currentfile= fopen(text,"w");

                fwrite( buffer, 1, 512, currentfile );
                njpeg++;
                printf("\nno. of jpeg blocks read= %d", njpeg);

            }

            // for all other jpegs after the first one
            else
            {
                //if (currentfile!=NULL){fclose(currentfile);}
                fclose(currentfile);

                sprintf(text, "%03d.jpg", njpeg);

                currentfile= fopen(text,"w");

                fwrite( buffer, 1, 512, currentfile );
                njpeg++;
                printf("\nno. of jpeg blocks read= %d", njpeg);
            }

        }

        else
        {   if(njpeg>0)
            fwrite( buffer, sizeof(BYTE), 512, currentfile );

        }

    }

    fclose(fileptr);
    fclose(currentfile);
    //

    printf("\ntotal no. of jpeg blocks read= %d\n", njpeg);


}