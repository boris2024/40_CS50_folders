#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];

    // Create array to store plate numbers
    char *plates[8];

    // allocate memory for each element in plates[] array
    // check if there were any errors in the allocation of memory to plates[] elements
    for(int i=0; i<8; i++)
    {
        plates[i]=malloc(7*4);

        if(plates[i]==NULL){    return 1;   }
    }

    FILE *infile = fopen(argv[1], "r");

    // check for error in fopen

    if(infile==NULL)
    {
        return 1;
    }

    int idx = 0;

    printf("\n");

    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        //printf("\n");

        //printf("data stored in buffer = %s\nbuffer address = %p\n", buffer, buffer);
        //printf("\n");

        // Save plate number in array

        // ATTENTION, in the expression below you are passing a memory address,
        // from a pointer variable to another
        // you actually need to pass the data stored in buffer, not its address

        //plates[idx] = buffer;

        strcpy(plates[idx], buffer);

        //printf("buffer address =   %p\n", buffer);
        //printf("inside plates [idx] = %s\n", plates[idx]);
        //printf("plates [idx] pointer =   %p\n\n\n", plates[idx]);

        idx++;

    }

    printf("\n");


    for (int i = 0; i < 8; i++)
    {   //printf("plates [ %d ] pointer =   %p\n", i, plates[i]);
        printf("%s\n", plates[i]);
    }


    // free memory allocated to elements of plates[]

    for(int i=0; i<8; i++)
    {
        free(plates[i]);
    }

    fclose(infile);
}
