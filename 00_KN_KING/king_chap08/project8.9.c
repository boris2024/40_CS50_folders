#include<cs50.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>

/* 20221201 project 8.9 from KN KING's "C programming, a modern approach"
*/

int main(void)
{
int rows, columns;
int i=0,j=0, zzz=0;

char alphabet[]=
{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

// create a 10 x 10 array, filled with '.' (periods)
char board[10][10];

for( i=0; i<10; i++)
{   for( j=0; j<10; j++){   board[i][j]='.';    }   }


// create a 10 x 10 array, filled with 0, which means false
// this will be used to track what elements have been modified by the snake
// it helps us answer the question "element already modified by the snake?"
int record[10][10];

for( i=0; i<10; i++)
{   for( j=0; j<10; j++){   record[i][j]=0;    }   }


srand ((unsigned) time(NULL));  // seed for random number generator

// starting point,
// you must initilize both arrays with the starting point

i=3, j=3;
board[i][j]=alphabet[0];
record[i][j]=1;

printf("\n");

int counter=1;
printf("counter = %d; starting point i= %d, j=%d\n", counter, i, j);

while(counter<27)
{
int direction=rand()%4;

// 1 element up from starting point
if(direction==0){   zzz=i-1;
                    if (counter==27){break;}
                    if( (zzz<0||zzz>9)||(j<0||j>9) ){continue;}
                    if(record[zzz][j]==1){continue;}

                    if(record[i-1][j]==1 && record[i+1][j] && record[i][j-1]==1 && record[i][j+1]==1){printf("\nx"); break;}

                    i=i-1;
                    board[i][j]=alphabet[counter];
                    record[i][j]=1;

                    counter++;
                 }
// 1 element down from starting point
else{   if(direction==1){   zzz=i+1;
                            if (counter==27){break;}
                            if( (zzz<0||zzz>9)||(j<0||j>9)  ){continue;}
                            if(record[zzz][j]==1){continue;}

                            if(record[i-1][j]==1&&record[i+1][j]&&record[i][j-1]==1&&record[i][j+1]==1){printf("\nxx"); break;}

                            i=i+1;
                            board[i][j]=alphabet[counter];
                            record[i][j]=1;

                            counter++;
                        }

// 1 element left from starting point
        else{   if(direction==2){   zzz=j-1;
                                    if (counter==27){break;}
                                    if( (i<0||i>9)||(zzz<0||zzz>9)  ){continue;}
                                    if(record[i][zzz]==1){continue;}

                                    if(record[i-1][j]==1 && record[i+1][j] && record[i][j-1]==1 && record[i][j+1]==1){printf("\nxxx"); break;}

                                    j=j-1;
                                    board[i][j]=alphabet[counter];
                                    record[i][j]=1;

                                    counter++;
                                 }

// 1 element right from starting point
                else{   zzz=j+1;
                        if (counter==27){break;}
                        if( (i<0||i>9)||(zzz<0||zzz>9) ){continue;}
                        if(record[i][zzz]==1){continue;}

                        if(record[i-1][j]==1&&record[i+1][j]&&record[i][j-1]==1&&record[i][j+1]==1){printf("\nxxxx"); break;}

                        j=j+1;
                        board[i][j]=alphabet[counter];
                        record[i][j]=1;
                        counter++;
                    }
            }
    }

}// WHILE ends here

printf("\n");

for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            printf(" %c",board[i][j]);
            if(j==9){printf("\n"); }
        }
    }

/*
printf("\n");
for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            printf(" %d",record[i][j]);
            if(j==9){printf("\n"); }
        }
    }
*/

printf("\n");

return 0;
}// MAIN ends here
