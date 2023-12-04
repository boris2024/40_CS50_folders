#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int main(void)
{
int n;
printf("\nenter number to check if it's prime or not\n");

scanf("%d",&n);

printf("\nthis program will check if %d is prime\n",n);

int counter=0;

for(int i=2; i<=(n-1); i++ )
{
    if((n%i)==0) {  counter++; }
}

if (counter==0)  {   printf("\n%d is prime\n",n);  }

else {printf("\n%d is not prime\n",n);    }


}
