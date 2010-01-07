// This is the std c header for binarysearch found through man bsearch.
// I'll do an implementation using this header.
/*void *bsearch(const void *key, const void *base,
                     size_t nmemb, size_t size,
                     int (*compar)(const void *, const void *));*/

#ifndef __BINARYSEARCH_H
#define __BINARYSEARCH_H

// binary search, delete and insert on int array.
int bfind(int *key, int *base, int n); 
void bdelete(int *key, int *base, int *n);
void binsert(int *key, int *base, int *n, int max);

#endif
