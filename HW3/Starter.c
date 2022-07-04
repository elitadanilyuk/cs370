/*
    By: Elita Danilyuk
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

#define READ_END 0
#define WRITE_END 1

int main(int argc, char **argv)
{
    if (argc != 2){
        exit(EXIT_FAILURE);
    }

    int size = 32;

    int fd[2];  // space for 2-way pipe
    char buffer[16];

    if (pipe(fd) == -1)      // error checking
    {
        fprintf(stderr, "Pipes creation failed.\n");
        return -1;
    }

    pid_t child_pid = fork(); // creating child

    if (child_pid < 0) {     // error checking
        fprintf(stderr, "Fork failed.\n");
        return -1;
    } else if (child_pid == 0) {                  
        // in child process (doing writing)
        execlp("./CharacterReader", "CharacterReader", buffer, NULL);
    } else {  // parent process does reading
        int status;
        wait(&status);

        close(fd[WRITE_END]);

        int received_count = read(fd[READ_END], buffer, sizeof(buffer));
        buffer[received_count] = '\0';

        printf("Message received from child: %s\n", buffer);
    }
    
        // shm_unlink(shm_name);       // unlinking shared memory segment to clean
        // waitpid(getpid, &status, WCONTINUE);

        
        // execlp("./Fibb", "./Fibb", (char *)line, (char *)NULL);
        // execlp("./Prime", "./Prime", (char *)line, (char *)NULL);
        // execlp("./Total", "Total", (char *)line, (char *)NULL);


    // naming memory segments
    char shm_fibb[] = "Shared_Mem_Fibb";
    char shm_prime[] = "Shared_Mem_Prime";
    char shm_total[] = "Shared_Mem_Total";

    int shm_f = shm_open(shm_fibb, O_CREAT | O_RDWR, 0666);
    int shm_p = shm_open(shm_prime, O_CREAT | O_RDWR, 0666);
    int shm_t = shm_open(shm_total, O_CREAT | O_RDWR, 0666);

    // specifying the number of bytes
    ftruncate(shm_f, size);
    ftruncate(shm_p, size);
    ftruncate(shm_t, size);

    // mapping the memory segments
    void *shmFibbPtr = mmap(0, size, PROT_READ, MAP_SHARED, shm_f, 0);
    void *shmPrimePtr = mmap(0, size, PROT_READ, MAP_SHARED, shm_p, 0);
    void *shmTotalPtr = mmap(0, size, PROT_READ, MAP_SHARED, shm_t, 0);

    printf("Starter [%d]: Created shared memory \"SHM_Fibb\" with FD: %d", getppid(), shm_f);
    printf("Starter [%d]: Created shared memory \"SHM_PRIME\" with FD: %d", getppid(), shm_p);
    printf("Starter [%d]: Created shared memory \"SHM_Total\" with FD: %d", getppid(), shm_t);


    printf("\n\n\n\n");



    FILE *filePointer = fopen(argv[1], "r");

    if (!filePointer)
    {
        printf("could not open file: error in filePointer section\n");
        exit(EXIT_FAILURE);
    }

    int finalFibb, finalPrime, finalTotal = 0;

    printf("\n");

    // fork for Fibb
    child_pid = fork();

    if (child_pid >= 0) { // fork successful
        if (child_pid == 0) { // fork returns 0 for child process
            // child process
            // execute Fibb
            execlp("./Fibb", "./Fibb", shm_f, buffer, NULL);
        } else {
            // parent process (pid)
            int status;
            wait(&status);
            finalFibb = shm_f;
            shm_unlink(shmFibbPtr);
        }
    } else {
        printf("Fork failure: in 'Fibb' section\n");
        exit(EXIT_FAILURE);
    }

    // fork for Prime
    child_pid = fork();

    if (child_pid >= 0) { // fork successful
        if (child_pid == 0) { // fork returns 0 for child process
            // child process
            // execute Prime
            execlp("./Prime", "./Prime", shm_p, buffer, NULL);
        } else {
            // parent process (pid)
            int status;
            wait(&status);
            finalPrime = shm_p;
            shm_unlink(shmPrimePtr);
        }
    } else {
        printf("Fork failure: in 'Prime' section\n");
        exit(EXIT_FAILURE);
    }

    // fork for Total
    child_pid = fork();

    if (child_pid >= 0) { // fork successful
        if (child_pid == 0) { // fork returns 0 for child process
            // child process
            // execute Total
            execlp("./Total", "Total", shm_t, buffer, NULL);
        } else {
            // parent process (pid)
            int status;
            wait(&status);
            finalTotal = shm_t;
            shm_unlink(shmTotalPtr);
        }
    } else {
        printf("Fork failure: in 'Total' section\n");
        exit(EXIT_FAILURE);
    }



    printf("Fibb: %d\nPrime: %d\nTotal Count: %d\n\n", finalFibb, finalPrime, finalTotal);

    fclose(filePointer);
    return 0;
}