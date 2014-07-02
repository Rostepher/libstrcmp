#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "macros.h"

static char encode_char(const char c)
{
    switch (tolower(c)) {
        case 'b':
        case 'f':
        case 'p':
        case 'v':
            return '1';

        case 'c':
        case 'g':
        case 'j':
        case 'k':
        case 'q':
        case 's':
        case 'x':
        case 'z':
            return '2';

        case 'd':
        case 't':
            return '3';

        case 'l':
            return '4';

        case 'm':
        case 'n':
            return '5';

        case 'r':
            return '6';

        default:
            break;
    }

    // otherwise return '0'
    return '0';
}

char *soundex(const char *str)
{
    // string cannot be NULL
    assert(str != NULL);

    size_t str_len = strlen(str);

    // allocate space for final code
    char *code = malloc(5 * sizeof(char));

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
    for (unsigned i = 1; i < str_len && d < 4; i++) {

        // check if current char in buf is not the same as previous char
        // and that the current char is not '0'
        if (NOT_EQ(buf[i], buf[i - 1]) && NOT_EQ(buf[i], '0')) {

            // if digits separated by an 'h' or 'w' are the same, skip them
            if (i > 1 && EQ(buf[i], buf[i - 2]) && strchr("hw", str[i - 1]))
                continue;

            // add digit to the code
            code[d] = buf[i];

            // increment digit counter
            d++;
        }
    }

    // pad the end of code with '0' if too short
    while (d < 4) {
        code[d] = '0';
        d++;
    }

    return code;
}

#include <stdio.h>
int main(int argc, char **argv)
{
    assert(argc >= 2);

    char *str = argv[1];
    char *code = soundex(str);

    printf("soundex(\"%s\") = %s\n", str, code);

    free(code);
}
