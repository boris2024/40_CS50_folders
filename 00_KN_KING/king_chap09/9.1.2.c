#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/*20221212 exercise 9.1.2 from KN KING's "C programming, a modern approach"
*/

int main(void)
{
int x, y, n;

printf("\nenter int value for x, then press ENTER\n");
scanf("%d",&x);

printf("\nenter int value for y, then press ENTER\n");
scanf("%d",&y);

printf("\nenter int value for n, then press ENTER\n");
scanf("%d",&n);

if((0<=x && x<=n-1)&& (0<=y && y<=n-1)  ){return 1;}

else{return 0;}


}