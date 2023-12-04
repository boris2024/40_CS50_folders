#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>

int main(void)
{
/*
    the code below creates a seg fault, you may compile it but it won't run

    char * text="celesteymiranda";

    text[0]='C';
    */

    char a[]="Celeste y Miranda";

    char b='c';

    char * text=a;

    a[0]='2';   text[1]='3';

    printf("%s",a);



   // char * text =;




}