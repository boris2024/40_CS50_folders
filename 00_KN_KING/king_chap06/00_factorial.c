#include<cs50.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>

int main(void)
{
int n, total=1;
printf("\nenter n, then press ENTER\n");
scanf("%d",&n);

for(int i=n; i>=1; i--)
{
    total=total*i;
}

printf("\ntotal = %d\n",total);

}