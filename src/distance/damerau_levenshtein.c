#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "macros.h"


/**
 *  Calculates and returns the Damerau-Levenshtein distance of two non NULL
 *  strings.
 *
 *  @param str1 first non NULL string
 *  @param str2 second non NULL string
 *  @param alpha_size size of the alphabet
 *
 *  @returns Damerau-Levenshtein distance of str1 and str2
 */
unsigned damerau_levenshtein(const char *str1,
                             const char *str2,
                             const unsigned alpha_size)
{
    // strings cannot be NULL
    assert(str1 != NULL);
    assert(str2 != NULL);

    // calculate size of strings
    size_t str1_len = strlen(str1);
    size_t str2_len = strlen(str2);

    // handle cases where one or both strings are empty
    if (str1_len == 0)
        return str2_len;
    if (str2_len == 0)
        return str1_len;

    // remove common substring
    // while (str1_len > 0 && str2_len > 0
    //        && EQ(str1[0], str2[0])) {
    //     str1++, str2++;
    //     str1_len--, str2_len--;
    // }

    const unsigned infinity = str1_len + str2_len;
    unsigned row, col;

    // create "dictionary"
    unsigned *dict = calloc(alpha_size, sizeof(unsigned));

    // create 2d matrix to hold calculated values
    // initializes all values to 0
    unsigned **matrix = malloc((str1_len + 2) * sizeof(unsigned *));
    for (int i = 0; i < str2_len + 2; i++)
        matrix[i] = calloc((str2_len + 2), sizeof(unsigned));

    // set all the starting values and add all characters to the dict
    matrix[0][0] = infinity;
    for (row = 1; row < str1_len + 2; row++) {
        matrix[row][0] = infinity;
        matrix[row][1] = row;
    }
    for (col = 1; col < str2_len + 2; col++) {
        matrix[0][col] = infinity;
        matrix[1][col] = col;
    }

    unsigned db;    // no idea what this is
    unsigned i, j;  // also no idea what these are
    unsigned cost;

    // fill in the matrix
    for (row = 1; row <= str1_len; row++) {
        db = 0;

        for (col = 1; col <= str2_len; col++) {
            i = dict[(int) str2[col - 1]];
            j = db;
            cost = EQ(str1[row - 1], str2[col - 1]) ? 0 : 1;

            if (cost == 0)
                db = col;

            matrix[row + 1][col + 1] = MIN4(
                matrix[row][col],
                matrix[row + 1][col],
                matrix[row][col + 1],
                matrix[i][j] + (row - i - 1) + (col - j - 1) + 1
            );
        }

        dict[(int) str1[row - 1]] = row;
    }

    unsigned result = matrix[str1_len + 1][str2_len + 1];

    // free dict
    free(dict);

    // free matrix
    for (int i = 0; i < str1_len + 2; i++) free(matrix[i]);
    free(matrix);

    return result;
}
