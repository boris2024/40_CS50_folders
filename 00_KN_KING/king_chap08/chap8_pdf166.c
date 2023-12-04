#include<cs50.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

/* 20221129
example from KN King's "C programming, a modern approach", page 166 of the book

*/

int main(void)
{
bool digit_seen[10]={false};
int digit;
long n;

printf("\nEnter a number, then press ENTER\n");
scanf("%ld",&n);

while(n>0)
{
    digit=n%10;

    if( digit_seen[digit] ){break;}

    digit_seen[digit]=true;

    n=n/10;
}

if (n>0){ printf("\nrepeated digit\n"); }

else{ printf("\nno repeated digit\n");}



return 0;
}// MAIN ends here