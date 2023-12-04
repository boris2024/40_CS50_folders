#include "helpers.h"
#include"math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // i is used to move along the height, j is used to move along the width

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            BYTE average=round((image[i][j].rgbtRed +image[i][j].rgbtGreen +image[i][j].rgbtBlue)/3.0);

            image[i][j].rgbtRed=average;
            image[i][j].rgbtGreen=average;
            image[i][j].rgbtBlue=average;

        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

for(int i=0; i<height; i++)
{

    for(int j=0; j<width; j++)
    {   double A, B, C, D, E, F, G, H, I;

        A=0.393, B=0.769, C=0.189;
        D=0.349, E=0.686, F=0.168;
        G=0.272, H=0.534, I=0.131;

        int new_red=round(A*image[i][j].rgbtRed + B*image[i][j].rgbtGreen + C*image[i][j].rgbtBlue);
        int new_green=round(D*image[i][j].rgbtRed + E*image[i][j].rgbtGreen + F*image[i][j].rgbtBlue);
        int new_blue=round(G*image[i][j].rgbtRed + H*image[i][j].rgbtGreen + I*image[i][j].rgbtBlue);

        if(new_red>255)
        {
            image[i][j].rgbtRed=255;
        }

        else
        {
            image[i][j].rgbtRed=new_red;
        }


        if(new_green>255)
        {
            image[i][j].rgbtGreen=255;
        }

        else
        {
            image[i][j].rgbtGreen=new_green;
        }


        if(new_blue>255)
        {
            image[i][j].rgbtBlue=255;
        }
        else
        {
            image[i][j].rgbtBlue=new_blue;
        }

    }

}

    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // i is used to move along the height, j is used to move along the width

    RGBTRIPLE copy[height][width];

    for(int i=0; i<height; i++ )
    {
        for(int j=0; j<width; j++)
        {
            copy[i][j].rgbtRed=0;
            copy[i][j].rgbtBlue=0;
            copy[i][j].rgbtGreen=0;
        }
    }


    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            copy[i][(width-1)-j].rgbtRed=image[i][j].rgbtRed;
            copy[i][(width-1)-j].rgbtBlue=image[i][j].rgbtBlue;
            copy[i][(width-1)-j].rgbtGreen=image[i][j].rgbtGreen;
        }
    }

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            image[i][j].rgbtRed=copy[i][j].rgbtRed;
            image[i][j].rgbtBlue=copy[i][j].rgbtBlue;
            image[i][j].rgbtGreen=copy[i][j].rgbtGreen;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
// 0. create a new 2D onto which you can pass the r, g, b values for every pixel

    RGBTRIPLE copy[height+2][width+2], copy2[height+2][width+2];

// 1. copy pixel information for every channel, from image[][] to copy[][]

// 1.a initialize every element of copy[][] and copy2[][] arrays

    for(int i=0; i<height+2; i++)
    {
        for(int j=0; j<width+2; j++)
        {
            copy[i][j].rgbtRed=0;
            copy[i][j].rgbtGreen=0;
            copy[i][j].rgbtBlue=0;

            copy2[i][j].rgbtRed=0;
            copy2[i][j].rgbtGreen=0;
            copy2[i][j].rgbtBlue=0;
        }
    }


// 1.b create a 1 px frame around the copied values of image[][]
// pass values from image[][] to displaced target on copy[][]

    for(int i=0; i<=height-1; i++)
    {
        for(int j=0; j<=width-1; j++)
        {
            copy[i+1][j+1].rgbtRed=image[i][j].rgbtRed;
            copy[i+1][j+1].rgbtGreen=image[i][j].rgbtGreen;
            copy[i+1][j+1].rgbtBlue=image[i][j].rgbtBlue;
        }
    }



// 2. Read pixel values from copy[][], apply the filter on these values and paste on copy2[][]

// remember: you still have to work on corners and edges

// TODO TODO TODO

// left EDGE
// apply filter to left edge of copy[][], where j=1, 1<= i <= height,
// this is the path the pixel at the center of the square must cover

    for(int i=1; i<=height; i++)
    {
        int j=1;
        {
            int sum_red=0, sum_green=0, sum_blue=0;
            float count=0;
            int avg_red=1, avg_green=1, avg_blue=1;

            for(int k=i-1; k<=i+1; k++)
            {
                for(int m=j-1; m<=j+1; m++)
                {
                    // this is the filter to avoid elements with r, g, b, values of 0
                    if(m!=0 && (1<=k && k<=height)  )
                    {
                    sum_red=sum_red + copy[k][m].rgbtRed;
                    sum_green=sum_green + copy[k][m].rgbtGreen;
                    sum_blue=sum_blue + copy[k][m].rgbtBlue;
                    count++;
                    }
                }
            }
            copy2[i][j].rgbtRed=round(sum_red/count);
            copy2[i][j].rgbtGreen=round(sum_green/count);
            copy2[i][j].rgbtBlue=round(sum_blue/count);
        }
    }

