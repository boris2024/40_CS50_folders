#include<stdio.h>
#include<stdlib.h>

struct person
{
    
    float height;
    int dob;
};

typedef struct person people;

int main(void)
{
    people *ptr,employee01;
    ptr=&employee01;

    printf("\nenter employee's dob:\n");
    scanf("%d",&(ptr->dob));

    printf("\nenter employee's height\n");
    scanf("%f",&(ptr->height));

    printf("\nemployee's dob= %d\nemployee's height= %0.2f\n",ptr->dob, ptr->height);

}