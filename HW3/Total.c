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

    int shm_t = shd_open(argv[1], O_RDWR, 0666);   // create/open shared memory segment

    void *shmTotalPtr = mmap(0, size, PROT_WRITE, MAP_SHARED, shm_t, 0); // map memory segment


    int n = atoi(argv[1]);
    int sum = 0;

    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }

    printf("Total[%d]: Sum = %d\n", getppid(), sum);


    sprintf(shmTotalPtr, "%s", sum);

    shm_unlink(argv[1]);    // close memory segment

    // Total should return the sum of first n numbers (n being the value of string).

    return sum;
}