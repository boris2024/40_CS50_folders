#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// practice from https://www.programiz.com/c-programming/c-structure-function
// passing structs to functions as arguments

typedef struct student
{
    string name;
    int grade;
} studentdata;

// function prototype

void display(studentdata mystudent);

int main(void)
{
    // create variable student1 of type struct student
    studentdata student01;

    student01.name=get_string("\nwrite student's name, then press ENTER : ");

    student01.grade=get_int("\nwrite student's grade, then press ENTER : ");

    display(student01);

}// MAIN ends here

void display(studentdata mystudent)
{

    printf("\nstudent's name = %s", mystudent.name);
    printf("\nstudent's grade = %d", mystudent.grade);
    printf("\n\n");
}