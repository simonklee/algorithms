#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linearsearch.h"
#include "../../c/citrus/citrus.h"

#define MAX 10
static void testlsearch(Suit *suit);

int main(int argc, char *argv[]) {
	Suit *suit;
	
	// allocate memory.
	suit = malloc(sizeof (Suit *));
	memset(suit, 0, sizeof *suit);
	
	// run tests.
	testlsearch(suit);
	
	// view summary.
	Summary(suit);
	
	// clean end.
	free(suit);
	return 0;
}

static void testlsearch(Suit *suit) {
	int key, kindex, n, max, len, i;
	int arr[MAX], arrtmp[MAX];

	// fill array.
	arr[0] = 4;
	arr[1] = 5;
	arr[2] = 6;		
	arr[3] = 7;	
	arr[4] = 8;	
    
    //  set current lenght of array.
	len = 5;
	
	
	// test lfind.
	key = 6;
	
	// do find.
	kindex = lfind(&key, arr, len);
	
	// check results.
	Equals(suit, kindex, 2);
	
	#if VERBOSE
	printf("Key: %d, Key Index was: %d\n", key, kindex);
	#endif // VERBOSE
	
		
	// test ldelete.
	// set temp array with expected result of outcome after delete.
	arrtmp[0] = 4;
	arrtmp[1] = 5;	
	arrtmp[2] = 7;	
	arrtmp[3] = 8;	
	
	// do delete.
	ldelete(&key, arr, &len);
	
	// check results.
	EqualsA(suit, arr, arrtmp, len, sizeof(int), IntComp);
	
	#if VERBOSE
	for (i = 0; i < len; i++) {
		printf("arr[%d] %d, arrtmp[%d]: %d\n", i, arr[i], i, arrtmp[i]);
	}
	#endif // VERBOSE
	
	// Test linsert
	key = 10;
	
	// manually set arrtemp with expected outcome after insert.
	arrtmp[4] = 10;
	
	// do insert.
	linsert(&key, arr, &len, MAX);
	
	// check results.
	EqualsA(suit, arr, arrtmp, len, sizeof(int), IntComp);
	
	#if VERBOSE	
	for (i = 0; i < len; i++) {
		printf("arr[%d] %d, arrtmp[%d]: %d\n", i, arr[i], i, arrtmp[i]);
	}	
	#endif // VERBOSE
}
