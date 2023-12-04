#include <stdio.h>
#include <stdlib.h>
int main()
{
    //! here we declare int n and i. Also, we declare p as a pointer of an int variable
    int n,i; int *p;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    p=(int*)malloc(n * sizeof(int));  //! memory allocated using malloc

    if(p == NULL)
    {   printf("memory cannot be allocated\n");   }

    else
    {   printf("Enter elements of array:\n");

        for(i=0;i<n;++i){ scanf("%d",&*(p+i));  }

        printf("Elements of array are\n");

        for(i=0;i<n;i++){ printf("%d\n",*(p+i));  }
    }
    return 0;
}
