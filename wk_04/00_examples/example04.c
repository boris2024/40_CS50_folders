#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>

int main (void)
{
    char * s=malloc(1);
    printf("enter content of the string: ");
    scanf("%s",s);
    printf("\ns= %s\ns= %p\n", s, s);

    free(s);
}