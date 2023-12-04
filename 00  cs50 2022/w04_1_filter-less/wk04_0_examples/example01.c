#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
int miranda=330;

printf("\nmiranda:%i\n",miranda);
printf("\nmiranda's age is stored in:%p\n",&miranda);


//!     in this exmaple...p1, p2 and p3 are declared as pointers.
//!     Then p1, p2 and p3 are pointers,
//!     *p1, *p2, *p3 are NOT pointers

int *p1;
p1=&miranda;
int *p2=&miranda;
int *p3=&miranda;



printf("\n%p, %p, %p\n",p1,p2,p3);

printf("\n%i, %i, %i\n",*p1,*p2,*p3);

printf("\n");

}