#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    int i;

    int n1 = 0;
    int n2 = 1;
    int n3 = n1 + n2;

    printf("Fibb[%d]: The first %d numbers of the Fibonacci sequence are:\n", getppid(), n);

    printf("%d, %d, ", n1, n2);

    for (i = 3; i <= n; ++i)
    {
        printf("%d, ", n3);
        n1 = n2;
        n2 = n3;
        n3 = n1 + n2;
    }

    printf("\n");

    // Fibb should return the nth fibonacii number (n being the value of string).

    return n2;
}