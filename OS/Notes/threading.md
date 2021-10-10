# Threads in POSIX

## Prototypes
```C
int pthread_attr_init(pthread_attr_t *attr); // 
int pthread_create(pthread_t *tid, const pthread_attr_t* attr, void* (*start_routine)(void*), void *arg);
int pthread_equal(pthread_t tid1, pthread_t tid2); // return zero if false, non zero if true
int pthread_join(pthread_t tid, void** retval);
void pthread_exit(void *ptr);
```

## Multiple Workers

```C
#define NUM_WORKERS 10

pthread_t workers[NUM_WORKERS];

// Join the 10 threads
for (int i = 0; i < NUM_WORKERS; ++i) 
    pthread_join(workers[i], NULL);
```


## Cancellation

```C
pthread_t tid;
pthread_create(&tid, &attr, void* worker, NULL); // Create thread
...
pthread_cancel(tid); // Cancel Thread
```

In target thread: (for deferred)
```C
pthread_testcancel()
```