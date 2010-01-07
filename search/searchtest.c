#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <citrus.h>
#include "linearsearch.h"

#define MAX 50
#define VERBOSE 1

static void testlsearch(Suit *suit);
static void testbsearch(Suit *suit);

int main(int argc, char *argv[]) {
	Suit *suit;
	
	// allocate memory.
	suit = malloc(sizeof (Suit *));
	memset(suit, 0, sizeof *suit);
	
	// run tests.
	//testlsearch(suit);
	testbsearch(suit);
	
	// view summary.
	Summary(suit);
	
	// clean end.
	free(suit);
	return 0;
}

static void testbsearch(Suit *suit) {
    int key, n, i;
   	int arr[MAX], arrtmp[MAX];
   	
   	// fill arrays
   	n = (MAX - 20);
    for (i = 0; i < n; i++) {
        arr[i] = i * 2;
        arrtmp[i] = i * 2;        
    }
   	
    // test integer division.
    Equals(suit, (11 / 2), 5); 
    
    // test binary search.
    key = 4;
    printf("%d\n", bfind(&key, arr, n)); 
  	#if VERBOSE
    for (i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    #endif
}
static void testlsearch(Suit *suit) {
	int key, kindex, len, i;
	int arr[MAX], arrtmp[MAX];

	// fill array.
	arr[0] = 4;
	arr[1] = 5;
	arr[2] = 6;		
	arr[3] = 7;	
	arr[4] = 8;	
    
	// set current lenght of array.
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
	printf("ldelete test\n");
	for (i = 0; i < len; i++) {
		printf("arr[%d] %d, arrtmp[%d]: %d\n", i, arr[i], i, arrtmp[i]);
	}
	printf("\n");
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
	printf("linsert test\n");
	for (i = 0; i < len; i++) {
		printf("arr[%d] %d, arrtmp[%d]: %d\n", i, arr[i], i, arrtmp[i]);
	}
	printf("array len: %d\n", len);
	printf("\n");
	#endif // VERBOSE
	
	// test sorted insertion
	// set temp array with expected result of outcome after insertion.
	arrtmp[0] = 1;
	arrtmp[1] = 4;
	arrtmp[2] = 5;	
	arrtmp[3] = 6;	
	arrtmp[4] = 7;
	arrtmp[5] = 8;
	arrtmp[6] = 10;
	arrtmp[7] = 15;

	key = 1;
	lsortinsert(&key, arr, &len, MAX);
	
	key = 6;
	lsortinsert(&key, arr, &len, MAX);
	
	key = 15;
	lsortinsert(&key, arr, &len, MAX);	
	
	EqualsA(suit, arr, arrtmp, len, sizeof(int), IntComp);
	Equals(suit, len, 8);
	
	#if VERBOSE	
	printf("lsortinsert test\n");
	for (i = 0; i < len; i++) {
		printf("arr[%d] %d, arrtmp[%d]: %d\n", i, arr[i], i, arrtmp[i]);
	}
	printf("array len: %d\n", len);	
	printf("\n");
	#endif // VERBOSE	
	
    // array sorted find.
	key = 6;
	
	// do find.
	kindex = lsortfind(&key, arr, len);
	
	// check results.
	Equals(suit, kindex, 3);
	
	#if VERBOSE
	printf("Key: %d, Key Index was: %d\n\n", key, kindex);
	#endif // VERBOSE	
}
