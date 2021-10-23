#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

    pid_t  pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("Error from Fork\n");
    } else if (pid == 0) {
    } else {
    }

    return 0;
}
