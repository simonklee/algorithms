#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <citrus.h>
#include "linearsearch.h"
#include "binarysearch.h"

#define MAX 50
#define VERBOSE 0

static void testLinearSearch(Suite *suite);
static void testBinarySearch(Suite *suite);

int main(int argc, char *argv[]) {
	Suite *suite;
	
	// allocate memory.
	suite = malloc(sizeof (Suite *));
	memset(suite, 0, sizeof *suite);
	
	// run tests.
	testLinearSearch(suite);
	testBinarySearch(suite);
	
	// view summary.
	Summary(suite);
	
	// clean end.
	free(suite);
	return 0;
}

static void testBinarySearch(Suite *suite) {
    int key, n, i;
   	int arr[MAX], arrtmp[MAX];
   	
   	// fill arrays
   	n = (MAX - 20);
    for (i = 0; i < n; i++) {
        arr[i] = i * 2;
        arrtmp[i] = i * 2;        
    }
   	
    // test integer division.
    Equals(suite, (11 / 2), 5); 
    
    // test binary search.
    key = 4;
    Assert(suite, BinarySearch(&key, arr, n) == 2);
    
    // test non-existing key.
    key = 3;
    Assert(suite, BinarySearch(&key, arr, n) == -1);
    
    // test recursive binary search search.
    key = 10;
    Assert(suite, BinarySearch2(&key, arr, 0, n) == 5);
  	#if VERBOSE
    for (i = 0; i < n; i++) {
        key = i * 2;
        printf("arr[%d]: %d\n", BinarySearch(&key, arr, n), arr[i]);
    }
    printf("\n");
    #endif
}

static void testLinearSearch(Suite *suite) {
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
		
	// test LinearSearch.
	key = 6;
	
	// do find.
	kindex = LinearSearch(&key, arr, len);
	
	// check results.
	Equals(suite, kindex, 2);
	
	#if VERBOSE
	printf("Key: %d, Key Index was: %d\n", key, kindex);
	#endif // VERBOSE
			
	// test LinearDelete.
	// set temp array with expected result of outcome after delete.
	arrtmp[0] = 4;
	arrtmp[1] = 5;	
	arrtmp[2] = 7;	
	arrtmp[3] = 8;	
	
	// do delete.
	LinearDelete(&key, arr, &len);
	
	// check results.
	EqualsA(suite, arr, arrtmp, len, sizeof(int), IntComp);
	
	#if VERBOSE
	printf("LinearDelete test\n");
	for (i = 0; i < len; i++) {
		printf("arr[%d] %d, arrtmp[%d]: %d\n", i, arr[i], i, arrtmp[i]);
	}
	printf("\n");
	#endif // VERBOSE
	
	// Test LinearInsert
	key = 10;
	
	// manually set arrtemp with expected outcome after insert.
	arrtmp[4] = 10;
	
	// do insert.
	LinearInsert(&key, arr, &len, MAX);
	
	// check results.
	EqualsA(suite, arr, arrtmp, len, sizeof(int), IntComp);
	
	#if VERBOSE	
	printf("LinearInsert test\n");
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
	LinearInsertS(&key, arr, &len, MAX);
	
	key = 6;
	LinearInsertS(&key, arr, &len, MAX);
	
	key = 15;
	LinearInsertS(&key, arr, &len, MAX);	
	
	EqualsA(suite, arr, arrtmp, len, sizeof(int), IntComp);
	Equals(suite, len, 8);
	
	#if VERBOSE	
	printf("LinearInsertS test\n");
	for (i = 0; i < len; i++) {
		printf("arr[%d] %d, arrtmp[%d]: %d\n", i, arr[i], i, arrtmp[i]);
	}
	printf("array len: %d\n", len);	
	printf("\n");
	#endif // VERBOSE	
	
    // array sorted find.
	key = 6;
	
	// do find.
	kindex = LinearSearchS(&key, arr, len);
	
	// check results.
	Equals(suite, kindex, 3);
	
	#if VERBOSE
	printf("Key: %d, Key Index was: %d\n\n", key, kindex);
	#endif // VERBOSE	
}
