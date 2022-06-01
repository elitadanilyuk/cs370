/* Starter: It is responsible for:
    1. Setting the seed, whose value is passed as an argument, using srand().
    2. Invoking functions in the Executor.
*/

#include <stdio.h>
#include "Executor.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    // if argument is correct continue, else output error message
    if (argc == 2)
    {
        // setting the seed by passed argument
        int seed = atoi(argv[1]);
        srand(seed);
        printf("[Starter]: With seed: %d\n", seed);

        // invoking Executor through get_running_ratio()
        double running_ratio = get_running_ratio();
        // printing the calculated average running ratio
        printf("[Starter]: Running ratio: %f\n\n", running_ratio);

        return 0;
    }
    else
    {
        printf("ERROR:  Incorrect number of arguments, try again.\n\n");
        return -1;
    }
}