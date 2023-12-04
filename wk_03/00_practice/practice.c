#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

struct person
{
    string name;
    float price;
};

int main(void)
{
    int n=4;
    struct person people[n], alvaro, roro, diego;


    people[0].name="bologna";
    people[0].price=5.5;

    people[1].name="margarita";
    people[1].price=11.5;

    people[2].name="tuna";
    people[2].price=22.1;

    people[3].name="pasta";
    people[3].price=33.5;

    for(int i=0; i<n; i++)
    {
        printf("\nname= %s",people[i].name);
        printf("\nprice= %0.2f", people[i].price);
        printf("\n");
    }

    alvaro.name="maracay";
    alvaro.price=33.4;

    roro.name="celeste";
    roro.price=32.1;

    printf("\n");
    printf("\nalvaro.name= %s", alvaro.name);
    printf("\nalvaro.price= %0.2f", alvaro.price);
    printf("\n\n");
}