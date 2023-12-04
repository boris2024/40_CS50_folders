#include<cs50.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>
#include<stdbool.h>

/* 20221201 example of how to use random numbers
*/

int main(void)
{
int dice1[]={1,2,3,4,5,6};
int dice2[]={1,2,3,4,5,6};

srand ((unsigned) time(NULL));

printf("\n");

int i=0;
int sum=0;

while(i<50)
{
    int cube1 = rand()%6 ;
    int cube2 = rand()%6 ;
    sum=dice1[cube1] + dice2[cube2];

    printf("  %d, %d", dice1[cube1], dice2[cube2]);

    i++;

    if(i%2==0){printf("\n");}

}

printf("\n");

return 0;
}// MAIN ends here