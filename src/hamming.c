#include <stdio.h>
#include <string.h>

/**
 *  Computes and returns the hamming distance between two strings. Both strings
 *  must have the same length.
 *
 *  @param str1 first string
 *  @param str2 second string
 *
 *  @returns hamming distance or -1 if str1 and st2 did not have the same
 *      length
 */
int hamming(const char *str1, const char *str2) {
    // if the string lengths do not match return -1
    if (strlen(str1) != strlen(str2))
        return -1;

    // while the string lengths are greater than zero, add the outcome of the
    // boolean expression comparing the chars at both pointers to the distance
    // variable and then increment the pointers
    int dist = 0;
    while (strlen(str1) > 0 && strlen(str2) > 0)
        dist += (*str1++ == *str2++);

    return dist;
}
