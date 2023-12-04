#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

// this program implements a variable size array,
// the number of elements is specified at run time

int main (void)
{
int * list= malloc(3*sizeof(int));

// check if you ran out of memory
if (list==NULL){printf("\nERROR, ran out of memory"); return 1;}

// these are actually ptr variables
list[0]=1;
list[1]=2;
list[2]=3;

printf("\n");
for (int i=0; i<3; i++)
{
    printf("%p\n", &list[i]);
}


printf("\n");
for (int i=0; i<3; i++)
{
    printf("%lu\n", sizeof(list[i]));
}


// create an int ptr variable of size 16 bytes

int * temp = malloc(4*sizeof(int));

// check if memory ran out of space

if (temp==NULL){    free(list); // if memory fails, free previous mem assigment also
                    printf("ERROR, memory ran out of space");
                    return 2;}

// copy list of size 3 into list of size 4

for (int i=0; i<3; i++)
{
    temp[i]=list[i];
}

printf("\n");
for (int i=0; i<3; i++)
{
    printf("%p\n", &temp[i]);
}




// add number to 4th element of array temp
temp[3]=4;

// free ptr variable list
free(list);

//


    list[1] = temp[1];



for (int i=0; i<4; i++)
{
    printf("list[%d]= %d\n", i, list[i]);
}

//free (list);
free (temp);

}