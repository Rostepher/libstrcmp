#ifndef STRCMP_H
#define STRCMP_H

// distance metrics
int damerau_levenshtein(const char *, const char *);
int hamming(const char *, const char *);
double jaro(const char *, const char *);
double jaro_winkler(const char *, const char *);
unsigned levenshtein(const char *, const char *);
unsigned optimal_string_alignment(const char *, const char *);
double sift3(const char *, const char *, unsigned);
double sift3B(const char *, const char *, unsigned, double);

// phonetics
char *soundex(const char *);
char *refined_soundex(const char *);

#endif STRCMP_H

