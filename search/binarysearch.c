#include <stdio.h>

// This is the std c header for binarysearch found through man bsearch.
// I'll do an implementation using this header.
void *bsearch(const void *key, const void *base,
                     size_t nmemb, size_t size,
                     int (*compar)(const void *, const void *));