// RIGHT EDGE
// apply filter to right edge of copy[][], pixel at center of square must cover this path:
// where j=width, 1<= i <= height

    for(int i=1; i<=height; i++)
    {
        int j=width;
        {
            int sum_red=0, sum_green=0, sum_blue=0;
            float count=0;
            int avg_red=1, avg_green=1, avg_blue=1;

            for(int k=i-1; k<=i+1; k++)
            {
                for(int m=j-1; m<=j+1; m++)
                {
                    // this is the filter to avoid elements with r, g, b, values of 0
                    if(m!=width+1 && (1<=k && k<=height)  )
                    {
                    sum_red=sum_red + copy[k][m].rgbtRed;
                    sum_green=sum_green + copy[k][m].rgbtGreen;
                    sum_blue=sum_blue + copy[k][m].rgbtBlue;
                    count++;
                    }
                }
            }
            copy2[i][j].rgbtRed=round(sum_red/count);
            copy2[i][j].rgbtGreen=round(sum_green/count);
            copy2[i][j].rgbtBlue=round(sum_blue/count);
        }
    }

// apply filter to TOP edge of copy[][], where i=1 and   2<= j <=width-1

 for(int j=2; j<=width-1; j++)
    {
        int i=1;
        {
            int sum_red=0, sum_green=0, sum_blue=0;
            float count=0;
            int avg_red=1, avg_green=1, avg_blue=1;

            for(int k=i-1; k<=i+1; k++)
            {
                for(int m=j-1; m<=j+1; m++)
                {
                    // this is the filter to avoid elements with r, g, b, values of 0
                    if(k!=0 )
                    {
                    sum_red=sum_red + copy[k][m].rgbtRed;
                    sum_green=sum_green + copy[k][m].rgbtGreen;
                    sum_blue=sum_blue + copy[k][m].rgbtBlue;
                    count++;
                    }
                }
            }
            copy2[i][j].rgbtRed=round(sum_red/count);
            copy2[i][j].rgbtGreen=round(sum_green/count);
            copy2[i][j].rgbtBlue=round(sum_blue/count);
        }
    }


// apply filter to BOTTOM edge of copy[][], where i=height+1  and  2<= j <= width-1

 for(int j=2; j<=width-1; j++)
    {
        int i=height;
        {
            int sum_red=0, sum_green=0, sum_blue=0;
            float count=0;
            int avg_red=1, avg_green=1, avg_blue=1;

            for(int k=i-1; k<=i+1; k++)
            {
                for(int m=j-1; m<=j+1; m++)
                {
                    // this is the filter to avoid elements with r, g, b, values of 0
                    if(k!=height+1)
                    {
                    sum_red=sum_red + copy[k][m].rgbtRed;
                    sum_green=sum_green + copy[k][m].rgbtGreen;
                    sum_blue=sum_blue + copy[k][m].rgbtBlue;
                    count++;
                    }
                }
            }
            copy2[i][j].rgbtRed=round(sum_red/count);
            copy2[i][j].rgbtGreen=round(sum_green/count);
            copy2[i][j].rgbtBlue=round(sum_blue/count);
        }
    }


// the body: 2 px removed from every edge

    for(int i=2; i<=height-1; i++)
    {
        for(int j=2; j<=width-1; j++)
        {
            int sum_red=0, sum_green=0, sum_blue=0;
            float count=0;
            int avg_red=1, avg_green=1, avg_blue=1;

            for(int k=i-1; k<=i+1; k++)
            {
                for(int m=j-1; m<=j+1; m++)
                {
                    sum_red=sum_red + copy[k][m].rgbtRed;
                    sum_green=sum_green + copy[k][m].rgbtGreen;
                    sum_blue=sum_blue + copy[k][m].rgbtBlue;
                    count++;
                }
            }

            copy2[i][j].rgbtRed=round(sum_red/count);
            copy2[i][j].rgbtGreen=round(sum_green/count);
            copy2[i][j].rgbtBlue=round(sum_blue/count);
        }
    }

// 3. extract rgb values from copy2[][] and paste back to image[][], remember there is a difference in size,
// and consider this in the limits of the areas to scan

    for(int i=1; i<=height; i++)
    {
        for(int j=1; j<=width; j++)
        {
            image[i-1][j-1].rgbtRed=copy2[i][j].rgbtRed;
            image[i-1][j-1].rgbtGreen=copy2[i][j].rgbtGreen;
            image[i-1][j-1].rgbtBlue=copy2[i][j].rgbtBlue;

        }
    }


    return;
}
