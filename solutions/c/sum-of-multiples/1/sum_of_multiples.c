#include "sum_of_multiples.h"

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit)
{
    unsigned int current;
    int flag; // flag == 0 means this multiple has already been counted
    unsigned int total = 0;
    for (size_t i = 0;i < number_of_factors; i++) {
        if (factors[i] == 0) continue;
        current = factors[i];
        while (current < limit) {
            // printf("%d %d\n", current, limit);
            flag = 1;
            for (size_t j = 0; j < i; j++) {
                if ((factors[j] != 0) && (current % factors[j] == 0)) {
                    flag = 0;
                }
            }
            if (flag) {
                total += current;   
            }
            current += factors[i];
        }
    }
    return total;
}