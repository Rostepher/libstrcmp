#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char encode_char(const char input)
{
    char c = tolower(input);

    // chars to replace where the index + 1 is the value
    char *values[] = {"bfpv", "cgjkqsxz", "dt", "l", "mn", "r"};

    // loop through each value char[] and check if c is present
    for (int i = 0; i < 6; i++)
        // if c is in the char[] value[i] return the proper char of its index + 1
        if (strchr(values[i], c) != NULL) return '0' + (i + 1);

    // otherwise return '0'
    return '0';
}

char *soundex(const char *str)
{
    // initialize variables
    char *code = malloc(5 * sizeof(char));
    char *encoded_str = malloc(strlen(str) * sizeof(char));

    // set the first value of the code to the uppercase of the first char in str
    code[0] = toupper(str[0]);

    // the number of digits in the code[] (max 4), acts as an index
    int digits = 1;

    // encode all the characters in the given string
    for (int i = 0; i < strlen(str); i++)
        encoded_str[i] = encode_char(str[i]);

    // loop through and add all viable encoded chars to the code
    for (int i = 1; i < strlen(encoded_str) && digits < 4; i++) {
        if (encoded_str[i] != encoded_str[i-1] && encoded_str[i] != '0') {
            // if numbers separated by an 'h' or 'w' are the same, skip them
            if (i > 1 && encoded_str[i] == encoded_str[i-2] && strchr("hw", str[i-1]))
                continue;
            // otherwise add the digits to the code and increment the digit count
            code[digits++] = encoded_str[i];
        }
        // printf("code = %s\n", code);
    }

    // pad the end of the code with 0s if the code is too short
    while (digits < 4)
        code[digits++] = '0';

    // free the heap of the encoded string and return the pointer to the code
    free(encoded_str);
    return code;
}
