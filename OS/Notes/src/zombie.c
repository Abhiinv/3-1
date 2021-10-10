#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {

    pid_t pid = fork();

    if (pid > 0) {
        sleep(10);
        wait(NULL);
        sleep(200);
    } else {
        printf("%d\n", getpid());
        exit(0);
    }

    return 0;
}