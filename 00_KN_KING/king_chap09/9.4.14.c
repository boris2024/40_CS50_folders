#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*20221213 problem 9.3.14 from "C programming, a modern approach" by KN KING
*/

bool has_zero(int a[], int n);

int main(void)
{
int n=100, a[n];

printf("\nenter int n, then press ENTER\n");
scanf("%d",&n);

printf("\nenter int numbers into a[n] array, press ENTER after each number\n");

for(int i=0; i<n; i++)
{
    printf("\nint a[%d] = ", i);
    scanf("%d", &a[i]);
}



bool fact=has_zero(a,n);

if (fact){printf("\nthere is at least 1 element in a[n] that equals 0\n");}
else{printf("\nthere are no elements equal to zero in a[n]\n");}


}// MAIN ends here

bool has_zero(int a[], int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        if (a[i]==0){return true;}
    }
// this was the error,it must return FALSE when ALL elements are non-zero
// when there are no elements equal to zero, the for loop ends without returning true in any event
// hence all elements are non-zero and the fxn returns false
return false;
}