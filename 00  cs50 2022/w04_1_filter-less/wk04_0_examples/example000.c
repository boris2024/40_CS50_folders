#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main (void)
{
    char *s= get_string("\ns=");
    char *t= get_string("\nt=");

    if(strcmp(s,t)==0)
    {
        printf("\nsame\n");
    }

    else    {printf("\ndifferent\n");}
}