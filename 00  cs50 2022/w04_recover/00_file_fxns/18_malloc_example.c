#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    // I hereby declare an int pointer
    int * p;

    // by using malloc I'm assigning memory to pointer p
    p=malloc(sizeof(int));

    // since I already assigned memory to p, I can dereference it
    *p=65;

    // I hereby declare a fileptr
    FILE * fileptr1;

    fileptr1=fopen("001_readme.txt","w");

    if(fileptr1==NULL){ printf("\nERROR, file was not created"); return 1; }

    // notice first argument of fwrite is a pointer (from p = &x)
    fwrite(p, sizeof(int), 1,  fileptr1);

    fclose(fileptr1);

    printf("\nThe value of p written into the txt file is %d\n", *p);

    // I hereby declare another int pointer

    int * q;
    // assign memory to the new pointer
    q=malloc(sizeof(int));

    FILE * fileptr2;
    fileptr2=fopen("001_readme.txt","r");

    char * name ="001_readme.txt";

    fread( q, sizeof(int),  1  , fileptr2 );

    printf("\nthe value read from %s is: %d\n", name, *q );

    fclose(fileptr2);

    free (p), free(q);

}