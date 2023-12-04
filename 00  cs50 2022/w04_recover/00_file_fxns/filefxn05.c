#include<stdio.h>
#include<stdlib.h>

// 1. C program to read name and marks of n number of students and store them in a file.


int main(void)
{
char name[50];

int mark, i, number;

printf("\nenter number of studens: \n");
scanf("%d",&number);

FILE * fileptr;

fileptr=(fopen("student013.txt","w"));

if  (fileptr==NULL) {printf("\nsuch file does not exist\n"); return 1;}

for(i=1; i<number+1; i++)
{
    printf("\nfor student %d, enter name: ",i);
    scanf("%s",name);

    printf("\nenter marks: ");
    scanf("%d", &mark);

    fprintf(fileptr, "\nname: %s  \nmark: %d\n", name, mark);

}

fclose(fileptr);

}