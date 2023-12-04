#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    // this time, try not to use pointers and dynamic memory allocation (malloc)

    int x=65;
    int y=77;

    FILE * filepointer1;

    char * filename="005_example.txt";

    filepointer1=fopen(filename,"w");

    if(filepointer1==NULL){ printf("\nERROR creating file"); return 1; }

    fwrite( &x, sizeof(int), 1, filepointer1);

    printf("\nInteger %d was written to file %s \n", x, filename);

    // ok, now...read from the file and move the data into memory

    fclose(filepointer1);

    // part 2 of the problem starts here

    FILE * filepointer2;
    filepointer2=fopen(filename,"r");

    if(filepointer2==NULL){ printf("\nERROR creating file"); return 1; }

    fread( &y , sizeof(int)  , 1  ,filepointer1 );

    printf("\ninteger %d was read from %s into memory\n", y, filename);

    fclose(filepointer2);


}