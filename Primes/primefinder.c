#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int isPrime(uint64_t);

// Finds the user specified number of primes
// and puts them in a new file primes.txt
int main(int argc, char **argv) {
    unsigned int n = 0;
    uint64_t curr = 2;
    FILE *ptr = fopen("primes.txt", "w");
    unsigned int P = atoi(argv[1]);
    while (n < P) {
        while (1) {
            if (isPrime(curr)) {
                fprintf(ptr, "%llu\n", curr);
                curr++;
                break;
            }
            curr++;
        }
        n++;
    }
    fclose(ptr);
    return 0;
}

// Inefficient function to check if a number is prime
int isPrime(uint64_t curr) {
    for (uint64_t comp = 2; comp < curr; comp++) {
        if ( curr % comp == 0)
            return 0;
    }
    return 1;
}
