#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    char *s=get_string("enter string s: ");

    if(s==NULL){    return 1;   }

    // allocate memory for another string

    int n=strlen(s);

    char *t=malloc(4*(n+1));

    if(t==NULL){    return 1;   }

    strcpy(t,s);

    if(n>0)
    {
        t[0]=toupper(t[0]);
    }

    printf("\npointer s address = %p, string stored in memory = %s", s,s);
    printf("\npointer t address = %p, string stored in memory = %s\n", t, t);

    free(t);
}