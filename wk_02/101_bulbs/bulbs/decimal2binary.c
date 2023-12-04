#include<stdio.h>
#include<cs50.h>
#include<string.h>


// the purpose of this code is to transform decimal number to binary

int main(void)
{
    int remainder, xyz;
    int xxx=get_int("enter decimal number to transform to binary, then press ENTER >");

    int binary_no[]={0,0,0,0,0,0,0,0};

    remainder=xxx;

    printf("\n");

    for(int i=7; i>=0; i--)
    {
        xyz= pow(2,i);

        if(remainder>=xyz)
        {   binary_no[i]=1;
            remainder = (remainder%xyz);    }

        else
        {   binary_no[i]=0; }
    }

    for(int i=7; i>=0; i--)
    {
        printf("%i ", binary_no[i]);
    }

    printf("\n");
}