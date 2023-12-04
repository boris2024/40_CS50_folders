#include "helpers.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            int x=image[i][j].rgbtRed;
            int y=image[i][j].rgbtGreen;
            int z=image[i][j].rgbtBlue;

            int average=round((x+y+z)/3.0);

            image[i][j].rgbtRed=average;
            image[i][j].rgbtGreen=average;
            image[i][j].rgbtBlue=average;

        }
    }


}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     RGBTRIPLE temp[height][width];

        //! create temp copy of each field of RGBTRIPLE image[height][width]
      for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
                        temp[i][j].rgbtRed=image[i][j].rgbtRed;
                        temp[i][j].rgbtGreen=image[i][j].rgbtGreen;
                        temp[i][j].rgbtBlue=image[i][j].rgbtBlue;
        }
    }

    for (int i=0; i<height; i++)
    {
        for(int j=(width-1); 0<=j; j--)
        {
                           image[i][(width-1)-j].rgbtRed=temp[i][j].rgbtRed;
                           image[i][(width-1)-j].rgbtGreen=temp[i][j].rgbtGreen;
                           image[i][(width-1)-j].rgbtBlue=temp[i][j].rgbtBlue;
        }
    }



}

//!  Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
 int i, j;

//! declare new 2D arrays of type RGBTRIPLE,
//! one is used to copy the content of image[height][width]
//! and another is used to create a pointers array

    RGBTRIPLE copy[height][width];
    RGBTRIPLE * ptr[height][width];

//! copy content from original 2D-array image[height][width] into
//! new 2D array, copy[height][width]

    for( i=0; i<height; i++)
    {
        for( j=0; j<width; j++)
        {
                           copy[i][j].rgbtRed=image[i][j].rgbtRed;
                           copy[i][j].rgbtGreen=image[i][j].rgbtGreen;
                           copy[i][j].rgbtBlue=image[i][j].rgbtBlue;
        }
    }

//! case of the 4 corners

for(int y=0; y<height; y++)
{
    for(int x=0; x<width; x++)
    {
        if( y==0 && x==0)
        {   int counter=0;
            int sumred=0;   int sumgreen=0;     int sumblue=0;

            for(int a=0; a<=1; a++)
            {
                for(int b=0; b<=1; b++)
                {
                    counter++;
                    sumred=sumred+copy[a][b].rgbtRed;
                    sumgreen=sumgreen+copy[a][b].rgbtGreen;
                    sumblue=sumblue+copy[a][b].rgbtBlue;
                }
            }
                    image[y][x].rgbtRed=round(sumred/counter);
                    image[y][x].rgbtGreen=round(sumgreen/counter);
                    image[y][x].rgbtBlue=round(sumblue/counter);
        }

        if( y==0 && x==(width-1))
        {   int counter=0;
            int sumred=0;   int sumgreen=0;     int sumblue=0;

            for(int a=0; a<=1; a++)
            {
                for(int b=(width-2);  b<=(width-1); b++  )
                {
                    counter++;
                    sumred=sumred+copy[a][b].rgbtRed;
                    sumgreen=sumgreen+copy[a][b].rgbtGreen;
                    sumblue=sumblue+copy[a][b].rgbtBlue;
                }
            }
                    image[y][x].rgbtRed=round(sumred/counter);
                    image[y][x].rgbtGreen=round(sumgreen/counter);
                    image[y][x].rgbtBlue=round(sumblue/counter);
        }



        if( y==(height-1) && x==(0))
        {   int counter=0;
            int sumred=0;   int sumgreen=0;     int sumblue=0;

            for(int a=(height-1); (height-2)<=a; a--   )
            {
                for(int b=0; b<=1; b++ )
                {
                    counter++;
                    sumred=sumred+copy[a][b].rgbtRed;
                    sumgreen=sumgreen+copy[a][b].rgbtGreen;
                    sumblue=sumblue+copy[a][b].rgbtBlue;
                }
            }
                    image[y][x].rgbtRed=round(sumred/counter)+1;
                    image[y][x].rgbtGreen=round(sumgreen/counter)+1;
                    image[y][x].rgbtBlue=round(sumblue/counter)+1;
        }

        if( y==(height-1) && x==(width-1))
        {   int counter=0;
            int sumred=0;   int sumgreen=0;     int sumblue=0;

            for(int a=(height-1); (height-2)<=a; a-- )
            {
                for(int b=(width-1); (width-2)<=b; b--    )
                {
                    counter++;
                    sumred=sumred+copy[a][b].rgbtRed;
                    sumgreen=sumgreen+copy[a][b].rgbtGreen;
                    sumblue=sumblue+copy[a][b].rgbtBlue;
                }
            }
                    image[y][x].rgbtRed=round(sumred/counter)+1;
                    image[y][x].rgbtGreen=round(sumgreen/counter)+1;
                    image[y][x].rgbtBlue=round(sumblue/counter);
        }
    }

}       //! 4 corners counting ends here


