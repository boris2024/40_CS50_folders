#include "helpers.h"
#include<stdio.h>

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    // TO DO TO DO TO DO
    RGBTRIPLE pixel = image[0][0];

    int i=0, j=0;

    // i moves along the columns, j moves along the ranks

    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            if(image[i][j].rgbtRed==0 && image[i][j].rgbtGreen==0 && image[i][j].rgbtBlue==0)
            {
            image[i][j].rgbtRed=255;
            image[i][j].rgbtGreen=0;
            image[i][j].rgbtBlue=0;
            }
        }
    }

}
