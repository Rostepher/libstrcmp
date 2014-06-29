#include <stdlib.h>
#include <string.h>

#include "macros.h"


/**
 *
 */
int optimal_string_alignment(const char *str1, const char *str2)
{
    // initialize size and counter variables
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);
    int x, y, cost, result;

    // remove common substring
    while (str1_len > 0 && str2_len > 0 && EQ(str1[0], str2[0]))
        str1++, str2++, str1_len--, str2_len--;

    // handle cases where one string is empty
    if (!str1_len) return str2_len;
    if (!str2_len) return str2_len;

    // initialize matrix to hold distance values
    int **matrix = malloc((str1_len + 1) * sizeof(int*));
    for (int i = 0; i <= str1_len; i++)
        matrix[i] = calloc((str2_len + 1), sizeof(int));

    // set all the starting values
    matrix[0][0] = 0;
    for (x = 1; x <= str1_len; x++)
        matrix[x][0] = x;
    for (y = 1; y <= str2_len; y++)
        matrix[0][y] = y;

    // itterate through and fill in the matrix
    for (x = 1; x <= str1_len; x++) {
        for (y = 1; y <= str2_len; y++) {
            cost = EQ(str1[x-1], str2[y-1]) ? 0 : 1;
            matrix[x][y] = MIN3(matrix[x-1][y] + 1,
                                matrix[x][y-1] + 1,
                                matrix[x-1][y-1] + cost);

            // handle transpositions
            if (x > 1 && y > 1 && EQ(str1[x], str2[y-1]) && EQ(str1[x-1], str2[y])) {
                matrix[x][y] = MIN(matrix[x][y], matrix[x-2][y-2] + cost);
            }
        }
    }

    result = matrix[str1_len][str2_len];

    // free dat memory!
    for (int i = 0; i < str1_len + 1; i++) free(matrix[i]);
    free(matrix);

    // return the result
    return result;
}
