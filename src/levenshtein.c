#include <stdlib.h>
#include <string.h>

#include "macros.h"

/**
 *  Calculates and returns the Levenshtein distance of two non NULL strings.
 *  More information about the algorithm can be found here:
 *      https://en.wikipedia.org/wiki/Levenshtein_distance
 *
 *  @param str1 first non NULL string
 *  @param str2 second non NULL string
 *
 *  @returns the levenshtein distance of str1 and str2
 */
unsigned levenshtien(const char *str1, const char *str2)
{
    // check for NULL pointers
    if (str1 == NULL && str2 == NULL)
        return 0;

    if (str1 != NULL && str2 == NULL)
        return strlen(str1);

    if (str1 == NULL && str2 != NULL)
        return strlen(str2);

    // calculate length of strings
    size_t str1_len = strlen(str1);
    size_t str2_len = strlen(str2);

    // handle cases where one or both strings are empty
    if (str1_len == 0)
        return (str2_len == 0) ? 0 : 1;

    // initialize variables
    unsigned i, k;
    unsigned last_diag, current, cost;

    // remove common substring
    while (str1_len > 0 && str2_len > 0 && EQ(str1[0], str2[0]))
        str1++, str2++, str1_len--, str2_len--;

    // initialize array to hold values
    unsigned *column = calloc(str1_len + 1,  sizeof(unsigned));
    for (y = 1; y <= str1_len; y++) column[y] = y;

    // itterate through the imagined rows of arrays
    for (x = 1; x <= str2_len + 1; x++) {
        column[0] = x;
        last_diag = x - 1;  // remember the last first slot

        // itterate throught each member of the column
        for (y = 1; y <= str1_len; y++) {
            // remember the diagonal before overwriting the array
            current = column[y];

            // calculate the cost
            cost = EQ(str1[y-1], str2[x-1]) ? 0 : 1;

            // determine min of the possible values
            column[y] = MIN3(column[y] + 1, column[y-1] + 1, last_diag + cost);

            // remember the new last_diag
            last_diag = current;
        }
    }

    free(column);
    return last_diag;
}
