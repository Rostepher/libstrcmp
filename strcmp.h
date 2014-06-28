#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// phonetics
char *soundex(const char *);

// distances
double jaro(char *, char *);
double jaro_winkler(char *, char *);
int hamming(const char *, const char *);
int levenshtein(const char *, const char *);
int damerau_levenshtien(const char *, const char *);