#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

typedef struct Pers_data
{
    int mass;
    int height;
} mydata;

int main(void)
{
    // here we use the alias for struct Pers_data
    mydata person01, person02;

    person01.mass=80;
    person01.height=170;

    person02.mass=75;
    person02.height=180;

    printf("\nmass= %i kg", person01.mass);
    printf("\nheight= %i cm", person01.height);
    printf("\n");

}