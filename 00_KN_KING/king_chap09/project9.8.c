#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>

/* 20221213
project 9.8 from "C programming, a modern approch" by KN KING
*/

int roll_dice(void);
bool play_game(void);

int sum01=1, sum02=100, wins=0, losses=0, point=100;
bool win_answer;
int dice1[]={1,2,3,4,5,6};  int dice2[]={1,2,3,4,5,6};
char answer='y';

int main (void)
{
srand ((unsigned) time(NULL));

while(1)
{

win_answer=play_game();

if(win_answer==true){ printf("\nyou won!"); wins++;}

else{ printf("\nyou lost!"); losses++;}

printf("\nplay again?\n");
scanf("%s",&answer);
if(answer=='y'||answer=='Y'){continue;}
else{break;}

}

printf("\nwins= %d, losses= %d\n",wins, losses);
printf("\n");
}// MAIN ends here

// FXN 1, roll_dice
int roll_dice(void)
{

    int i=0;
    int sum=0;
    while(i<1)  {   int cube1 = rand()%6 ;
                    int cube2 = rand()%6 ;
                    sum=dice1[cube1] + dice2[cube2];
                    i++;    }
    return sum;
}


//  FXN 2, play_game
bool play_game(void)
{   // roll 1
    sum01=roll_dice();
    printf("\nYou rolled %d",sum01);

    if(sum01==7 || sum01==11){  return true; }

    else{   if(sum01==2||sum01==3||sum01==12){  return false; }

            else{   point=sum01;
                    printf("\nYour point is %d, roll again!", sum01);

                    // roll 2 and next rolls are part of a loop

                    while(1)
                    {   sum02=roll_dice();
                        //printf("\nyou rolled = %d\n",sum02);

                        if(point==sum02){printf("\nyou rolled %d",sum02); return true;}

                        else{   if(sum02==7){   printf("\nyou rolled %d", sum02);
                                                return false;
                                            }

                                else{ continue; }

                            }
                    }

                }
        }
}