//! case 2: the 4 edges

//! EDGE 0

for( int x=1; x<=(width-2); x++ )
{
    for( int y=0; y<=0; y++ )
    {
        int counter=0;
        int sumred=0;   int sumgreen=0;     int sumblue=0;

        for(int a=y; a<=(1); a++)
        {
            for(int b=(x-1); b<=(x+1); b++ )
            {
                counter++;
                sumred=sumred+copy[a][b].rgbtRed;
                sumgreen=sumgreen+copy[a][b].rgbtGreen;
                sumblue=sumblue+copy[a][b].rgbtBlue;
            }
        }
                image[y][x].rgbtRed=round(sumred/counter);
                image[y][x].rgbtGreen=round(sumgreen/counter);
                image[y][x].rgbtBlue=round(sumblue/counter);
    }
}

//! EDGE 1

for(int y=1; y<=(height-2); y++)
{
    for(int x=(width-1); x<=(width-1); x++)
    {
        int counter=0;
        int sumred=0;   int sumgreen=0;     int sumblue=0;

        for(int a=(y-1); a<=(y+1); a++)
        {
            for(int b=(width-1); (width-2)<=b; b--)
            {   counter++;
                sumred=sumred+copy[a][b].rgbtRed+1;
                sumgreen=sumgreen+copy[a][b].rgbtGreen;
                sumblue=sumblue+copy[a][b].rgbtBlue;
            }
        }
                image[y][x].rgbtRed=round(sumred/counter);
                image[y][x].rgbtGreen=round(sumgreen/counter);
                image[y][x].rgbtBlue=round(sumblue/counter);
    }
}

//! EDGE 3

for(int y=1; y<=(height-2); y++)
{
    for(int x=(0); x<=(0); x++)
    {
        int counter=0;
        int sumred=0;   int sumgreen=0;     int sumblue=0;

        for(int a=(y-1); a<=(y+1); a++)
        {
            for(int b=(0); b<=1; b++)
            {
                counter++;
                sumred=sumred+copy[a][b].rgbtRed+1;
                sumgreen=sumgreen+copy[a][b].rgbtGreen;
                sumblue=sumblue+copy[a][b].rgbtBlue;
            }
        }
                image[y][x].rgbtRed=round(sumred/counter);
                image[y][x].rgbtGreen=round(sumgreen/counter);
                image[y][x].rgbtBlue=round(sumblue/counter);
    }
}

//! EDGE 2
for( int x=1; x<=(width-2); x++ )
{
    for( int y=(height-1); (height-1)<=y; y-- )
    {
        int counter=0;
        int sumred=0;   int sumgreen=0;     int sumblue=0;

        for(int a=(y); (height-2)<=a  ; a--  )
        {
            for(int b=(x-1); b<=(x+1); b++)
            {
                counter++;

                sumred=sumred+copy[a][b].rgbtRed;
                sumgreen=sumgreen+copy[a][b].rgbtGreen;
                sumblue=sumblue+copy[a][b].rgbtBlue;
            }
        }

                image[y][x].rgbtRed=round(sumred/counter);
                image[y][x].rgbtGreen=round(sumgreen/counter);
                image[y][x].rgbtBlue=round(sumblue/counter);

    }
} //! 4th block for the EDGES ends here


//!
    for(int y=(1); y<=(height-2); y++)
    {
        for(int x=1; x<=(width-2); x++ )
        {
            int counter=0;
            int sumred=0;   int sumgreen=0;     int sumblue=0;

            for(int a=y-1; a<=y+1; a++)
            {
                for(int b=x-1; b<=x+1; b++)
                {   counter++;

                    sumred=sumred+copy[a][b].rgbtRed;
                    sumgreen=sumgreen+copy[a][b].rgbtGreen;
                    sumblue=sumblue+copy[a][b].rgbtBlue;
                }
            }

                    image[y][x].rgbtRed=round(sumred/counter)+1;
                    image[y][x].rgbtGreen=round(sumgreen/counter);
                    image[y][x].rgbtBlue=round(sumblue/counter);
        }
    }


}  //! BLUR fxn ends here



// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
//! 1. declare new temporary 2D array

RGBTRIPLE temp[height][width];

//! 2. Fill R,G,B values for each pixel in temp[][] with 1,1,1


for(int a=0; a<=(height-1); a++)
{
    for(int b=0; b<=(width-1); b++)
    {
        temp[a][b].rgbtRed=image[a][b].rgbtRed;
        temp[a][b].rgbtBlue=image[a][b].rgbtGreen;
        temp[a][b].rgbtGreen=image[a][b].rgbtBlue;
    }
}


// 3. Declare Gx and Gy coefficients

    int gx[0][0]=-1;                    int gy[0][0]=-1;
    int gx[0][1]=0;                     int gy[0][1]=-2;
    int gx[0][2]=1;                     int gy[0][2]=-1;
    int gx[1][0]=-2;                    int gy[1][0]=0;
    int gx[1][1]=0;                     int gy[1][1]=0;
    int gx[1][2]=2;                     int gy[1][2]=0;
    int gx[2][0]=-1;                    int gy[2][0]=1;
    int gx[2][1]=0;                     int gy[2][1]=2;
    int gx[2][2]=1;                     int gy[2][2]=1;

//4.




for(int i=0; i<=(height-1);i++ )
{
    for(int j=0; j<=(width-1); j++)
    {

    float gxred=0;    float gxgreen=0;  float gxblue=0;
    float gyred=0;    float gxgreen=0;  float gxblue=0;

    for(int a=0; a<=2; a++)
    {
        for( int b=0; b<=2; b++)
        {

            if (    (i+a)<0||(i+a)>(height-1)   ){continue;}

            if  (   (j+a)<0||(j+a)>(width-1)   ){continue;}

            else
            {
                gxred = gxred + temp[i][j].rgbtRed * gx[a][b];
            }

        }
    }





    }
}





}//! EDGE ends here


