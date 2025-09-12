#include "matching_brackets.h"

bool is_paired(const char *input) {
    char stack[MAX_STACK_SIZE];
    char *sp = stack;
    char *current = (char*)input;
    while (*current != '\0') {
        if ((*current == '(') || (*current == '[') || (*current == '{')) {
            *sp = *current;
            sp++;
        } else if (*current == ')') {
            if ((sp <= stack) || (*(sp - 1) != '(')) return false;
            sp--;
        } else if (*current == ']') {
            if ((sp <= stack) || (*(sp - 1) != '[')) return false;
            sp--;
        } else if (*current == '}') {
            if ((sp <= stack) || (*(sp - 1) != '{')) return false;
            sp--;
        }
        current++;
    }
    if (sp > stack) return false;
    return true;
}