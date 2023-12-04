#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    char *s=get_string("what is your first name? ");

    int n = strlen(s);

    printf("\nnumber of characters in s pointer is n= %d\n",n);

    char *t=malloc(4*(n+1));

    strcpy(t,s);

    /*
    for(int i=0; i<n+1; i++)
    {
        t[i]=s[i];
    }
    */

    t[0]=toupper(t[0]);

    printf("\naddress of pointer s = %p, the actual value is %s",s, s);
    printf("\naddress of pointer t = %p, the actual value is %s\n",t,t);

    free(t);
}
/*
if(n>0)
    {

        t[0]=toupper(t[0]);

    }
*/