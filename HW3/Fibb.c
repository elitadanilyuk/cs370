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

    int shm_f = shd_open(argv[1], O_RDWR, 0666);   // create/open shared memory segment

    void *shmFibbPtr = mmap(0, size, PROT_WRITE, MAP_SHARED, shm_f, 0); // map memory segment

    
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

    sprintf(shmFibbPtr, "%s", n2);

    shm_unlink(argv[1]);    // close memory segment

    // Fibb should return the nth fibonacii number (n being the value of string).

    return n2;
}