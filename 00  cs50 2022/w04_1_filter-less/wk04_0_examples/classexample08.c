#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
FILE *file =fopen("phonebook.csv","a");
if (!file)
{
    return 1;
}

string name=get_string("\nName: ");
string number=get_string("\nNumber: ");

fprintf(file, "%s,%s\n", name, number);

fclose(file);

}