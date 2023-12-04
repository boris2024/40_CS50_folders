#include<cs50.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

/*
20221125
this program is a solution to project 6.6 from KN Kings "C Programming, A Modern Approach"
this time we use the FOR mechanism
*/


int main(void)
{
int n;
printf("\nenter number to use as upper limit, hit ENTER after\n");
scanf("%d",&n);

printf("\n");

for(int i=0; 2*i*i<n; i++)
{
    printf("%d ",2*i*i);
}

printf("\n");

return 0;
}// main ends here
