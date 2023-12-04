#include<cs50.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

// C program to calculate the factorial of a number n using recursion

int recursion(int n);

int main(void)
{
int n;
printf("\nenter number n to calculate factorial\n");
scanf("%d",&n);
printf("n= %d\n",n);

int x=recursion(n);

printf("\nn! = %d \n",x);

return 0;
}   // MAIN ends here

int recursion(int n)
{
int total=1;

if (n>1)    {
                total=n*recursion(n-1);
                printf("\nn1= %d\n",n);
                printf("\ntotal =%d\n",total );

                return total;
            }

else        {   return 1;   }

}