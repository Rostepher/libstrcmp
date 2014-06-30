#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "macros.h"


/**
 *
 */
unsigned optimal_string_alignment(const char *str1, const char *str2)
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

    // create new string pointers
    char *str1_ptr = str1;
    char *str2_ptr = str2;

    // remove common substring
    while (str1_len > 0 && str2_len > 0
           && EQ(str1_ptr[0], str2_ptr[0])) {
        str1_ptr++, str2_ptr++;
        str1_len--, str2_len--;
    }

    unsigned row, col, cost, result;

    // initialize matrix to hold distance values
    unsigned **matrix = malloc((str1_len + 1) * sizeof(unsigned *));
    for (unsigned i = 0; i <= str1_len; i++)
        matrix[i] = calloc((str2_len + 1), sizeof(unsigned));

    // set all the starting values
    matrix[0][0] = 0;
    for (row = 1; row <= str1_len; row++)
        matrix[row][0] = row;
    for (col = 1; col <= str2_len; col++)
        matrix[0][col] = col;

    // itterate through and fill in the matrix
    for (row = 1; row <= str1_len; row++) {
        for (col = 1; col <= str2_len; col++) {
            cost = EQ(str1_ptr[row - 1], str2_ptr[col - 1]) ? 0 : 1;

            matrix[row][col] = MIN3(
                matrix[row - 1][col] + 1,         // deletion
                matrix[row][col - 1] + 1,         // insertion
                matrix[row - 1][col - 1] + cost     // substitution
            );

            // transpositions
            if (row > 1 && col > 1
                && EQ(str1_ptr[row], str2_ptr[col - 1])
                && EQ(str1_ptr[row - 1], str2_ptr[col])) {

                matrix[row][col] = MIN(
                        matrix[row][col],
                        matrix[row - 2][col - 2] + cost
                );
            }
        }
    }

    result = matrix[str1_len][str2_len];

    for (unsigned i = 0; i < str1_len + 1; i++)
        free(matrix[i]);
    free(matrix);

    return result;
}
