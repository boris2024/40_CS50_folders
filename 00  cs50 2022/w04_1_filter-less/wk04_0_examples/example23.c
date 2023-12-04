	#include<stdio.h>
	#include<stdlib.h>

	int main()
	{
		int *ptr;
		ptr = (int *)malloc(sizeof(ptr));

		

		if (ptr == NULL)
		{	printf("ERROR: could not be allocated: memory overflow\n");
			return 1;	}

		*ptr = 10;

		printf("\n%d\n", *ptr);
		//printf("\n%d\n", n);
		printf("\n");

		free(ptr);
		return 0;
	}