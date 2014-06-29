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

    // initialize size and counter variables
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);

    // remove common substring
    // while (str1_len > 0 && str2_len > 0 && EQ(str1[0], str2[0]))
    //     str1++, str2++, str1_len--, str2_len--;

    // handle cases where one string is empty
    if (!str1_len) return str2_len;
    if (!str2_len) return str2_len;

    // initialize matrix to hold distance values
    int **matrix = malloc((str1_len + 1) * sizeof(int*));
    for (x = 0; x <= str1_len; x++)
        matrix[x] = malloc((str2_len + 1) * sizeof(int));

    // set all the starting values and add all characters to the dict
    matrix[0][0] = 0;
    for (x = 1; x <= str1_len; x++) {
        matrix[x][0] = x;
    }
    for (y = 1; y <= str2_len; y++) {
        matrix[0][y] = y;
    }

    // add code here

    for (int i = 0; i < str1_len + 1; i++) free(matrix[i]);
    free(matrix);

    return result;
}
