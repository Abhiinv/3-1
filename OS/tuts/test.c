#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pfds[2];
    char buf[1000];
    int status;

    pipe(pfds);
    if (!fork()) {
        // close(pfds[0]);
        write(pfds[1], "child1", 7);
        // sleep(2);
        write(pfds[1], "child2", 7);
    } else {
        // close(pfds[1]);
        read(pfds[0], buf, 500);
        printf("%s\n", buf);
        read(pfds[0], buf, 500);
        printf("%s\n", buf);
        wait(&status);
    }

    return 0;
}