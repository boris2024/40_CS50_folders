#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main (void)
{
    int c, *pc;

    c=22;
    printf("\nvalue of c= %i",c);
    printf("\nthe address where c is stored: %p",&c);
    printf("\n");

    //! in this expression the pointer is pc
    pc=&c;
    printf("\nthe address stored in pointer pc= %p",&c);
    printf("\nthe address stored in pointer pc= %p",pc);
    printf("\nthe content of pointer pc is %i",*pc);
    printf("\n");

    c=11;
    printf("\nthe address of pointer pc= %p", pc);
    printf("\nthe address of pointer pc= %p", &c);
    printf("\nthe content of pointer pc= %i", *pc);
    printf("\n");


    //! since pointer pc stores the address of var c,
    //! then we can change the contet of var c using *pc

    *pc=2;
    printf("\nthe address of c is: %p",pc);
    printf("\nthe value of c=%i",*pc);
    printf("\nthe value of c=%i",c);
    printf("\n");
}