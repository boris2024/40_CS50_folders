// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";           temps[0].temp = 97;     temps[1].city = "Boston";           temps[1].temp = 82;
    temps[2].city = "Chicago";          temps[2].temp = 85;     temps[3].city = "Denver";           temps[3].temp = 90;
    temps[4].city = "Las Vegas";        temps[4].temp = 105;    temps[5].city = "Los Angeles";      temps[5].temp = 82;
    temps[6].city = "Miami";            temps[6].temp = 97;     temps[7].city = "New York";         temps[7].temp = 85;
    temps[8].city = "Phoenix";          temps[8].temp = 107;    temps[9].city = "San Francisco";    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }

}   // MAIN ends here


// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
    // Add your code here

    avg_temp interim;

    for(int i=0; i<NUM_CITIES; i++)
    {
        // index is the elemet number for the initial max temp element
        int index;

        // max is the assumed initial max temp
        int max;

        max=temps[9].temp, index=9;

        // step 1, find max temp element within unsorted array
        for(int j=i; j<NUM_CITIES; j++)
        {
            if( temps[j].temp > max )
            {
                max=temps[j].temp;
                index=j;
            }
        }

        printf("\n i = %d", i);
        printf("\nmax temp = %d, element = %d\n\n",max, index);

        // step 2, perform the swap

        interim=temps[index];
        temps[index]=temps[i];
        temps[i]=interim;

    }

}
