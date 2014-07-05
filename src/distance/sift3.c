#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "macros.h"


/**
 *  Computes and returns the fast sift3 distance between two non NULL strings.
 *  More information about the algorithm can be found here:
 *      http://siderite.blogspot.com/2007/04/super-fast-and-accurate-string-distance.html
 *
 *  @param str1 first non NULL string
 *  @param str2 second non NULL string
 *  @param max_offset maximum offset to search for lowest common substring
 *
 *  @returns sift3 distance of str1 and str2
 */
double sift3(const char *str1, const char *str2, unsigned max_offset)
{
    // strings cannot be NULL
    assert(str1 != NULL);
    assert(str2 != NULL);

    // calculate string lengths
    unsigned str1_len = strlen(str1);
    unsigned str2_len = strlen(str2);

    // if both strings are empty return 0
    // if only one of the strings is empty return str2_len
    if (str1_len == 0)
        return (double) str2_len;
    if (str2_len == 0)
        return (double) str1_len;

    unsigned lcs = 0;   // lowest common substring
    unsigned c1 = 0;    // current index/char in str1
    unsigned c2 = 0;    // current index/char in str2

    // calculate lowest common substring
    while ((c1 < str1_len) && (c2 < str2_len)) {
        if (EQ(str1[c1], str2[c2])) {
            lcs++;
        } else {
            for (unsigned i = 0; i < max_offset; i++) {
                // check if c1 + i is out of bounds
                // and if the char at c1 + i is equal to c2
                if ((c1 + i < str1_len) && (EQ(str1[c1 + i], str2[c2]))) {
                    c1 += i;
                    break;
                }

                if ((c2 + 1 < str2_len) && (EQ(str2[c2 + i], str1[c1]))) {
                    c2 += i;
                    break;
                }
            }
        }

        c1++;
        c2++;
    }

    return ((str1_len + str2_len) / 2.0 - lcs);
}

/**
 *  Computes and returns the fast sift3B distance between two non NULL strings.
 *  More information about the algorithm can be found here:
 *      http://siderite.blogspot.com/2007/04/super-fast-and-accurate-string-distance.html
 *
 *  @param str1 first string
 *  @param str2 second string
 *  @param max_offset maximum offset to search for lowest common substring
 *  @param max_dist maximum distance between str1 and str2 before the algorithm
 *      should exit prematurely, meaning the strings were too different.
 *
 *  @returns sift3B distance of str1 and str2
 */
double sift3B(const char *str1,
               const char *str2,
               unsigned max_offset,
               double max_dist)
{
    // strings cannot be NULL
    assert(str1 != NULL);
    assert(str2 != NULL);

    // calculate string lengths
    unsigned str1_len = strlen(str1);
    unsigned str2_len = strlen(str2);

    // if both strings are empty return 0
    // if only one of the strings is empty return str2_len
    if (str1_len == 0)
        return (double) str2_len;
    if (str2_len == 0)
        return (double) str1_len;

    unsigned lcs = 0;   // lowest common substring
    unsigned c1 = 0;    // current index/char in str1
    unsigned c2 = 0;    // current index/char in str2
    double temp_dist;

    // calculate lowest common substring
    while ((c1 < str1_len) && (c2 < str2_len)) {
        if (EQ(str1[c1], str2[c2])) {
            lcs++;
        } else {
            if (c1 < c2)
                c2 = c1;
            else
                c1 = c2;

            for (unsigned i = 0; i < max_offset; i++) {
                // check if c1 + i is out of bounds
                // and if the char at c1 + i is equal to c2
                if ((c1 + i < str1_len) && (EQ(str1[c1 + i], str2[c2]))) {
                    c1 += i;
                    break;
                }

                if ((c2 + 1 < str2_len) && (EQ(str2[c2 + i], str1[c1]))) {
                    c2 += i;
                    break;
                }
            }
        }

        c1++;
        c2++;

        // check if current distance is greater than max_dist
        temp_dist = (c1 + c2) / 1.5 - lcs;
        if (temp_dist >= max_dist)
            return round(temp_dist);
    }

    // main change in 3B algorithm
    return round((str1_len + str2_len) / 1.5 - lcs);
}
