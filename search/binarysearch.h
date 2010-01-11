#ifndef __BINARYSEARCH_H
#define __BINARYSEARCH_H

// binary search, delete and insert on int array.
int BinarySearch(int *key, int *base, int n);
int BinarySearch2(int *key, int *base, int min, int max);
int BinaryDelete(int *key, int *base, int *n);
int BinaryInsert(int *key, int *base, int *n, int max);

#endif
