#include <cs50.h>
#include <stdio.h>

int calculatePopulation();

int main(void)
{
    //Prompt for start size
    int start;
    do
    {
       start = get_int("Start size: ");
    }
    while (start < 9);
    //Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    //Print number of years
    int result = calculatePopulation(start, end);
    printf("Years: %i\n", result);
}

//Calculate number of years until we reach threshold
int calculatePopulation(int start, int end)
{
    int years = 0;
    for (int i = start; start < end;)
    {
        int born = start / 3;
        int dead = start / 4;

        start = start + born - dead;
        years++;

    }

    return years;
}
