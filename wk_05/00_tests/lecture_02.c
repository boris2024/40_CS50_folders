#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int *list;
    list=malloc(3*sizeof(int));

    // check for memory assignment errors

    if(list==NULL)
    {
        printf("EROROR assigning memory 1");
        return 1;
    }

    list[0]=13;
    list[1]=2120;
    list[2]=7;

    // resize the list to be of size 4, use realloc

    int *tmp;

    // notice realloc takes care of copying /moving the date
    tmp=realloc(list, 4*sizeof(int));

    if(tmp==NULL)
    {
        free(list);
        printf("ERROR assigning memory 2");
        return 1;
    }

    list=tmp;

    list[3]=4;

    // print list

    int i=0;
    while(i<4)
    {
        printf("\n%d\n",list[i]);
        i++;
    }

    free(tmp);


}