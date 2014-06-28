#ifndef STRCMP_H
#define STRCMP_H

// phonetics
char *soundex(const char *);

// distances
double jaro(char *, char *);
double jaro_winkler(char *, char *);
int hamming(const char *, const char *);
int levenshtein(const char *, const char *);
int damerau_levenshtien(const char *, const char *);

#endif // STRCMP_H
