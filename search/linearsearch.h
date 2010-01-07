#ifndef __LINEARSEARCH_H
#define __LINEARSEARCH_H

// unsorted find and insert.
int lfind(int *key, int *base, int n); 
void linsert(int *key, int *base, int *n, int max);

// works for both sorted and unsorted array.
void ldelete(int *key, int *base, int *n);

// sorted linear insert and find.
int lsortfind(int *key, int *base, int n); 
void lsortinsert(int *key, int *base, int *n, int max);

#endif
