#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    //creates times variable
    int times = 0;

    //makes the number divide through all numbers between 2 and the number itself
    for (int i = 2; i <= number; i++)
    {
        float result = number % i;
        if (result == 0)
        {
            times++;
        }
    }

    bool value = false;

    if (times == 1)
    {
        value = true;
    }
    return value;
}
