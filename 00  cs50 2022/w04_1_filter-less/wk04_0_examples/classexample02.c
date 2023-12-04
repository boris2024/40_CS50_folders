#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s=get_string("\ns= ");

    char *t=malloc(strlen(s)+1);

    strcpy(t,s);        //! copy s characters into t, one by one

    t[0]=toupper(t[0]);

    printf("\ns:%s ",s);
    printf("\nt:%s \n",t);

    free(t);

}