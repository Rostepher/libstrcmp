#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define equal(a, b) (tolower(a) == tolower(b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define min3(a, b, c) ((a) < (b) ?\
        ((a) < (c) ? (a) : (c)) :\
        ((b) < (c) ? (b) : (c)))

int levenshtien(const char *str1, const char *str2) {
    // initialize size variables
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);
    int x, y, last_diag, current, cost;

    // remove common substring
    while (str1_len > 0 && str2_len && equal(str1[0], str2[0]))
        str1++, str2++, str1_len--, str2_len--;

    // handle cases where one string is empty
    if (!str1_len) return str2_len;
    if (!str2_len) return str1_len;

    // initialize array to hold values
    int *column = calloc(str1_len + 1,  sizeof(int));
    for (int y = 1; y <= str1_len; y++) column[y] = y;

    // itterate through the imagined rows of arrays (hence the +1)
    for (int x = 1; x <= str2_len + 1; x++) {
        column[0] = x; // set the first slot to x
        last_diag = x - 1; // remember the last first slot

        // itterate throught each member of the column
        for (int y = 1; y <= str1_len; y++) {
            current = column[y]; // remembers the diagonal before overwritten
            cost = equal(str1[y-1], str2[x-1]) ? 0 : 1;
            column[y] = min3(column[y] + 1, column[y-1] + 1, last_diag + cost);
            last_diag = current; // remember the new last diagonal
        }
    }

    free(column);

    // return final value
    return last_diag;
}
