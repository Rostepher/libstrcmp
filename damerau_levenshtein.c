#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// variable length min function
int min(int args[], int size) {
    if (size > 0) {
        int min = args[0];
        for (int i = 1; i < size; i++)
            if (args[i] < min) min = args[i];
        return min;
    } else return INT_MIN;
}

int damerau_levenshtein(const char *str1, const char *str2) {
    // initialize size and counter variables
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);

    // remove common substring
    // while (str1_len > 0 && str2_len > 0 && equal(str1[0], str2[0]))
    //     str1++, str2++, str1_len--, str2_len--;

    // handle cases where one string is empty
    if (!str1_len) return str2_len;
    if (!str2_len) return str2_len;

    // initialize matrix to hold distance values
    // initialize matrix to hold distance values
    printf("initializing matrix\n");
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

    // free dat memory!
    for (int i = 0; i < str1_len + 1; i++) free(matrix[i]);
    free(matrix);

    return result;
}