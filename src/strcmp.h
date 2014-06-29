#ifndef STRCMP_H
#define STRCMP_H

// phonetics
char *soundex(const char *);

// distance metrics
double jaro(const char *, const char *);
double jaro_winkler(const char *, const char *);
unsigned levenshtein(const char *, const char *);
int damerau_levenshtein(const char *, const char *);
int hamming(const char *, const char *);

#endif STRCMP_H
