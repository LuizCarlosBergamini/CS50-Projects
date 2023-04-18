#include <cs50.h>
#include <stdio.h>

void createPyramid();

int main(void)
{
    //creates a variable called height and ask the user for the height of pyramid
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    //create the pyramid of selected height
    createPyramid(height);

}










void createPyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int j = i; j <= height - 1; j++)
        {
            printf(" ");
        }

        switch (i)
        {
            case 1:
                printf("#  #\n");
                break;

            case 2:
                printf("##  ##\n");
                break;

            case 3:
                printf("###  ###\n");
                break;

            case 4:
                printf("####  ####\n");
                break;

            case 5:
                printf("#####  #####\n");
                break;

            case 6:
                printf("######  ######\n");
                break;

            case 7:
                printf("#######  #######\n");
                break;

            case 8:
                printf("########  ########\n");
                break;
        }
    }
}


