#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 30


int main() {
    int pfds[2]; // Pipe File Descriptors with 2 elements
    char buffer[BUFFER_SIZE];

    if (pipe(pfds) == -1) {
        perror("error creating pipe\n");
        exit(1);
    }

    printf("Writing to the file descriptor:\t\t%d\n", pfds[1]);
    write(pfds[1], "DAMNNN!", 8);

    printf("Reading from the file descriptor:\t%d\n", pfds[0]);
    read(pfds[0], buffer, 8);

    printf("Contents read:\nStart---\n%s\n---End\n", buffer);


    return 0;
}