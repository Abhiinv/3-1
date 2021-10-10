# Process Creation

- `execlp(const char* path_to_binary, const char* arg0, ..., (char *)0)`
- `pid_t wait(int *status)
> try executing ex.out binary

```C
#include <sts/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {

    pid_t pid;
    pid = fork();

    if (pid < 0) { // Error OCcured during fork
        fptintf(stderr, "Fork Failed");
        retrun 1;
    }

    else if (pid == 0) { // In Child Process
        printf("Child Process");
        execlp("/bin/ls", "ls", NULL);
        // execlp("/bin/ls", "ls", "-al", NULL); to execute with flags
        // Anything written over here will never execute, since exec never returns
    }

    else { // In Parent Process
        wait(NULL); // wait for child to complete
        printf("Child execution finished");
    }

    return 0;
}
```



Example:
```c
#include <sts/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    printf("Hello\n") 
}
```


```
Output:
Hello
Hello
```

```c
#include <sts/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    fork();
    printf("Hello\n") 
}
```

```
Output:
Hello
Hello
Hello
Hello
Hello
Hello
Hello
Hello
# (i.e. 2^3 times)
```

```
     P
    / \
    P  C1
   / \
```

## Getting pids

- `pid_t getpid()`: Get PID of process
- `pid_t getppid()`: Get PID of Parent Process

```C
#include <sts/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {

    pid_t pid;
    pid = fork();

    if (pid < 0) { // Error OCcured during fork
        fptintf(stderr, "Fork Failed");
        retrun 1;
    }

    else if (pid == 0) { // In Child Process
        printf("Child Process");
        printf("child pid: %d", getpid());
    }

    else { // In Parent Process
        printf("parent pid: %d", getpid()); // ALWAYS < child pid
        wait(NULL); // wait for child to complete
        printf("Child execution finished");
    }

    return 0;
}
```