// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            switch (argv[1][i])
            {
                case 'a':
                    printf("%c", argv[1][i] - 43);
                    break;
                case 'e':
                    printf("%c", argv[1][i] - 50);
                    break;
                case 'i':
                    printf("%c", argv[1][i] - 56);
                    break;
                case 'o':
                    printf("%c", argv[1][i] - 63);
                    break;
                default:
                    printf("%c", argv[1][i]);
                    break;
            }
        }
        printf("\n");
    }
    else
    {
        printf("ERROR\n");
        return 1;
    }
}