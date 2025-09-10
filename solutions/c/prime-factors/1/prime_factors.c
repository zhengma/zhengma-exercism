#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]) {
    size_t count = 0;
    while (n > 1) {
        for(uint64_t factor = 2; factor <= n; factor++) {
            if (n % factor == 0) {
                factors[count] = factor;
                count++;
                n /= factor;
                break;
            }
        }
    }
    return count;
}