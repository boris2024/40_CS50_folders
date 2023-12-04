#include<stdio.h>
#include<stdlib.h>

int main(void)
{ int i=6; int j=6;

    int height=3;
    int width=3;

    int image[i][j];
    int* ptr[i][j];

//! assign a value to image[k][l]
    for(int k=0; k<(height+0); k++)
    {
        for(int l=0; l<(width+0); l++)
        {   image[k][l]=1;  }
    }

//! here, I move, apply a 1 unit translation to the image array within the pointers array
    for(i=0; i<(height); i++ )
    {
        for(j=0; j<(width); j++)
        {   ptr[i+1][j+1]=&image[i][j]; }
    }

//! now, assign the NULL pointer around the edge of the non-NULL pointers

    for(int b=0;b<=4;b++){  ptr[0][b]=NULL; }
    for(int b=0;b<=4;b++){  ptr[4][b]=NULL; }
    for(int a=1;a<=3;a++){  ptr[a][0]=NULL; }
    for(int a=1;a<=3;a++){  ptr[a][4]=NULL; }

for(int c=0; c<5;c++)
{   for(int d=0; d<5; d++)
    {   printf("\nheight=%d, width=%d, ptr=%p\n", c,d,ptr[c][d]);  }
}

int counternull=0;
int counternot=0;

for(int m=0; m<=4;m++)
{
    for(int n=0;n<=4;n++)
    {
        if(ptr[m][n]==NULL){counternull++;}
        if(ptr[m][n]!=NULL){counternot++;}
    }
}

printf("\ncounter null=%d\n",counternull);
printf("\ncounter not null=%d\n",counternot);

//! now....using the pointers array as a reference..

//int counternull2=0;

for(int m=1; m<=3;m++)
{
    for(int n=1;n<=3;n++)
    {   int counternull2=0;

        for(int z=m-1; z<=m+1; z++)
        {
            for(int w=n-1; w<=n+1; w++)
            {
                if(ptr[z][w]==NULL)
                {   counternull2++;
                    
                }
            }
        }
        printf("\nm= %d; n= %d, counternull=%d\n",m,n,counternull2);
    }
}

}


/*
    for(i=1; i<(height+1); i++ )
    {
        for(j=1; j<(width+1); j++)
        {
            ptr[i][j]=&image[i][j];
        }
    }
    */

    //int* ptr[i][j];

    //ptr[height][width]=&image[height][width];

/*
    for(i=1; i<=(4); i++ )
    {
        for(j=1; j<=(4); j++)
        {
            printf("\n[%d], [%d], image= %d\n",i,j,*ptr[i][j]);
        }
    }
    */

/*
//! this is just to test and print
    for(int x=1; x<(4); x++ )
    {
        for(int y=1; y<(4); y++)
        {
            printf("\n[%d], [%d], ptr array= %d\n",x,y,*ptr[x][y]);
        }
    }
*/