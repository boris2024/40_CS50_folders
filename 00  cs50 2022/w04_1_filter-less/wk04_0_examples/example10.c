#include<cs50.h>
#include<stdio.h>
#include<string.h>

//! this code is an example is passing pointers to FUNCTIONS

//!     Here, the value stored at i, *p, is 10 initially.
//!     We then passed the pointer p to the addOne() function.
//!     The ptr pointer gets this address in the addOne() function.
//!     Inside the function, we increased the value stored at ptr by 1 using (*ptr)++;
//!     Since ptr and p pointers both have the same address, *p inside main() is also 11.


//!     remember int *ptr == int *p == &i
void addOne (int*ptr){(*ptr)++;}

int main (void)
{
int i=10;
int *p;

p=&i;           //! in this line the address of i is passed to pointer p
addOne(p);      //! in this line I'm passing pointer p to the fxn

printf("\n%i\n",*p); // the output is 11
}