#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "macros.h"


/**
 *
 */
int damerau_levenshtein(const char *str1, const char *str2)
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
    // while (str1_len > 0 && str2_len > 0
    //        && EQ(str1_ptr[0], str2_ptr[0])) {
    //     str1_ptr++, str2_ptr++;
    //     str1_len--, str2_len--;
    // }

    unsigned row, col;

    // initialize matrix to hold distance values
    unsigned **matrix = malloc((str1_len + 1) * sizeof(unsigned *));
    for (row = 0; row <= str1_len; row++)
        matrix[row] = malloc((str2_len + 1) * sizeof(unsigned));

    // set all the starting values and add all characters to the dict
    matrix[0][0] = 0;
    for (row = 1; row <= str1_len; row++) {
        matrix[row][0] = row;
    }
    for (col = 1; col <= str2_len; col++) {
        matrix[0][col] = col;
    }

    // add code here

    // free matrix
    for (int i = 0; i < str1_len + 1; i++) free(matrix[i]);
    free(matrix);

    return result;
}
