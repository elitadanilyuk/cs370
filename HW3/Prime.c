#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
// #include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>


int main(int argc, char **argv)
{
    int size = 32;

    int shm_p = shd_open(argv[1], O_RDWR, 0666);   // create/open shared memory segment

    void *shmPrimePtr = mmap(0, size, PROT_WRITE, MAP_SHARED, shm_p, 0); // map memory segment


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


    sprintf(shmPrimePtr, "%s", (i - 1));

    shm_unlink(argv[1]);    // close memory segment

    // Prime should return the nth prime number(n being the value of string).
    return (i - 1);
}