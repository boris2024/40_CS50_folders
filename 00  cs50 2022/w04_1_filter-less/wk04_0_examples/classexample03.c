#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s;    //! here I declare s as a pointer
    s=get_string("\ns: ");

    //printf("\ns: %s\n",s);

    char *t=malloc(strlen(s)+1);

    if(t==NULL){return 1;}

    strcpy(t,s);

    if(strlen(t)>0)
    {   t[0]=toupper(t[0]); }

    printf("\ns= %s",s);
    printf("\nt= %s",t);
    printf("\n");

    free(t);

}