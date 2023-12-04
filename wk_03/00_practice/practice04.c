#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// practice from https://www.programiz.com/c-programming/c-structure-function
// passing structs to functions as arguments

struct people
{
    string name;
    int height;
    int mass;
};

int calculate(struct people student01);

int main(void)
{
    struct people student01;
    int massindex;

    //student01.name=get_string("enter your name, then hit ENTER : ");

    student01.height=get_int("enter your height in cm, then hit ENTER : ");

    student01.mass=get_int("enter your body mass in kg, then hit ENTER : ");

    massindex=calculate(student01);

    printf("\nmassindex: %d \n",massindex);

}// MAIN ENDS HERE

int calculate(struct people student01)
{
    int result;
    int height= student01.height;
    int mass= student01.mass;

    result= height*mass;

    return result;
}