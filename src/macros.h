#ifndef STRCMP_MACROS_H
#define STRCMP_MACROS_H

#ifdef STRCMP_CASE_INSENSATIVE
# include <ctype.h>
# define EQ(a, b) (tolower(a) == tolower(b))
#else
# define EQ(a, b) ((a) == (b))
#endif  // STRCMP_CASE_INSENSATIVE

#define NOT_EQ(a, b) !EQ(a, b)

#define MIN(a, b) ((a) < (b)) ? (a) : (b)
#define MIN3(a, b, c) MIN(MIN(a, b), c)
#define MIN4(a, b, c, d) MIN(MIN(a, b), MIN(c, d))

#define MAX(a, b) ((a) > (b)) ? (a) : (b)
#define MAX3(a, b, c) MAX(MAX(a, b), c)
#define MAX4(a, b, c, d) MAX(MAX(a, b), MAX(b, c))

#endif // STRCMP_MACROS_H
