#ifndef LUHN_H
#define LUHN_H

#include <stdbool.h>

int digit(char *c, bool parity);
bool luhn(const char *num);

#endif
