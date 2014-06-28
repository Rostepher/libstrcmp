#include "strcmp.h"

void test_hamming() {}
void test_jaro() {}
void test_jaro_winkler() {}
void test_levenshtein() {}
void test_damerau_levenshtein() {}
void test_optimal_string_alignment() {}

void test_soundex() {
    const char *sdx, *tests[][2] = {
        {"Soundex",     "S532"},
        {"Example",     "E251"},
        {"Sownteks",    "S532"},
        {"Ekzampul",    "E251"},
        {"Euler",       "E460"},
        {"Gauss",       "G200"},
        {"Hilbert",     "H416"},
        {"Knuth",       "K530"},
        {"Lloyd",       "L300"},
        {"Lukasiewicz", "L222"},
        {"Ellery",      "E460"},
        {"Ghosh",       "G200"},
        {"Heilbronn",   "H416"},
        {"Kant",        "K530"},
        {"Ladd",        "L300"},
        {"Lissajous",   "L222"},
        {"Wheaton",     "W350"},
        {"Burroughs",   "B620"},
        {"Burrows",     "B620"},
        {"O'Hara",      "O600"},
        {"Washington",  "W252"},
        {"Lee",         "L000"},
        {"Gutierrez",   "G362"},
        {"Pfister",     "P236"},
        {"Jackson",     "J250"},
        {"Tymczak",     "T522"},
        {"VanDeusen",   "V532"},
        {"Ashcraft",    "A261"},
        {0, 0}
    };

    printf("Testing Soundex:\n");
    int i = 0, passed = 0;
    for (; tests[i][0]; i++) {
        sdx = soundex(tests[i][0]);
        if (!strcmp(sdx, tests[i][1])) {
            printf(".");
            passed++;
        } else {
            printf("\nError (expected '%s' : recieved '%s')", tests[i][1], sdx);
        }
    }
    printf("\npassed: %d/%d\n", passed, i);
}

int main(int argc, char *argv[]) {
    test_soundex();
    return 0;
}