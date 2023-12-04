
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Check if one command line argument is given
    if (argc != 2)
    {
        printf("Usage:./recover card.raw\n");
        return 1;
    }

    // Open file and check for NULL
    FILE *file_in = fopen(argv[1], "r");

    if (file_in == NULL)
    {
        printf("ERROR: Could not open file\n");
        return 1;
    }

    //save enough space for 8 characters
    char *name = malloc(8);

    //variable used to name jpg files
    int jpeg_no = 0;

    //save jpeg_no to name
    sprintf(name, "%03d.jpg", jpeg_no);

    //make the file called (whatever's saved in name) for writing in
    FILE * file_out = fopen(name, "w");

    unsigned char buffer[512];

    // while fread successfully reads 512 bytes into buffer
    while (fread(buffer, 1, 512, file_in) == 512)
    {
        // Check if the jpg header is present in the block being read
        if (buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 && buffer[3] >= 0xe0 && buffer[3] <= 0xef )
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

    }

    //close any open files
    fclose(file_out);
    fclose(file_in);
    //free malloc memory
    free(name);
}