#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <citrus.h>
#include "bubblesort.h"
#include "utils.h"

static void testBubbleSort(Suite *suite);

int main(int argc, char **argv) {
    Suite *suite;

    // allocate memory.
    suite = malloc(sizeof (Suite *));
    memset(suite, 0, sizeof *suite);
    
    // run tests.
    testBubbleSort(suite);
    
    // view summary.
    Summary(suite);

    // clean end.
    free(suite);
    return 0;
}

#define N 10
static void testBubbleSort(Suite *suite) {
    int arr[N];
    randomize(arr, N);
    
    printf("Unsorted Array\n");    
    printIntArray(arr, N);
    
    BubbleSort(arr, N);
    printf("Sorted Array\n");
    printIntArray(arr, N);
    
    // Bubble Sort on N 100,000 int's
    // real	1m40.271s
    // user	1m40.167s
    // sys	0m0.027s
    
    randomize(arr, N);
    printf("Unsorted Array\n");
    printIntArray(arr, N);
    
    SelectionSort(arr, N);
    printf("Sorted Array\n");
    printIntArray(arr, N);
    
    // Selection Sort on N 100,000 int's
    // real	0m31.698s
    // user	0m31.691s
    // sys	0m0.007s

}

