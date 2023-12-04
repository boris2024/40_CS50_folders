#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include<stdbool.h>


int main(int argc, char *argv[])
{
    if(argc!=2)
    {   printf("\ncorrect use:./recover card.raw\n");   return 1;}

    FILE *file_in=fopen(argv[1],"r");

    if(file_in==NULL)
    {   printf("\ncould not open file to read data\n"); return 1;}


    // declare pointer that represents file to write to
    FILE * file_out=NULL;


    // solving the file name issue
    char *names=malloc(400);

    if(names==NULL)
    {   printf("\nERROR during memory allocation\n");   return 1;
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

    int block_size=512, jpg_counter=-1;

    int iteration=0;

    // iterate reading blocks of 512 bytes each
    while(1)
    {

        // x represents the number of elements read from the file into the buffer called "test"
        int x=0;
        x=fread(test,1,block_size,file_in);

        if(x<512)break;

        // check for jpg files

        if(test[0]==signature[0] && test[1]==signature[1] && test[2]==signature[2])
        {   A1=true;    }

        if(test[3]==224 || test[3]==225 || test[3]==226 || test[3]==227 || test[3]==228 || test[3]==229 || test[3]==230 || test[3]== 231 || test[3]==232 || test[3]==233 || test[3]==234 || test[3]==235 || test[3]==236 || test[3]==237 || test[3]==238 || test[3]==239)
        {   A2=true;    }

        if(A1==true&&A2==true)
        {   jpg_counter++;  }

        // if this the first jpg ....
        if(jpg_counter==0)
        {
            file_out= fopen(names+8*jpg_counter,"w");

            if(file_out==NULL)
            {
                printf("\ncould not open file to write data 100\n");
                return 1;
            }

            // write the first block of the first file
            fwrite(test, 1, x,file_out);

            // now, keep reading and writing and look for next jpg to activate fclose
            while(1)
            {
                int y;
                y=fread(test,1,512,file_in);

                if(test[0]==signature[0] && test[1]==signature[1] && test[2]==signature[2])
                {   B1=true;    }

                if(test[3]==224 || test[3]==225 || test[3]==226 || test[3]==227 || test[3]==228 || test[3]==229 || test[3]==230 || test[3]== 231 || test[3]==232 || test[3]==233 || test[3]==234 || test[3]==235 || test[3]==236 || test[3]==237 || test[3]==238 || test[3]==239)
                {   B2=true;    }

                if(B1==true&&B2==true)
                {   break;  }

                else
                {   fwrite(test, 1, 512,file_out);  }
            }
        }   // case for 000.jpg ends here


        // if jpeg_counter is >0 (this is not the first jpg)
        else
        {
            if(jpg_counter>0)
            {
                fclose(file_out);

                file_out= fopen(names+8*jpg_counter,"w");

                if(file_out==NULL)
                {
                    printf("\ncould not open file to write data 200, jpeg_counter = %d\n",jpg_counter );
                    return 1;
                }

                fwrite(test, 1, x,file_out);

                while(1)
                {
                    int z;
                    z=fread(test,1,512,file_in);

                    if(test[0]==signature[0] && test[1]==signature[1] && test[2]==signature[2])
                    {   B1=true;    }

                    if(test[3]==224 || test[3]==225 || test[3]==226 || test[3]==227 || test[3]==228 || test[3]==229 || test[3]==230 || test[3]== 231 || test[3]==232 || test[3]==233 || test[3]==234 || test[3]==235 || test[3]==236 || test[3]==237 || test[3]==238 || test[3]==239)
                    {   B2=true;    }

                    if(B1==true&&B2==true)
                    {   break;  }

                    else
                    {   fwrite(test, 1, 512,file_out);  }
                }
            }
        }

    iteration++;

    }

    free(names);
    fclose(file_in);

}// MAIN ends here
