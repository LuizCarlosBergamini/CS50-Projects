#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int length;
    {
        length = get_int("Length: ");
    }
    while (length < 1);

    int powerOf2[length];

    powerOf2[0] = 1;
    printf("%i\n", powerOf2[0]);
    for (int i = 1; i < length; i++)
    {
        powerOf2[i] = 2 * powerOf2[i - 1];
        printf("%i\n", powerOf2[i]);
    }
}