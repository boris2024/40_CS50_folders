#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int *list;
    list=malloc(3*sizeof(int));

    printf("\n00 address of pointer list = %p\n",list);

    if(list==NULL)
    {
        printf("\nERROR assigning memory\n");
        return 1;
    }

    // initialize list with 3 integers

    list[0]=10;
    list[1]=111;
    list[2]=23;

    // list of size 4

    int *temp;
    temp=malloc(4*sizeof(int));
    printf("\n100 address of pointer temp = %p\n",temp);

    //check for error assigning memory to temp
    if(temp==NULL)
    {
        free(list);
        printf("\nERROR assigning memory 2\n");
        return 1;
    }

    temp[0]=list[0];
    temp[1]=list[1];
    temp[2]=list[2];
    temp[3]=457;

    int i=0;

    while(i<3)
    {
        printf("\ntemp[%d] = %d\n",i,temp[i]);
        i++;
    }

    // free list of size 3
    free(list);

    printf("\n01 address of pointer list = %p\n",list);

    printf("\n101 address of pointer temp = %p\n",temp);

    // remember list of size 4
    list=temp;

    printf("\n02 address of pointer list = %p\n",list);

    i=0;
    while(i<4)
    {
        printf("\nlist[%d]= %d\n",i,list[i]);
        i++;
    }


    free(temp);
    //free(list);

}