#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
So what does this do?
It reads in the size of the array to create into the variable size.
It then uses malloc to allocate enough memory to hold that many integers.
As the memory it allocates will be continuous, we can use this memory just
like an array.
We store the address of that memory into grades and the rest of the
program is basically as it was above.
*/
/*
int main()
{
    int i=0;    int *grades;    int size;

    printf("\nEnter the number of students :\n");
    scanf("%d\n", &size);

    grades = malloc(size * sizeof(int));

    do { printf("Enter grade #%d:\n", i+1);
    scanf("%d\n", &grades[i]); i++; } while(i<size);
}
*/
/*
//!
There are still a few key elements missing here.

The first, a very important part of programming, is error detection.
Remember that if we try to dereference a NULL pointer, it will very often
cause something bad to happen, like making our program crash.

If for some reason malloc() cannot allocate memory, it will return NULL.

So there exists the possibility that if malloc() cannot allocate the requested memory,
the value of NULL will be stored in grades, and then when we try to access the ith
element of grades, we will have a problem.

To prevent problems like these, we need to check
to see if the result of the call to malloc() returns NULL.

If it does, there was an error, and we need to handle it. How you handle it
depends on how you're using the memory, but in this case we'll just display an
error and exit the program.

*/


int main()
{   int i=0;    int *grades;    int size;
    printf("Enter the number of students:\n");
    scanf("%d\n", &size);

    grades=(int*)malloc(size*sizeof(int));

    if (grades == NULL)
    {   printf("Error: Unable to allocate memory for array\n");
        exit(1); }

    do {    printf("Enter grade #%d:\n", i+1);
            scanf("%d\n", &grades[i]);
            i++; }
        while(i<size);

        free(grades);
}

/*
to dereference a pointer that doesn't point to memory we own).
*/