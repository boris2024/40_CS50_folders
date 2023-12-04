#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(void)
{
    string s=get_string("s: ");

    string t=s;

    printf("\ns: %s\n",s);
    printf("\nt: %s\n",t);

    //t[0]=toupper(t[0]);

    //! who said s and t were pointers ?? they are an array of char
    printf("\ns address: %p\n",s);
    printf("\nt address: %p\n",t);

    //printf("\n");
}