#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    int a;
    int x[4];

    for(a=0; a<4;a++)
    {
        printf("\nx[%i] is stored in %p",a,&x[a]);
    }
    printf("\n");
    printf("\nthe address for x is %p",&x);
    printf("\nthe address for a is %p", &a);
    printf("\n");
}