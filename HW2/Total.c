#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    int sum = 0;

    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }

    printf("Total[%d]: Sum = %d\n", getppid(), sum);

    // Total should return the sum of first n numbers (n being the value of string).

    return sum;
}