#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Checks if the RGB atributtes of the RGBTRIPLE image is equal to 0 AKA black
            if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtBlue == 0x00)
            {
                image[i][j].rgbtRed = 0x00;
                image[i][j].rgbtGreen = 0xa2;
                image[i][j].rgbtBlue = 0xff;
            }
        }
    }
}
