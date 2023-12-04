#include<cs50.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

/*
20221127
calendar example, project 6.8, from "C programming, a modern approach" by KN KING
the easiest part was the most difficult...
it took me about 8 hrs to figure out the easiest part...
the key to this problem: try to keep things simple
*/

int main(void)
{
int n, j, i,initday;

printf("\nEnter number of days to calculate month, then hit ENTER\n");
scanf("%d",&n);

printf("\nEnter day of the week on which the month begins\n1= Monday, 7= Sunday\n");
scanf("%d",&initday);
printf("\n");

// i = position, j = calendar day,
// j=i-initday+2

for( i=0; i<=n+initday-2; i++)
{

j=i-initday+2;
if(j<1){  printf("          "); }

else{ printf("%10d",j ); }

if(i%7==6) { printf("\n");}

}

printf("\n");

return 0;
}// MAIN ends here