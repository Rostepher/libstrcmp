#libstrcmp

libstrcmp is a library dedicated to fast C implementations of various string
distance metrics and phonetic metrics. The metrics provided in libstrcmp are
useful in fuzzy-string matching as well as natural-language processing.

##Algorithms
Algorithms that are currently implemented or plan to be
implemented are split into two sections, _String Distance Metics_ and
_Phonetic Algorithms_:

###String Distance Metrics
1. [Hamming Distance](https://en.wikipedia.org/wiki/Hamming_distance)
2. [Levenshtein Distance](https://en.wikipedia.org/wiki/Levenshtein_distance)
3. [Damerau-Levenshtein Distance](https://en.wikipedia.org/wiki/Damerau-Levenshtein_distance)
4. [Jaro Distance](https://en.wikipedia.org/wiki/Jaro-Winkler_distance)
5. [Jaro-Winkler Distance](https://en.wikipedia.org/wiki/Jaro-Winkler_distance)
6. [Optimal String Alignment Distance](https://en.wikipedia.org/wiki/Damerau-Levenshtein_distance)
7. [Sift3 and Sift3B Distance](http://siderite.blogspot.com/2007/04/super-fast-and-accurate-string-distance.html)

###Phonetic Algorithms
1. [Soundex](https://en.wikipedia.org/wiki/Soundex)
2. [Refined Soundex](http://ntz-develop.blogspot.com/2011/03/phonetic-algorithms.html)
3. [Metaphone](https://en.wikipedia.org/wiki/Metaphone)
4. [Double Metaphone](https://en.wikipedia.org/wiki/Metaphone#Double_Metaphone)

libstrcmp is licensed under the MIT License and is free to use under the terms
specified in LICENSE.md
