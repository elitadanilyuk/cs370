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

int main(int argc, char ** argv) {
    int fd[2]; 
    close(fd[READ_END]);                    // closing read-end of pipe
    char message[10];
    int number = 370;
    sprintf(message, "%d", number);         // writing number into msg array to put in pipe
    write(fd[WRITE_END], message, strlen(message) + 1);
    close(fd[WRITE_END]);

    return 0;
}