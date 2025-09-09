#include "luhn.h"

int digit(char *c, bool parity)
{
    if (parity) {
        return *c - '0';
    }
    return (((*c - '0') << 1) <= 9) ? ((*c - '0') << 1) : ((*c - '0') << 1) - 9;
}

bool luhn(const char *num)
{
    char *ptr = (char*)num;
    bool parity;
    unsigned int sum = 0;
    unsigned int counter = 0;
    while (*ptr != '\0') {
        ptr++;
    }
    ptr--;
    // if (ptr == num) return false;
    parity = true;
    while (ptr >= num) {
        if (*ptr == ' ') {
            ptr--;
            continue;
        }
        if ((*ptr < '0') || (*ptr > '9')) {
            return false;
        }
        sum += digit(ptr, parity);
        parity = !parity;
        ptr--;
        counter++;
    }
    if (counter <= 1) {
        return false;
    }
    return (sum % 10 == 0);
}