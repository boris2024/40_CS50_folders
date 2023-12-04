#include<stdlib.h>
#include<stdio.h>

// 20230519 create structures within structures in C

struct complex
{
    int imaginary;
    float real;
};

struct number
{
    struct complex comp;
    int integers;
};

struct number num1, num2;

int main(void)
{
    num1.comp.imaginary=11;

    num2.comp.real=3.4;

    printf("\ncomplex imaginary= %d\n", num1.comp.imaginary);


}