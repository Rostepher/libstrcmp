#include <stdio.h>
#include <string.h>

// a pointer which will allow an arbitray type to be input into the hashmap
typedef void *any_t;

typedef struct hashmap {
    any_t *map;
} hash;