/*
// corner01,  0,0
if( i==0 && j==0)
{
        gx00=gx01=gx02=gx10=gx20=0;

        gy00=gy01=gy02=gy10=gy20=0;

        int gxared= temp[i-1][j-1].rgbtRed*gx00 +  temp[i-1][j].rgbtRed*gx01 + temp[i-1][j+1].rgbtRed*gx02;
        int gxbred= temp[i][j-1].rgbtRed*gx10 +    temp[i][j].rgbtRed*gx11 +   temp[i][j+1].rgbtRed*gx12;
        int gxcred= temp[i+1][j-1].rgbtRed*gx20 +  temp[i+1][j].rgbtRed*gx21 + temp[i+1][j+1].rgbtRed*gx22;

        int gyared= temp[i-1][j-1].rgbtRed*gy00 +  temp[i-1][j].rgbtRed*gy01 +    temp[i-1][j+1].rgbtRed*gy02;
        int gybred= temp[i][j-1].rgbtRed*gy10 +    temp[i][j].rgbtRed*gy11 +      temp[i][j+1].rgbtRed*gy12;
        int gycred= temp[i+1][j-1].rgbtRed*gy20 +  temp[i+1][j].rgbtRed*gy21 +    temp[i+1][j+1].rgbtRed*gy22;

        int gxred= gxared + gxbred + gxcred;
        int gyred= gyared + gybred + gycred;

        double red1= ( sqrt( gxred*gxred + gyred *gyred ));
        int red2 = round (red1);
        if(red2>=255){image[i][j].rgbtRed=255;}
        else{ image[i][j].rgbtRed=red2; }



        int gxagreen= temp[i-1][j-1].rgbtGreen*gx00 +  temp[i-1][j].rgbtGreen*gx01 + temp[i-1][j+1].rgbtGreen*gx02;
        int gxbgreen= temp[i][j-1].rgbtGreen*gx10 +    temp[i][j].rgbtGreen*gx11 +   temp[i][j+1].rgbtGreen*gx12;
        int gxcgreen= temp[i+1][j-1].rgbtGreen*gx20 +  temp[i+1][j].rgbtGreen*gx21 + temp[i+1][j+1].rgbtGreen*gx22;

        int gyagreen= temp[i-1][j-1].rgbtGreen*gy00 +  temp[i-1][j].rgbtGreen*gy01 +    temp[i-1][j+1].rgbtGreen*gy02;
        int gybgreen= temp[i][j-1].rgbtGreen*gy10 +    temp[i][j].rgbtGreen*gy11 +      temp[i][j+1].rgbtGreen*gy12;
        int gycgreen= temp[i+1][j-1].rgbtGreen*gy20 +  temp[i+1][j].rgbtGreen*gy21 +    temp[i+1][j+1].rgbtGreen*gy22;

        int gxgreen= gxagreen + gxbgreen + gxcgreen;
        int gygreen= gyagreen + gybgreen + gycgreen;

        double green1= ( sqrt( gxgreen*gxgreen + gygreen *gygreen ));
        int green2 = round (green1);
        if(green2>=255){image[i][j].rgbtGreen=255;}
        else{ image[i][j].rgbtGreen=green2; }


        int gxablue= temp[i-1][j-1].rgbtBlue*gx00 +  temp[i-1][j].rgbtBlue*gx01 + temp[i-1][j+1].rgbtBlue*gx02;
        int gxbblue= temp[i][j-1].rgbtBlue*gx10 +    temp[i][j].rgbtBlue*gx11 +   temp[i][j+1].rgbtBlue*gx12;
        int gxcblue= temp[i+1][j-1].rgbtBlue*gx20 +  temp[i+1][j].rgbtBlue*gx21 + temp[i+1][j+1].rgbtBlue*gx22;

        int gyablue= temp[i-1][j-1].rgbtBlue*gy00 +  temp[i-1][j].rgbtBlue*gy01 +    temp[i-1][j+1].rgbtBlue*gy02;
        int gybblue= temp[i][j-1].rgbtBlue*gy10 +    temp[i][j].rgbtBlue*gy11 +      temp[i][j+1].rgbtBlue*gy12;
        int gycblue= temp[i+1][j-1].rgbtBlue*gy20 +  temp[i+1][j].rgbtBlue*gy21 +    temp[i+1][j+1].rgbtBlue*gy22;

        int gxblue= gxablue + gxbblue + gxcblue;
        int gyblue= gyablue + gybblue + gycblue;

        double blue1= ( sqrt( gxblue*gxblue + gyblue *gyblue ));
        int blue2 = round (blue1);
        if(blue2>=255){image[i][j].rgbtBlue=255;}
        else{ image[i][j].rgbtBlue=blue2; }
}


// corner02,   (height-1),(0)
if( i==(height-1) && j==(0)   )
{
        gx20=gx21=gx22=gx10=gx00=0 ;
        gy20=gy21=gy22=gy10=gy00=0 ;

        int gxared1= temp[i-1][j-1].rgbtRed*gx00 +  temp[i-1][j].rgbtRed*gx01 + temp[i-1][j+1].rgbtRed*gx02;
        int gxbred1= temp[i][j-1].rgbtRed*gx10 +    temp[i][j].rgbtRed*gx11 +   temp[i][j+1].rgbtRed*gx12;
        int gxcred1= temp[i+1][j-1].rgbtRed*gx20 +  temp[i+1][j].rgbtRed*gx21 + temp[i+1][j+1].rgbtRed*gx22;

        int gyared1= temp[i-1][j-1].rgbtRed*gy00 +  temp[i-1][j].rgbtRed*gy01 +    temp[i-1][j+1].rgbtRed*gy02;
        int gybred1= temp[i][j-1].rgbtRed*gy10 +    temp[i][j].rgbtRed*gy11 +      temp[i][j+1].rgbtRed*gy12;
        int gycred1= temp[i+1][j-1].rgbtRed*gy20 +  temp[i+1][j].rgbtRed*gy21 +    temp[i+1][j+1].rgbtRed*gy22;

        int gxred1= gxared1 + gxbred1 + gxcred1;
        int gyred1= gyared1 + gybred1 + gycred1;

        double red1= ( sqrt( gxred1*gxred1 + gyred1 *gyred1 ));
        int red2 = round (red1);
        if(red2>=255){image[i][j].rgbtRed=255;}
        else{ image[i][j].rgbtRed=red2; }

}



}
}



//! return RGB values from temp[][] back to image[][]
/*
for( int a=0; a<=(height-1); a++ )
    {
        for( int b=0; b<=(width-1); b++ )
        {
            image[a][b].rgbtRed=temp[a][b].rgbtRed;
            image[a][b].rgbtGreen=temp[a][b].rgbtGreen;
            image[a][b].rgbtBlue=temp[a][b].rgbtBlue;
        }
    }
*/


*/