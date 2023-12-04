
// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

for (int i = 0; i < height; i++)
    {
        // Loop through columns
        for (int j = 0; j < width; j++)
        {
            // Initialise ints
            float Gx_red;
            float Gx_blue;
            float Gx_green;
            float Gy_red;
            float Gy_blue;
            float Gy_green;

int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

// loop through each row and each pixel of the image
for (int i = 0; i < height; i++)
{
    for (int j = 0; j < width; j++)
    {
        int redx = 0;
        int greenx = 0;
        int bluex = 0;

        int redy = 0;
        int greeny = 0;
        int bluey = 0;

        // loop through the pixels 1 row and 1 column from the pixel
        for (int k = 0; k < 3; k++)
        {
            for (int l = 0; l < 3; l++)
            {
                // consider pixels in edges
                if (i - 1 + k < 0 || i - 1 + k > height - 1 || j - 1 + l < 0 || j - 1 + l > width - 1)
                {
                    continue;
                }

                // calcuate Gx for each color
                redx = redx + (image[i - 1 + k][j - 1 + l].rgbtRed * Gx[k][l]);
                greenx = greenx + (image[i - 1 + k][j - 1 + l].rgbtGreen * Gx[k][l]);
                bluex = bluex + (image[i - 1 + k][j - 1 + l].rgbtBlue * Gx[k][l]);

                // calculate Gy for each color
                redy = redy + (image[i - 1 + k][j - 1 + l].rgbtRed * Gy[k][l]);
                greeny = greeny + (image[i - 1 + k][j - 1 + l].rgbtGreen * Gy[k][l]);
                bluey = bluey + (image[i - 1 + k][j - 1 + l].rgbtBlue * Gy[k][l]);
            }
        }
        // calculate square root of Gx2 + Gy2 for each color
        float r = sqrt((redx * redx) + (redy * redy));
        float g = sqrt((greenx * greenx) + (greeny * greeny));
        float b = sqrt((bluex * bluex) + (bluey * bluey));

        // round to nearest integer and cap at 255
        int red =  round(r);
        int green = round(g);
        int blue = round(b);

        if (red > 255)
            red = 255;
        if (green > 255)
            green = 255;
        if (blue > 255)
            blue = 255;

        // replace color values with new value
        image[i][j].rgbtRed = red;
        image[i][j].rgbtBlue = blue;
        image[i][j].rgbtGreen = green;
    }
}
return;