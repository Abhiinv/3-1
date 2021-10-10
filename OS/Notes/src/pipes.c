#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main() {
    char write_msg[BUFFER_SIZE] = "Greetings";
    char read_msg[BUFFER_SIZE];

    int fd[2];
    pid_t pid;

    // Create Pipe
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe Creation Failed");
        return 1;
    }

    // Create a Child Procs
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork Faield");
        return 1;
    }

    // Parent Procs
    if (pid > 0) {
        close(fd[READ_END]); // Close unused end of the pipe
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
        close(fd[WRITE_END]);
    }

    else {
        
    }
}