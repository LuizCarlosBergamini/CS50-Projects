#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // iterates for each pixel of the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // take the average number of rgbt colors
            float average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;
            // turn all the rgbt colors to the average number
            image[i][j].rgbtRed = (int) average;
            image[i][j].rgbtGreen = (int)  average;
            image[i][j].rgbtBlue = (int) average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    // iterate for each row
    for (int i = 0; i < height; i++)
    {
        // iterate for each column (or pixel in this case)
        for (int j = 0; j < width; j++)
        {
            // create actualpixel variable
            RGBTRIPLE actualpixel;
            // actualpixel gets the last pixel of the image
            for (int k = 0; k < (width*2) - j; k++)
            {
                actualpixel = image[i][k];
            }
            image[i][j] = actualpixel;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float amountRed = 0;
            float amountGreen = 0;
            float amountBlue = 0;
            int count = 0;
            // iterate over neighboring rows
            for (int row = i - 1; row <= i + 1; row++)
            {
                // check if neighboring row is out of bounds
                if (row < 0 || row >= height)
                {
                    continue;
                }

                // iterate over neighboring columns
                for (int col = j - 1; col <= j + 1; col++)
                {
                    // check if neighboring column is out of bounds
                    if (col < 0 || col >= width)
                    {
                        continue;
                    }

                    // access neighboring pixel in image array
                    RGBTRIPLE neighbor = image[row][col];

                    // do something with neighboring pixel
                    amountRed += neighbor.rgbtRed;
                    amountGreen += neighbor.rgbtGreen;
                    amountBlue += neighbor.rgbtBlue;
                    count++;
                }
            }

            image[i][j].rgbtRed = amountRed / count;
            image[i][j].rgbtGreen = amountGreen / count;
            image[i][j].rgbtBlue = amountBlue / count;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    RGBTRIPLE multx[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    RGBTRIPLE multy[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int row = i - 1; row <= i + 1; row++)
            {
                if (row < 0 || row >= height)
                {
                    continue;
                }

                for (int col = j - 1; col <= j + 1; col++)
                {
                    if (row < 0 || row >= height)
                    {
                    continue;
                    }

                    //calcula no 2d array o valor da cor do pixel atual vezes o numero em Gx e Gy
                    multx[row][col].rgbtRed = Gx[row][col] * image[row][col].rgbtRed;
                    multx[row][col].rgbtGreen = Gx[row][col] * image[row][col].rgbtGreen;
                    multx[row][col].rgbtBlue = Gx[row][col] * image[row][col].rgbtBlue;
                    multy[row][col].rgbtRed = Gy[row][col] * image[row][col].rgbtRed;
                    multy[row][col].rgbtGreen = Gy[row][col] * image[row][col].rgbtGreen;
                    multy[row][col].rgbtBlue = Gy[row][col] * image[row][col].rgbtBlue;
                }
            }

            RGBTRIPLE sumx = 0;
            sumx.rgbtRed += (int) multx[i][j].rgbtRed;
            sumx.rgbtGreen += (int) multx[i][j].rgbtGreen;
            sumx.rgbtBlue += (int) multx[i][j].rgbtBlue;

            }
        }
    }
    return;
}
