#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n,i, sum=0;

  int *ptr;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    ptr=(int*)malloc(n*sizeof(int));  //memory allocated using malloc

    if(ptr==NULL)
    {
        printf("Sorry! unable to allocate memory");
        exit(0);
    }

    printf("Enter elements of array: ");
    for(i=0;i<n;++i)
    {
        scanf("%d",ptr+i);
        sum=sum+ *(ptr+i);
    }
    
    printf("Sum=%d",sum);
    free(ptr);
return 0;
}