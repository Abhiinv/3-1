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
        printf("In Child Proc...\nCurr PID:\t%d\t\tParent PID:\t%d\n", getpid(), getppid());
        sleep(5);
        printf("Child Ending...\n");
    } else {
        printf("In Parent Proc...\nCurr PID:\t%d\t\tChild PID:\t%d\n", getpid(), pid);
        wait(&status);
        printf("Exiting Parent with Status:\t%d\n", status);
    }

    return 0;
}
