#include "helpers.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//! Convert image to grayscale
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


    return;
}

//! Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
                double A=0.393;      double B=0.769;     double C=0.189;
                double D=0.349;      double E=0.686;     double F=0.168;
                double G=0.272;      double H=0.534;     double I=0.131;

                int x=image[i][j].rgbtRed;
                int y=image[i][j].rgbtGreen;
                int z=image[i][j].rgbtBlue;

                int h = round(A*x + B*y + C*z);
                int m = round(D*x + E*y + F*z);
                int l = round(G*x + H*y + I*z);

                if(h>=255){h=255;}

                if(m>=255){m=255;}

                if(l>=255){l=255;}

                image[i][j].rgbtRed=h;
                image[i][j].rgbtGreen=m;
                image[i][j].rgbtBlue=l;

        }

    }

    return;
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


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{   int i, j;

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

                //image[y][x].rgbtRed=round(sumred/counter);
                //image[y][x].rgbtGreen=round(sumgreen/counter);
                //image[y][x].rgbtBlue=round(sumblue/counter);

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


}//! BLUR function ends here
