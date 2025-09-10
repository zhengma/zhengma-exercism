#include "collatz_conjecture.h"

int steps(int start) {
    if (start <= 0) {
        return ERROR_VALUE;
    }
    int counter = 0;
    while (start != 1) {
        start = ((start & 1) == 0) ? start >> 1 : start * 3 + 1;
        counter++;
    }
    return counter;
}