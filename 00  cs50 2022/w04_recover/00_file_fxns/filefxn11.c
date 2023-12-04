#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char id[4];
    char fname[16];
    char lname[16];
} s_employee;

int main(void)
{
    // populate struct variables

    s_employee employee[]=
    {   {"8861", "Perla", "Perez"},
        {"8862", "Celeste","Barboza"},
        {"8892", "Miranda", "Barboza"}
    };

    FILE * fileptr=NULL;

    //create and open the text file
    fileptr=fopen("00003test.txt","w");

    if(fileptr==NULL){  printf("\nERROR creating file");   return 1;   }

    //write the struct in the file

    fwrite(&employee, sizeof(employee), 1, fileptr);

    fclose(fileptr);
}