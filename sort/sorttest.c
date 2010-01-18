#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <citrus.h>
#include "bubblesort.h"
#include "selectionsort.h"
#include "utils.h"

#define VERBOSE 0
#define N 10000

static void testSort(const char *name, void (sort)(int *base, int n));

int main(int argc, char **argv) {
    Suite *suite;

    // allocate memory.
    suite = malloc(sizeof (Suite *));
    memset(suite, 0, sizeof *suite);
    
    // run tests.
    testSort("Bubble Sort", BubbleSort);
    testSort("Selection Sort", SelectionSort);
    
    // view summary.
    Summary(suite);

    // clean end.
    free(suite);
    return 0;
}

// function to test sorting int arrays.
static void testSort(const char *name, void (sort)(int *base, int n)) {
    int arr[N];
    double elapsed;
    randomize(arr, N);
    
    printf("Test for %s:\n", name);
    
    #if VERBOSE
    printf("Unsorted Array\n");    
    printIntArray(arr, N);
    #endif    
    
    timer(); // Start timer.
    sort(arr, N);
    elapsed = timer(); // Stop timer.
    
    #if VERBOSE
    printf("Sorted Array\n");    
    printIntArray(arr, N);
    #endif
    
    printTime(elapsed);
    printf("\n");
}
