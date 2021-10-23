#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*
         Consequence of Parent Sleeping: 

         Child Proc becomes a Zombie

            > grep State /proc/<child pid>/status
            < State:	Z (zombie)

            > grep State /proc/<parent pid>/status
            < State:	S (sleeping)

        */

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("Error from Fork\n");
    } else if (pid == 0) {
        printf("In Child Proc...\nCurr PID:\t%d\t\tParent PID:\t%d\n", getpid(), getppid());
        printf("Child Ending...\n");
    } else {
        printf("In Parent Proc...\nCurr PID:\t%d\t\tChild PID:\t%d\n", getpid(), pid);
        sleep(120);

        printf("Exiting Parent with Status:\t%d\n", status);
    }

    return 0;
}
