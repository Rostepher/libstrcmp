#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE    1
#define FALSE   0

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define equal(a, b) (tolower(a) == tolower(b))
#define not_equal(a, b) (tolower(a) != tolower(b))

double jaro(const char *str1, const char *str2) {
    // length of the strings, stops the repeated use of strlen
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);

    // if both strings are empty return 1
    // if only one of the strings is empty return 0
    if (str1_len == 0) return str2_len == 0 ? 1.0 : 0.0;

    // max distance between two chars to be considered matching
    // floor() is ommitted due to integer division rules
    int match_distance = (int) max(str1_len, str2_len)/2 - 1;

    // arrays of bools that signify if that char in the matcing string has a match
    int *str1_matches = calloc(str1_len, sizeof(int));
    int *str2_matches = calloc(str2_len, sizeof(int));

    // number of matches and transpositions
    double matches = 0.0;
    double transpositions = 0.0;

    // find the matches
    for (int i = 0; i < str1_len; i++) {
        // start and end take into account the match distance
        int start = max(0, i - match_distance);
        int end = min(i + match_distance + 1, str2_len);

        // add comments...
        for (int k = start; k < end; k++) {
            // if str2 already has a match continue
            if (str2_matches[k]) continue;
            // if str1 and str2 are not
            if (not_equal(str1[i], str2[k])) continue;
            // otherwise assume there is a match
            str1_matches[i] = TRUE;
            str2_matches[k] = TRUE;
            matches++;
            break;
        }
    }

    // if there are no matches return 0
    if (matches == 0) {
        free(str1_matches);
        free(str2_matches);
        return 0.0;
    }

    // count transpositions
    int k = 0;
    for (int i = 0; i < str1_len; i++) {
        // if there are no matches in str1 continue
        if (!str1_matches[i]) continue;
        // while there is no match in str2 increment k
        while (!str2_matches[k]) k++;
        // increment transpositions
        if (not_equal(str1[i], str2[k])) transpositions++;
        k++;
    }

    // divide the number of transpositions by two as per the algorithm specs
    // this division is valid because the counted transpositions include both
    // instances of the transposed characters.
    transpositions /= 2.0;

    // free dat allocated memory !VERY IMPORTANT!
    free(str1_matches);
    free(str2_matches);

    // return the jaro distance
    return ((matches / str1_len) +
        (matches / str2_len) +
        ((matches - transpositions) / matches)) / 3.0;
}

double jaro_winkler(const char *str1, const char *str2) {
    // compute the jaro distance
    double dist = jaro(str1, str2);

    // finds the number of common terms in the first 3 strings, max 3.
    int prefix_length = 0;
    if (strlen(str1) != 0 && strlen(str2) != 0)
        while (prefix_length < 3 && equal(*str1++, *str2++)) prefix_length++;

    // 0.1 is the default scaling factor
    return dist + prefix_length * 0.1 * (1 - dist);
}