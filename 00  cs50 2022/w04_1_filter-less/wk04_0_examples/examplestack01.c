void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for( int i = 0; i < height  ; i++)
    {
        for( int j = 0; j < width ; j++)
        {
            //! variables to store for new value for each color
            //! count valid pixels to count average
            int sumR = 0, sumG = 0, sumB = 0, count = 0;

            //! available pixels for each pixel
            int indexs[9][2] =
            {
                {i-1, j-1}, {i-1, j}, {i-1, j+1},
                {i, j-1}, {i, j}, {i, j+1},
                {i+1, j-1}, {i+1, j}, {i+1, j+1}
            };

            for( int k = 0; k < 9; k++)
            {
                //! only add valid pixels considering corner and edge pixels
                if( indexs[k][0] >= 0 && indexs[k][0] <= height && indexs[k][1] >= 0 && indexs[k][1] <= width)
                {
                    //! current valid pixel
                    RGBTRIPLE currentImg = image[indexs[k][0]][indexs[k][1]];
                    //! add current pixel color values to corresponding color variable
                    sumR += currentImg.rgbtRed;
                    sumB += currentImg.rgbtBlue;
                    sumG += currentImg.rgbtGreen;
                    //! increase valid pixels count
                    count++;
                }
            }
            //! set new pixel color value
            image[i][j].rgbtRed = round(sumR/ (float) count);
            image[i][j].rgbtBlue = round(sumB/ (float) count);
            image[i][j].rgbtGreen = round(sumG/ (float) count);
        }
    }
}