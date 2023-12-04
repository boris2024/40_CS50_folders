#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("invalid argc size\n");
        return 1;
    }

    // open memory card
    FILE *raw_file = fopen(argv[1], "r");

    // make sure memory address was successfully allocated to raw_file
    if (raw_file == NULL)
    {
        printf("memory was not allocated to raw_file\n");
        return 1;
    }

    // create buffer, and create constant value for the block size to be read
    const int BLOCK_SIZE = 512;
    typedef uint8_t BYTE;
    BYTE buffer[BLOCK_SIZE];

    // make a pointer for the current file that is being modified:
    FILE *current_file = NULL;

    // count number of jpeg files
    int jpeg_count = 0;

    // repeat process until end of card
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        // check buffer and if it is start of new jpeg (if it is)
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // allocate space for filename
            char filename[8];
            // first jpg
            if (jpeg_count == 0)
            {
                sprintf(filename, "%03i.jpg", jpeg_count);
                FILE *img = fopen(filename, "w");
                current_file = img;
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
                jpeg_count += 1;
            }
            // else, we need to close the previous file first before creating a new file
            else
            {
                fclose(current_file);
                sprintf(filename, "%03i.jpg", jpeg_count);
                FILE *img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
                jpeg_count += 1;
            }

        }
        // else
        else
        {
            if (jpeg_count > 0) // THIS WAS THE PROBLEM
            {
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, current_file);
            }
            // if already found jpeg keep writing to it
        }
    }
    // close any remaining files
    fclose(raw_file);
    fclose(current_file);
    return 0;
}