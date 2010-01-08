#ifndef __LINEARSEARCH_H
#define __LINEARSEARCH_H

// unsorted find and insert.
int LinearSearch(int *key, int *base, int n); 
void LinearInsert(int *key, int *base, int *n, int max);

// works for both sorted and unsorted array.
void LinearDelete(int *key, int *base, int *n);

// sorted linear insert and find.
int LinearSearchS(int *key, int *base, int n); 
void LinearInsertS(int *key, int *base, int *n, int max);

#endif
