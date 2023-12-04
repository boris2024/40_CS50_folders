#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{

char girl[]= "c3l4ste";

printf("\n");

for( int i=0; i<7; i++)
{   printf("%c ",girl[i]);
}
printf("\n");

FILE * fileptr;

fileptr=fopen("03_family.txt","w");

if (fileptr==NULL){ printf("\nERROR, could not read file\n");
                    return 1;   }

for(int i=0; i<1;i++)
{
    fwrite(&girl[i] ,7*sizeof(char), 7,fileptr   );
}

fclose(fileptr);

}