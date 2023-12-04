#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int main (void)
{
float time;

printf("\nenter time to launch (sec):\n");
scanf("%f", &time);
printf("\ntime to launch is: %0.2f sec\n", time);

while(time>1)
    {
        printf("time to launch: %0.2f\n", time);
        time--;
    }


}// main ends here