
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Check if one command line argument is given
    if (argc != 2)
    {
        printf("Usage: ./recover image file\n");
        return 1;
    }

    // Open file and check that it exists
    FILE *file_in = fopen(argv[1], "r");

    if (file_in == NULL)
    {
        printf("ERROR, can't open original file\n");
        return 1;
    }

    //save names of files in ptr called name
    char *name = malloc(8);

    //for naming the files numbers
    int jpeg_no = 0;

    //save number.jpg to name
    sprintf(name, "%03d.jpg", jpeg_no);


    // you can open a file and assign to a file pointer before finding the jpg header
    FILE * file_out = fopen(name, "w");

    //initialize the buffer to read blocks into
    unsigned char buffer[512];

    bool A1=false, A2=false;

    // while fread successfully reads 512 bytes into buffer
    while (fread(buffer, 1, 512, file_in) == 512)
    {
        // Check if the buffer contains the start of an image and make a new one if it does
        if (buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255){  A1=true;    }

        if (buffer[3]==224 || buffer[3]==225 || buffer[3]==226 || buffer[3]==227 || buffer[3]==228 || buffer[3]==229 || buffer[3]==230 || buffer[3]== 231 || buffer[3]==232 || buffer[3]==233 || buffer[3]==234 || buffer[3]==235 || buffer[3]==236 || buffer[3]==237 || buffer[3]==238 || buffer[3]==239)
        {  A2=true;    }

        if(A1==true&&A2==true)
        {
            if (jpeg_no > 0)
            {
                fclose(file_out);
                sprintf(name, "%03d.jpg", jpeg_no);
                file_out = fopen(name, "w");
                jpeg_no++;
            }

            else
            {
                fclose(file_out);
                sprintf(name, "%03d.jpg", jpeg_no);
                file_out = fopen(name, "w");
                jpeg_no++;
            }


        }

        fwrite(&buffer, 512, 1, file_out);

        if(jpeg_no==50)break;
    }

    //close any open files
    fclose(file_out);
    fclose(file_in);
    //free malloc memory
    free(name);
}