#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "macros.h"


static bool is_vowel(char c) {
    switch (tolower(c)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;

        default:
            break;
    }

    return false;
}

char *double_metaphone(const char *str)
{
    // string cannot be NULL
    assert(str != NULL);
}
