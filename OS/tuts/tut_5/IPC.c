#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 256

int pfds[2];
char buffer[BUFFER_SIZE];

int main() {
    if (pipe(pfds) == -1) {
        perror("Pipe creation failed\n");
        exit(1);
    }


    int status;
    pid_t pid = fork();

    if (pid < 0) {
        perror("Forking process failed\n");
    }

    else if (pid == 0) {
        // Child Process
        dup2(pfds[1], 1); // Why?
        close(pfds[0]);
        close(pfds[1]);

        if (execlp("ls", "ls", NULL) == -1) {
            perror("Calling ls failed\n");
        }

        else {
            if (fork() == 0) {
                dup2(pfds[0], 0);
            }
        }


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