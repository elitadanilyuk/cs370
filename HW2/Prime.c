#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    int i = 3;
    int count, x;
    printf("Prime [%d]: First %d prime numbers are:\n", getppid(), n);

    if (n >= 1)
    {
        printf("2, ");
    }

    for (count = 2; count <= n; ++i)
    {
        for (x = 2; x < i; x++)
        {
            if ((i % x) == 0)
            {
                break;
            }
        }

        if (x == i)
        {
            printf("%d, ", i);
            count++;
        }
    }

    printf("\n");

    // Prime should return the nth prime number(n being the value of string).
    return (i - 1);
}