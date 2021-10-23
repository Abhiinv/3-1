#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int status;

    if (fork() == 0) {
        // execlp("ls", "ls", "-l", "-a", NULL);
        // execlp("ls", "ls", "-la", NULL);
        execlp("ls", "ls", "-lA", NULL);

        printf("Somehow you insanely fucked up. This should literally not be possible. All the best\n");
    } else {
        wait(&status);
    }

    return 0;
}
