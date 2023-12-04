#include<stdio.h>

int main(void)
{
    char * S="elizabeth_nelson_still!";

    //printf("\n%s\n",S);

    //printf("\n%p\n",&S);

    for(int a=0; a<=27; a++)
    {
        printf("\ns[%d]=%p\n",a,&S[a]);
        printf("\ns[%d]=%c\n",a,S[a]);
    }

}