// This is the std c header for BinarySearch found through man bsearch.
// I'll do an implementation using this header.
/*void *bsearch(const void *key, const void *base,
                     size_t nmemb, size_t size,
                     int (*compar)(const void *, const void *));*/

#ifndef __BINARYSEARCH_H
#define __BINARYSEARCH_H

// binary search, delete and insert on int array.
int BinarySearch(int *key, int *base, int n);
int BinarySearch2(int *key, int *base, int min, int max);
void BinaryDelete(int *key, int *base, int *n);
void BinaryInsert(int *key, int *base, int *n, int max);

#endif
