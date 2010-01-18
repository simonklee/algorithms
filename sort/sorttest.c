#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bubblesort.h"
#include "selectionsort.h"
#include "utils.h"

#define VERBOSE 0
#define N 10000

// Function to test sorting int arrays.
static void testSort(const char *name, void (sort)(int *base, int n));

int main(int argc, char **argv) {
 
    // run tests.
    testSort("Bubble Sort", BubbleSort);
    testSort("Selection Sort", SelectionSort);

    return 0;
}

// Function to test sorting int arrays.
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
