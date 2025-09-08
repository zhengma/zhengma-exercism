#include "eliuds_eggs.h"

unsigned int egg_count(unsigned int bin)
{
    unsigned int counter = 0;
    while (bin > 0) {
        if ((bin & 1) == 1) {
            counter++;
        }
        bin >>= 1;
    }
    return counter;
}