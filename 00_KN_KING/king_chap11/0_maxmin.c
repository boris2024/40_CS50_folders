#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>

/*  20221221
find the largest and smalles elements in the array, assign them to pointers
page 250, "C programming, a modern approach"
*/

#define N 10

void max_min(int a[], int n, int * max, int * min);

int main (void)
{
int b[N], i, big, small;

printf("\nthere are n= %d elements in the array\n",N);

int k=0;
while(1)
{
    printf("element[%d]= ",k);
    scanf("%d",&b[k]);
    k++;
    if(k==N){break;}
}

//use while(1) to print elements in the array

printf("\n");

int j=0;
while(1)
{
    printf(" %d",b[j]);
    j++;
    if(j==N){break;}
}

printf("\n");

max_min(b, N, &big, &small);

printf("largest: %d\n", big);
printf("smallest: %d\n", small);

return 0;
}// MAIN ends here



void max_min(int a[], int n, int * max, int * min )
{
    int i;

    *max=a[0];
    *min=a[0];

    for(i=1; i<n; i++)
    {
        if( a[i]>*max ){ *max=a[i]; }

        else{   if(a[i]<*min){ *min=a[i]; }

            }


    }
}

