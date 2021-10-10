#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {

    pid_t pid = fork();

    if (pid > 0) {
        printf("parent process: %d\n", getpid());
        sleep(6);
    } else {
        printf("parent PID: %d\n", getppid());
        printf("Child Process: %d\n", getpid());
        sleep(20);
        printf("orphaned parent PID: %d\n", getppid());
        exit(0);
    }

    return 0;
}