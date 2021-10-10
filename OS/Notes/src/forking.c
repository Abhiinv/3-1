#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {

    pid_t pid = fork();

    if (pid > 0) {
        printf("Parent process\n");
        wait(NULL);
    } else {
        printf("Child process\n");
        execlp("../shell/tut3_7.sh", "print_cmd_args", "hjashdkjhas", NULL);

    }

    return 0;
}