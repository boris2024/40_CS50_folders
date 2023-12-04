//! Program to calculate the sum of n numbers entered by the user

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, i, sum = 0;    int*ptr;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  ptr = (int*) malloc(n * sizeof(int));

  //! if memory cannot be allocated
  if(ptr == NULL)
  { printf("Error! memory not allocated.");
    exit(0);  }

  printf("Enter elements: ");

  for(i = 0; i < n; ++i)
    { scanf("%d", ptr + i);
      sum=sum + *(ptr+i);
    }

  printf("Sum = %d\n", sum);

  // deallocating the memory


  for(i=0;i<n;i++)
  { printf("\n%d\n",*(ptr+i));  }

  for(i=0;i<n;i++)
  { printf("\n%p\n",&(ptr[i]));  }

  free(ptr);
  return 0;
}
