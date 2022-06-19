/*
    Takes a mandatory argument that is the name of the .txt file which contains a string.
    The Starter will read all the lines from the text file, and send each line to the child processes
    for further processing.
        a. The Starter is responsible for executing the fork() functions to launch the child process.
        b. Each child process runs the exec() function to run the program needed (Fibb, Prime, or Total),
            while also supplying the arguments that the new program needs to complete its execution.
        c. The wait() function is used to wait for the completion of the execution of the child processes,
            and WEXITSTATUS(status) function is used to obtain the result (as an eight-bit integer) from
            the three child programs.
    The Starter then saves the status. After all the processes are complete the Starter will output the
    counts of each type of characters (a code snippet is provided below).

    By: Elita Danilyuk
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        exit(EXIT_FAILURE);
    }

    FILE *filePointer = fopen(argv[1], "r");

    if (!filePointer)
    {
        printf("could not open file: error in filePointer section\n");
        exit(EXIT_FAILURE);
    }

    int size = 100;
    char line[100];

    int finalFibb, finalPrime, finalTotal = 0;

    printf("\n");

    while (fgets(line, size, filePointer))
    {

        // fork for Fibb
        pid_t child_pid = fork();

        if (child_pid >= 0) { // fork successful
            if (child_pid == 0) { // fork returns 0 for child process
                // child process
                // execute Fibb
                execlp("./Fibb", "./Fibb", (char *)line, (char *)NULL);
            } else {
                // parent process (pid)
                int status;
                printf("Starter[%d]: Forked process with ID %d.\n", getppid(), getpid());
                printf("Starter[%d]: Waiting for process [%d].\n", getppid(), getpid());
                wait(&status);
                finalFibb = WEXITSTATUS(status);
                printf("Starter[%d]: Child process %d returned %d.\n", getppid(), getpid(), finalFibb);
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
                execlp("./Prime", "./Prime", (char *)line, (char *)NULL);
            } else {
                // parent process (pid)
                int status;
                printf("Starter[%d]: Forked process with ID %d.\n", getppid(), getpid());
                printf("Starter[%d]: Waiting for process [%d].\n", getppid(), getpid());
                wait(&status);
                finalPrime = WEXITSTATUS(status);
                printf("Starter[%d]: Child process %d returned %d.\n", getppid(), getpid(), finalPrime);
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
                execlp("./Total", "Total", (char *)line, (char *)NULL);
            } else {
                // parent process (pid)
                int status;
                printf("Starter[%d]: Forked process with ID %d.\n", getppid(), getpid());
                printf("Starter[%d]: Waiting for process [%d].\n", getppid(), getpid());
                wait(&status);
                finalTotal = WEXITSTATUS(status);
                printf("Starter[%d]: Child process %d returned %d.\n", getppid(), getpid(), finalTotal);
            }
        } else {
            printf("Fork failure: in 'Total' section\n");
            exit(EXIT_FAILURE);
        }
    } // end while(file has lines)

    printf("Fibb: %d\nPrime: %d\nTotal Count: %d\n\n", finalFibb, finalPrime, finalTotal);

    fclose(filePointer);
    return 0;
}