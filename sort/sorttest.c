#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bubblesort.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include "utils.h"

#define VERBOSE 0
#define N 50000

// Function to test sorting int arrays.
static void testSort(const char *name, void (sort)(int *base, int n));
static void delDups(int *base, int *n);
static void OddEvenSort(int *base, int n);

int main(int argc, char **argv) {
 
    // run tests.
    testSort("Bubble Sort", BubbleSort);
    testSort("Selection Sort", SelectionSort);
    testSort("OddEven Sort", OddEvenSort);
    testSort("Insertion Sort", InsertionSort);

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

    int n = (int) N;
    delDups(arr, &n);
    printf("Sorted Array without duplicates\n");    
    printIntArray(arr, n);    
    #endif
    
    printTime(elapsed);
    printf("\n");

}

static void delDups(int *base, int *n) {
    int i, curr = 0;
    for (i = 1; i < *n; i++) {
        if (base[i] != base[curr])
            curr++;
            base[curr] = base[i];
    }
    *n = (curr + 1);
}


static void OddEvenSort(int *base, int n) {
    int j, i;   
    for (i = 0; i < ((n + 1)/2); i++) {
        for (j = 0; j < (n-1); j += 2) {
            if (base[j] > base[j + 1])
                swap(&base[j], &base[j+1]);
        } 
        for (j = 1; j < (n-1); j += 2) {
            if (base[j] > base[j+1])
                swap(&base[j], &base[j+1]);
        }
    }
}

void compEqual(int a, int b) {
    // nothing yet.
}
