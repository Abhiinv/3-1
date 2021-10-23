#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 256

int pfds[2];
char buffer[BUFFER_SIZE];

int main() {
    int status;
    pid_t pid;

    if (pipe(pfds) == -1) {
        perror("Pipe creation failed\n");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("Forking process failed\n");
    }

    else if (pid == 0) {
        // Child Process
        close(pfds[0]);
        char msg[] = "IT COULD LET IN A CHILD!";
        write(pfds[1], msg, sizeof msg);
    }

    else {
        close(pfds[1]);
        wait(&status);
        read(pfds[0], buffer, BUFFER_SIZE);
        printf("Received from Child: \n--start--\n%s\n--end--\n");
    }

    return 0;
}