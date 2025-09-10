#include "reverse_string.h"

char *reverse(const char *value)
{
    size_t length = 0;
    while(value[length] != '\0') {
        length++;
    }
    char *result = (char*)malloc((length + 1) * sizeof(char));
    for(size_t i = 0; i < length; i++) {
        result[i] = value[length - 1 - i];
    }
    result[length] = '\0';
    return result;
}