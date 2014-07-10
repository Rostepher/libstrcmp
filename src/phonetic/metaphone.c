#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


static bool is_vowel(char c)
{
    switch(c) {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            return true;

        default:
            return false;
    }
}

static void remove_char(char *str, unsigned i)
{
    if (i >= strlen(str))
        return;

    memmove(&str[i], &str[i + 1], strlen(&str[i + 1]));
    str[strlen(str) - 1] = '\0';
}

/**
 *
 */
static void to_uppercase(char *str)
{
    // string cannot be NULL
    assert(str != NULL);

    size_t str_len = strlen(str);

    if (str_len == 0)
        return;

    for (unsigned i = 0; i < str_len; i++)
        str[i] = toupper(str[i]);
}

static inline void drop_duplicates(const char *str, char *buf)
{
    // string cannot be NULL
    assert(str != NULL);

    size_t str_len = strlen(str);

    if (str_len < 2)
        return;

    for (unsigned i = 1; i < str_len; i++) {
        if (str[i] == 'C' || str[i] != str[i - 1]) {

            // add non-duplicates to buffer
            strncat(buf, str[i], 1);
        }
    }
}

static inline void drop_initial_letters(char *str)
{
    // string cannot be NULL
    assert(str != NULL);

    if (strlen(str) < 2)
        return;

    if ((str[0] == 'A' && str[1] == 'E')
        || (str[0] == 'G' && str[1] == 'N')
        || (str[0] == 'K' && str[1] == 'N')
        || (str[0] == 'P' && str[1] == 'N')
        || (str[0] == 'W' && str[1] == 'R')) {

        // remove first char
        strcpy(str, &str[1]);
    }
}

static inline void drop_b_after_m_at_end(char *str)
{
    // string cannot be NULL
    assert(str != NULL);

    size_t str_len = strlen(str);

    if (strlen < 2)
        return;

    // remove 'B' by making it NULL
    if (str[str_len - 1] == 'B' && str[str_len - 2] == 'M')
        str[str_len - 1] = '\0';
}

static inline void transform_c(char *str)
{
    // string cannot be NULL
    assert(str != NULL);

    size_t str_len = strlen(str);

    // handle empty string
    if (str_len <= 0)
        return;

    // handle string of length 1
    if (str_len == 1) {
        if (str[0] == 'C')
            str[0] == 'K';
        return;
    }

    for (unsigned i = 1; i < str_len; i++) {
        if (str[i - 1] == 'C') {
            switch (str[i]) {
                case 'I':
                    // 'C' followed by 'IA'
                    if (i + 1 < str_len) {
                        if (str[i + 1] == 'A') {
                            str[i - 1] = 'X';
                            break;
                        }
                    }

                    // 'C' followed by 'I'
                    str[i - 1] = 'S';
                    break;

                // 'C' followed by 'H'
                case 'H':
                    str[i - 1] = 'X';
                    break;

                // 'C' followed by 'E' or 'Y'
                case 'E':
                case 'Y':
                    str[i - 1] = 'S';
                    break;

                default:
                    str[i - 1] = 'K';
                    break;
            }
        }
    }
}

static inline void transform_d(char *str)
{
    // string cannot be NULL
    assert(str != NULL);

    size_t str_len = strlen(str);

    // handle empty string
    if (str_len <= 0)
        return;

    // handle string of length 1 or 2
    if (str_len <= 2 && str_len > 0) {
        if (str[0] == 'D')
            str[0] = 'T';

        if (str_len == 2)
            if (str[1] == 'D')
                str[1] == 'T';

        return;
    }

    for (unsigned i = 2; i < str_len; i++) {
        if (str[i - 2] == 'D') {
            if (str[i - 1] == 'G'
                && (str[i] == 'E' || str[i] == 'Y' || str[i] == 'I')) {
                    str[i - 2] = 'J';
            } else {
                str[i - 2] = 'T';
            }
        }
    }
}

static inline void drop_g(char *str)
{
    // string cannot be NULL
    assert(str != NULL);

    size_t str_len = strlen(str);

    if (strlen < 2)
        return;

    for (unsigned i = 1; i < str_len; i++) {
        if (str[i - 1] == 'G') {
            if (str[i] == 'H' && i + 1 < str_len) {
                if (!is_vowel(str[i + 1])) {
                    str[i - 1] = '\0';
                    strcpy(&str[i - 1], &str[i]);
                }
            }
        }
    }
}

/**
 *
 */
char *metaphone(const char *str, unsigned max_len)
{
    // str cannot be NULL
    assert(str != NULL);

    size_t str_len = strlen(str);

    // handle empty string case
    if (str_len == 0)
        return str;

    // make a copy of str to manipulate and transform
    char *str_cpy = strcpy(str);

    to_uppercase(str_cpy);

    // drop duplicate adjacent letters, except for 'C'
    char buf[str_len];
    if (str_len > 1) {
        for (unsigned i = 1; i < str_len; i++) {
            if (str_cpy[i] == 'C' || str_cpy[i] == str_cpy[i - 1]) {

            }
        }
    }

}
