#include <stdio.h>
#include <stdlib.h>

long long factorial(long long n) {

    long long res = 1;
    for (int i = 2; i <= n; ++i) res = res * i;

    return res;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Invalid Parameters entered!\n");
        return 1;
    }

    int n = atoi(argv[1]);
    printf("%d!: %lld\n", n, factorial(n));
    
    return 0;
}
