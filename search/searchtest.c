#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <citrus.h>
#include <sys/types.h>
#include "linearsearch.h"
#include "binarysearch.h"
#include "binarysearch-g.h"

#define MAX 50
#define VERBOSE 0

static void testLinearSearch(Suite *suite);
static void testBinarySearch(Suite *suite);
static void testBinarySearchG(Suite *suite); 

int main(int argc, char *argv[]) {
    Suite *suite;

    // allocate memory.
    suite = malloc(sizeof (Suite *));
    memset(suite, 0, sizeof *suite);

    //printf("%d\n", SSIZE_MAX);
    #if VERBOSE
    printf("Verbose is set to true and will Print messages during test. \n");
    #endif

    // run tests.
    testLinearSearch(suite);
    testBinarySearch(suite);
    testBinarySearchG(suite);

    // view summary.
    Summary(suite);

    // clean end.
    free(suite);
    return 0;
}

static void testBinarySearchG(Suite *suite) {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  
    char *arr2[] = {"ABC", "DEF", "GHI", "JKL", "MNS", "OPQ", "RST", "UVW", "XYZ"};
    char *nothere = "Not In Array";
    
    #if VERBOSE
    printf("Testing BinarySearchG\n\n");
    #endif
    
    // The Important tests. Does it work?
    void *result = BinarySearchG(&arr2[2], arr2, 9, sizeof(char *), StringCompare);
    void *result2 = BinarySearchG(&arr[2], arr, 10, sizeof(int), IntegerCompare);
    void *result3 = BinarySearchG(&nothere, arr2, 9, sizeof(char *), StringCompare);
    
    Assert(suite, *(char **)result == "GHI");
    Assert(suite, *(int *)result2 == 2);
    Assert(suite, result3 == NULL);

    #if VERBOSE
    printf("Char * Array results:\n");
    printf("expected: %p,\t%s\n", &arr2[2], arr2[2]);    
    printf("result:   %p,\t%s\n\n", result, *(char **)result);

    printf("Int Array results:\n");
    printf("expected: %p,\t%d\n", &arr[2], arr[2]);    
    printf("result:   %p,\t%d\n\n", result2, *(int *)result2);
    #endif   
}

static void testBinarySearch(Suite *suite) {
    int key, n, i, tmp;
   	int arr[MAX], arrtmp[MAX];
   	
   	// fill arrays
   	n = (MAX - 30);
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
  	printf("Using Binary Search to find each item in the Array. \n");
    for (i = 0; i < n; i++) {
        key = i * 2;
        printf("arr[%d]: %d\n", BinarySearch(&key, arr, n), arr[i]);
    }
    printf("\n");
    #endif
    
    // test delete.
    key = 30;
    tmp = n - 1; // expected n to decrease after BinaryDelete
    Assert(suite, BinaryDelete(&key, arr, &n) == 15);
    Equals(suite, n, tmp);
    Assert(suite, BinaryDelete(&key, arr, &n) == -1);
    
    // test insert, check if duplication is prohibited.
    tmp = n;
    for (i = 0; i < n; i++) {
        #if VERBOSE
        printf("arr[%d]: %d\n", i, arr[i]);
        #endif
        key = arr[i];
        if (BinaryInsert(&key, arr, &n, MAX) > -1) {
            #if VERBOSE
            printf("Insertion failed. Allowed to insert duplicate. \n");
            #endif
        }
    }
    Equals(suite, tmp, n);
    
    // test insert, do insert.
    tmp = n + 3;

    key = 1;
    Equals(suite, BinaryInsert(&key, arr, &n, MAX), 1);    

    key = 19;
    Equals(suite, BinaryInsert(&key, arr, &n, MAX), 11);

    key = 50;
    Equals(suite, BinaryInsert(&key, arr, &n, MAX), 21);

    Assert(suite, tmp == n);

    #if VERBOSE
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
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
    printf("\nKey: %d, Key Index was: %d\n", key, kindex);
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
