#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/*
20221212 exercise 9.1.6 from KN KING's "C programming, a modern approach"
write a fxn that returns the kth digit of number n from the right
*/

void digit(int n, int k)
{
int counter1=0, counter2=0,n1,n2;
int kthdigit;

n1=n;
n2=n;

// first, determine number of digits in n
while(1)
{
    n1=n1/10;
    counter1++;
    if(n1<1){break;}
}

printf("\nnumer of digits in n= %d\n", counter1);

if(k>counter1){  printf("\nk>number of digits in n\n0\n");
              }
else
{
    while(1)
    {
        kthdigit=(n2%10);
        n2=n2/10;
        counter2++;
        if(k==counter2){break;}
    }

printf("\nthe kth digit of number n= %d\n",kthdigit);
}

}// digit fxn ends here



int main(void)
{
int n, k;

printf("\nenter int value for number n, then press ENTER\n");
scanf("%d",&n);

printf("\nenter position of kth digit (from the right end) then press ENTER\n");
scanf("%d",&k);

// number = kth digit of number n, from the right

digit (n,k);



}// MAIN ends here