#include <assert.h>
#include <stddef.h>
#include <string.h>

/**
 *  Computes and returns the hamming distance between two strings. Both strings
 *  must have the same length and not be NULL.
 *
 *  @param str1 first string
 *  @param str2 second string
 *
 *  @returns hamming distance or -1 if str1 and st2 did not have the same
 *      length or if one or both str1 and str2 were NULL
 */
int hamming(const char *str1, const char *str2)
{
    // strings cannot be NULL
    assert(str1 != NULL);
    assert(str2 != NULL);

    // calculate length of strings
    size_t str1_len = strlen(str1);
    size_t str2_len = strlen(str2);

    // handle cases where one or both strings are empty
    if (str1_len != str2_len
        || (str1_len == 0 && str2_len == 0))
        return -1;

    // create separate pointers
    char *str1_ptr = str1;
    char *str2_ptr = str2;

    int dist = 0;
    while (str1_len > 0 && str2_len > 0) {
        dist += (*str1_ptr == *str2_ptr);
        str1_ptr++, str2_ptr++;
        str1_len--, str2_len--;
    }

    return dist;
}