// Blur image

//! by jonathandavies

void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE imgbuffer[height][width];
    // Create an RGBTRIPLE 2-D array to store modified pixels.

    float counter = 0.00;
    int redsum, bluesum, greensum;
    redsum = bluesum = greensum = 0;

    //! buffer image is created
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imgbuffer[i][j] = image[i][j];
        }
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = - 1; k <= 1; k++) // Iterate from top to bottom of nearby pixels
            {
                for (int l = -1; l <= 1; l++) // Iterate left to right of nearby pixels
                {
                    if (i + k >= 0 && i + k <= height && j + l >= 0 && j + l <= width) // check if pixel fits
                    {
                        redsum += image[i + k][j + l].rgbtRed;
                        greensum += image[i + k][j + l].rgbtGreen;
                        bluesum += image[i + k][j + l].rgbtBlue;
                        counter += 1;
                    }

                }
            }


            imgbuffer[i][j].rgbtRed = round(redsum / counter);
            imgbuffer[i][j].rgbtGreen = round(greensum / counter);
            imgbuffer[i][j].rgbtBlue = round(bluesum / counter);

            counter = 0;
            redsum = bluesum = greensum = 0;
        }
    }

    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            image[x][y] = imgbuffer[x][y];
        }
    }
    return;
}