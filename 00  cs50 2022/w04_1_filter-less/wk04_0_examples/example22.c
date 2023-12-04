#include<stdio.h>
#include <stdlib.h>
int main() {

    int* ptr1;

    //! We want ptr1 to store the space of 3 integers
    ptr1 = (int*) malloc (3 * sizeof(int));

    //! check the address assigned to ptr1 is NOT NULL
    if(ptr1==NULL){  printf("\nMemory not allocated. \n");   }

    else{   printf("\nMemory allocated succesfully. \n");     }


    //! This statement shows where memory is allocated, here ptr1 is an array
    printf("\nThe address of the pointer is:%p\n ", ptr1);

    //! Here we assign values to the ptr1 created
    for(int i=0;i<3;i++)
    { ptr1[i] = i;  }

    //! Printing the values of ptr1 to show memory allocation is done
    for(int i=0;i<3;i++)
    { printf("%d\n", ptr1[i]);
      printf("%p\n", &ptr1[i]);
    }

}