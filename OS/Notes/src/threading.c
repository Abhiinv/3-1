#include <pthread.h>
#include <stdio.h>

int sum;
void *runner(void *param);


int main(int argc, char *argv[]) {
    pthread_t tid; // Thread Identifier
    pthread_attr_t attr; // Thread attributes

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return -1;
    }


    if (atoi(argv[1]) < 0) {
        fprintf(stderr, "Number must be positive\n");
        return -1;
    }

    pthread_attr_init(&attr); // Set the default attributes
    pthread_create(&tid, &attr, runner, (void *)argv[1]); // Create the thread
    pthread_join(tid, NULL); // Wait for thread to to exit

    printf("Sum: %d\n", sum);

    return 0;
}

void *runner(void *param) {
    int i;
    int upper = atoi((char *)param);
    sum = 0;

    for (i = 1; i <= upper; i++) { 
        sum += i;
    }
    pthread_exit(NULL);
}