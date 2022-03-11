// *******************************************
// Program to check if the square of a prime greater than
// 3 is one greater than a multiple of 24.
// Checks all primes in primes.txt, one prime per line
// *******************************************
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int check(uint64_t);

int main() {
    FILE *fp = fopen("primes.txt", "r");
    size_t len = 0;
    char *line = NULL;
    unsigned int curr = 0;

    while (getline(&line, &len, fp) != -1) {
        curr = atoi(line);
        if (curr == 2 || curr == 3)
            continue;
        if (check(curr)) {
            printf("Works for %u\n", curr);
        } else {
            printf("Does not work for %u!\n", curr);
            return 0;
        }
    }

    fclose(fp);
}

int check(uint64_t prime) {
    if ((prime*prime) % 24 == 1)
        return 1;
    return 0;
}
