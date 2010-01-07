// Linear Search is nothing else then looping an array, looking for a match.
// This is created mostly as a comparison for bsearch.
// - Simon Zimmermann.

#include <stdio.h>
#include <assert.h>
#include "linearsearch.h"

static void shiftleft(int *base, int n, int l);
static void shiftright(int *base, int n, int l);

// linear search of array.
int lfind(int *key, int *base, int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (base[i] == *key) 
			return i;
	}
	return -1;
}

// insertion of unsorted array, insert at the end. O(1)
void linsert(int *key, int *base, int *n, int max) {
	// check array boundary.
	if (*n < max) {
		base[*n] = *key;	// add new key to the end of array.
		*n += 1;			// increase boundery of array.
	}
}

// delete and fill the gap. O(N)
void ldelete(int *key, int *base, int *n) {
	int i = lfind(key, base, *n);
	*n -= 1;
	// shift to the left.
	for (; i < *n; i++) {
		base[i] = base[i + 1];
	}
}

// linear sorted array search. Stop looking if a larger number is found. O(N/2)
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

// insertion of sorted array, insert in correct location. O(N)
void lsortinsert(int *key, int *base, int *n, int max) {
	int i, j;
	
	// check array boundary.
	if (*n < max) {
	    // find insertion spot in the sorted array.
        for (i = 0; i < *n; i++) {
            // if key is less then base we know that i is the insertion point.
            if (*key < base[i]) { 
                break;
            }
        }
        // Shift array to the right routine.
        for (j = *n; j > i; j--) {
            base[j] = base[j-1]; // shift array to the right.
        }
        // Set the new key.
        base[i] = *key;
        *n += 1;
	}
}

// Linear move function.
static void shiftleft(int *base, int n, int l) {
    // write code
}

// Linear move function.
static void shiftright(int *base, int n, int l) {
    // write code
}

