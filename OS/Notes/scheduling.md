# Pthread schedlung

API Allows specifying PCS, or SCS during thread creation:

- `PTHREAD_SCOPE_PROCESS`
- `PTHREAD_SCOPRE_SYSTEM`


`int pthread_attr_setscore(pthread_attr_t *attr, int scope)`
`int pthread_attr_getscore(pthread_attr_t *attr, int *scope)`

on success returns 0; on error return non-zero error numebr



```C
#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 5

int main(int argc, char *argv[]) {
    int i, scope;
    pthread_t tid[NUM_THREADS];
    pthread_attr_t attr;

    pthread_attr_inti(&attr);

    if (pthread_attr_getscope(&attr, &scope) != 0) 
        fprintf(stderr, "Error");

    else {
        if (scope == PTHREAD_SCOPE_PROCESS) 
            printf("PTHREAD_SCOPE_PROCESS");
        else if (scope == PTHREAD_SCOPE_PROCESS) 
            printf("PTHREAD_SCOPE_PROCESS");
        else 
            fprintf(stderr, "Illegal scope");

    }

    pthread_attr_setscope(&attr, PTHERAD_SCOPE_SYSTEM);


    for (int i = 0; i < NUM_THREAD; ++i) 
        pthread_create(&tid[i], &attr, runner, NULL);
}


```