
// Linear Search is nothing else then looping an array, looking for a match.
// This is created mostly as a comparison for bsearch.
// - Simon Zimmermann.

#include <stdio.h>
#include <assert.h>
#include "linearsearch.h"

// linear search of array.
int lfind(int *key, int *base, int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (base[i] == *key) 
			return i;
	}
	return -1;
}

// linear sorted array search. Stop looking if a larger number is found.
int lsortfind(int *key, int *base, int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (base[i] == *key) 
			return i;
		else if (base[i] > *key)
			return -1;
	}	
	return -1;	
}

// insertion of unsorted array, insert at the end.
void linsert(int *key, int *base, int *n, int max) {
	// check array boundary.
	if (*n < max) {
		base[*n] = *key;	// add new key to the end of array.
		*n += 1;			// increase boundery of array.
	}
}

// insertion of sorted array, insert in correct location.
void lsortinsert(int *key, int *base, int *n, int max) {
	int i; // = lsortfind(key, base, *n);
	// check array boundary.
	if (*n < max) {
		
		
	}
}

// delete and fill the gap.
void ldelete(int *key, int *base, int *n) {
	int i = lfind(key, base, *n);
	*n -= 1;
	for (; i < *n; i++) {
		base[i] = base[i + 1];
	}
}
