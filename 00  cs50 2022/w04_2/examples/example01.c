  #include"helpers.h"
    #include <math.h>

    int check_cap(int num);

    void edges(int height, int width, RGBTRIPLE image[height][width])
    {

    RGBTRIPLE image_copy[height][width];
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    int kernel_blue = 0, kernel_green = 0, kernel_red = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           int gxsum_blue = 0, gxsum_green = 0, gxsum_red = 0;
           int gysum_blue = 0, gysum_green = 0, gysum_red = 0;

            for (int k = i - 1, m = 0;   k <= i + 1;    k++, m++)
            {
                for (int l = j - 1, n = 0;   l <= j+1;   l++, n++)
                {
                    //Ignoring Unnecessary pixels for calculation
                    if (k < 0 || k > height || l < 0 || l > width)
                    {
                        continue;
                    }
                    else
                    {
                        gxsum_blue += image[k][l].rgbtBlue * Gx[m][n];
                        gxsum_green += image[k][l].rgbtGreen * Gx[m][n];
                        gxsum_red += image[k][l].rgbtRed * Gx[m][n];
                        gysum_blue += image[k][l].rgbtBlue * Gy[m][n];
                        gysum_green += image[k][l].rgbtGreen * Gy[m][n];
                        gysum_red += image[k][l].rgbtRed * Gy[m][n];
                    }
                }
            }
            //Sobel's Algorithm for Final channel value
            kernel_blue = round(sqrt(pow(gxsum_blue, 2) + pow(gysum_blue, 2)));
            kernel_green = round(sqrt(pow(gxsum_green, 2) + pow(gysum_green, 2)));
            kernel_red = round(sqrt(pow(gxsum_red, 2) + pow(gysum_red, 2)));

            kernel_blue = check_cap(kernel_blue);
            kernel_green = check_cap(kernel_green);
            kernel_red = check_cap(kernel_red);

            image_copy[i][j].rgbtBlue = kernel_blue;
            image_copy[i][j].rgbtGreen = kernel_green;
            image_copy[i][j].rgbtRed = kernel_red;
        }
    }

    //copying edge detected info into original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j ++)
        {
            image[i][j] = image_copy[i][j];
        }
    }
    return;
    }

  //Capping the value at 255
  int check_cap(int num)
  {
      if (num > 255)
      {
          return 255;
      }
      else
      {
          return num;
      }
  }