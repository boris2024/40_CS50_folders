#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int main(void)
{
    char *test=malloc(sizeof(char)*400);

    if(test==NULL)
    {
        printf("\nERROR during memory allocation\n");
        return 1;
    }


    for(int i=0; i<50; i++)
    {
        sprintf(test+8*i,"%03d.jpg",i);
    }

    int count=0;

    for(int i=0; i<50; i++)
    {
        printf("\n%s",test+8*i);
    }

    printf("\ntest[399]= %c\n",test[399]);


    printf("\n");


/*
    while(1)
    {
        if(count%8==0)
        {
            printf("\ncount = %d, address is = %p\n",count,(test+count));
        }

        count++;

        if(count==40)
        {
            break;
        }
    }
    */

} // MAIN ends here