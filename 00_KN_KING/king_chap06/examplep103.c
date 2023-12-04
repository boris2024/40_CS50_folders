#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

// this program sums a series of integers. Upon entering 0 the program stops, prints the total sum
int main(void)
{
int n,sum,a;

printf("\nwrite each number followed by ENTER, write 0 to finalize\n");

sum=0;

while(1)
{   scanf("\n%d",&n );
    sum=sum+n;

    if(n==0){break;}
}

printf("\ntotal = %d\n", sum);

}