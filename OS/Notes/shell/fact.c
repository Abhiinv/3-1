#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <unistd.h>

uint64_t fact(uint64_t n) {
    if (n <= 1) return 1;

    return fact(n - 1) * n;
}

int main(int argc, char *argv[]) {
    if (argc < 2) return -1;

    // sleep(1);

    int n = atof(argv[1]);
    uint64_t res = fact(n);
    // printf("Factorial of %d: ", n);
    // printf("%" PRIu64 "\n", fact(n));

    return 0;
}