#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarysearch-g.h"

// compare functions.
int IntegerCompare(const void *a, const void *b) {
    int *aptr = (int *)a;
    int *bptr = (int *)b;
    return *aptr - *bptr; 
}

int StringCompare(const void *a, const void *b) {
    char *aptr = *(char **)a;
    char *bptr = *(char **)b;
    return strcmp(aptr, bptr);
}

// a more generic approach to Binary Search.
void *BinarySearchG(const void *key, const void *base,
                     size_t nmemb, size_t size,
                     int (*compar)(const void *, const void *)) {
    int min = 0, mid, max;
    max = (int) nmemb;

    while (min <= max) {
        mid = (min + max) / 2;
        if (compar(base + mid * size, key) < 0)
            min = mid + 1;
        else if (compar(base + mid * size, key) > 0)
            max = mid - 1;
        else 
            return (void *)base + mid * size; // return address of key.
    } 
    return NULL;
}
