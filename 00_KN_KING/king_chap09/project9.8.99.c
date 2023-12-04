#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>

/* 20221215 this is a test before tackling project 9.8 from
"C programming, a modern approch" by KN KING
*/

int roll_dice(void);
bool play_game(void);

int sum01=1, sum02=100, wins=0, losses=0, point=100, counter, sum;
bool win_answer;
int dice1[]={1,2,3,4,5,6};  int dice2[]={1,2,3,4,5,6};


int main (void)
{
srand ((unsigned) time(NULL));

counter=0;
printf("\n");
while(counter<36)
{
sum=roll_dice();
counter++;
printf("   roll %d sum= %d",counter,sum);
if(counter%5==0){printf("\n");}
}

printf("\n");
}// MAIN ends here

// FXN 1, roll_dice
int roll_dice(void)
{

    int i=0;
    sum=0;
    while(i<1)  {   int cube1 = rand()%6 ;
                    int cube2 = rand()%6 ;
                    sum=dice1[cube1] + dice2[cube2];
                    i++;    }
    return sum;
}