#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int initpop, finalpop,  n;
    float pop;

    initpop=5;

    // TODO: Prompt for start size

    while(initpop<9)
    {
        initpop=get_int("Enter the initial population of llamas >");
    }

    //printf("\nInitial llama population = %i\n", initpop);

    // TODO: Prompt for end size

    finalpop=0;

    while(finalpop<initpop)
    {
        finalpop=get_int("Enter the final population of llamas >");
    }

    //printf("\nFinal llama population = %i\n", finalpop);

    // TODO: Calculate number of years until we reach threshold

    pop=initpop;
    //int pop2;

    for(int i=0; pop<finalpop; i++)
    {
        pop=(int)(pop+pop*(1/3.0)-pop*(1/4.0));

        // in the following assignment decimals are lost
        //pop;
        //printf("\nend of year= %i, llama pop = %f",i, pop);
        n=i;
    }
    printf("\n");
    printf("Years: %i", n);
    printf("\n");

    // TODO: Print number of years
}
