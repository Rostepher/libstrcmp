#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "macros.h"

static char encode_char(const char c)
{
    switch (tolower(c)) {
        case 'b':
        case 'p':
            return '1';

        case 'f':
        case 'v':
            return '2';

        case 'c':
        case 'k':
        case 's':
            return '3';

        case 'g':
        case 'j':
            return '4';

        case 'q':
        case 'x':
        case 'z':
            return '5';

        case 'd':
        case 't':
            return '6';

        case 'l':
            return '7';

        case 'm':
        case 'n':
            return '8';

        case 'r':
            return '9';

        default:
            break;
    }

    // otherwise return '0'
    return '0';
}

char *refined_soundex(const char *str)
{
    // string cannot be NULL
    assert(str != NULL);

    size_t str_len = strlen(str);

    // final code buffer
    char code[str_len + 1];

    // temporary buffer to encode string
    char buf[str_len];

    // set first value to first char in str
    code[0] = toupper(str[0]);

    // number of digits in code
    unsigned d = 1;

    // encode all chars in str
    for (unsigned i = 0; i < str_len; i++)
        buf[i] = encode_char(str[i]);

    // add all viable chars to code
    char prev = '\0';
    for (unsigned i = 0; i < str_len; i++) {

        // check if current char in buf is not the same as previous char
        if (NOT_EQ(buf[i], prev)) {

            // add digit to the code
            code[d] = buf[i];

            // increment digit counter
            d++;

            // set prev to current char
            prev = buf[i];
        }
    }

    // allocate space for final code
    // d will be length of the code + 1
    char *result = malloc(d * sizeof(char));

    // copy final code into result and null terminate
    for (unsigned i = 0; i < d; i++)
        result[i] = code[i];
    result[d] = '\0';

    return result;
}
