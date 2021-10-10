/*

Global Variables:
n = number of processes
bool waiting[n] <- false
bool lock <- false

Local Vars:
key

*/

#include <stdbool.h>

#define N 100

bool waiting[N];
bool lock, key;

bool test_and_set(bool *lock);

int main() {
    int i;
    do {
        /* Entry Section Starts */
        waiting[i] = true;
        key = true;

        while (waiting[i] && key)
            key = test_and_set(&lock);

        waiting[i] = false;
        /* Entry Section Ends */

        // Critical Section

        /* Exit Section Starts */
        int j = (i + 1) % N;
        while ((j != i) && !waiting[j])
            j = (j + 1) % N;

        if (j == i)
            lock = false;
        else
            waiting[i] = false;

        /* Exit Section Ends*/

        // Remainder Section

    } while (true);

    return 0;
}