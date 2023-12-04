// Modifies the volume of an audio file

// 20230506
// there is more than 1 way to do this la problem.
// this is my attempt to solve this problem following a different approach,
// this time using malloc AND knowing (beforehand) how many bytes to read / write

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)  {   printf("Could not open file.\n");   return 1;   }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {   printf("Could not open file.\n");   return 1;   }

    float factor = atof(argv[3]);


    // TODO: Copy header from input file to output file
    // declare buffer to hold same data type that makes up the header in wav files
    uint8_t buffer1[HEADER_SIZE];

    // step 1, read HEADER from input file to buffer1
    fread(buffer1, 1, HEADER_SIZE, input);

    // step 2, write HEADER from buffer1 to output
    fwrite(buffer1, 1, HEADER_SIZE, output);


    // TODO: Read samples from input file and write updated data to output file

    // I downloaded the file and read number of bytes it takes in my disk

    int j= (352844-44)/2;

    int16_t * buffer2=malloc(sizeof(int16_t)*j);

    int items01= fread(buffer2, 2, j, input);

    for(int i=0; i<j;i++)
    {
        buffer2[i]=buffer2[i]*factor;
    }

    int items02= fwrite(buffer2, 2, j, output);
    printf("items read= %d\nitems written= %d\n", items01, items02);
/**/
    // Close files and free malloc

    free(buffer2);
    fclose(input);
    fclose(output);
}
