#include<stdio.h>
#include<cs50.h>

int main(void)
{
    string name;
    int age;
    long number;

    printf("\n");
    name=get_string("What is your first name? >");

    age=get_int("What is your age >");

    number=get_long("What is your phone number? >");

    printf("your name = %s\nyour age= %i\nyour number= %li\n",name, age, number);


    //printf("\n");
}