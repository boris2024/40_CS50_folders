#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s=get_string("\ns: ");

    char *t=malloc(strlen(s)+1);

    int n= strlen(s)+1;

    for(int i=0; i<n; i++)
    {   t[i]=s[i];       }

    t[0]=toupper(t[0]);

    printf("\ns: %s", s);
    printf("\nt: %s", t);
    printf("\n");

    free(t);
}