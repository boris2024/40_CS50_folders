#include<stdlib.h>
#include<stdio.h>

typedef struct People
    {
        int dob;
        int salary;
        char *name;
        float height;
    }person;

int main(void)
{


    // here the datatype is person and the variable is "employee"
    person employee;

    employee.dob=19790420;
    employee.height=1.72;
    employee.name="alvaro e.";

    printf("\ndob= %d\nheight= %f\nname= %s\n",employee.dob,employee.height,employee.name);
}