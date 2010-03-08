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
static void testUtil();

int main(int argc, char **argv) {
 
    // run tests.
    testSort("Bubble Sort", BubbleSort);
    testSort("Selection Sort", SelectionSort);
    testSort("OddEven Sort", OddEvenSort);
    testSort("Insertion Sort", InsertionSort);
    testUtil();
    
    return 0;
}

// Util test function.
static void testUtil() { 
    printf("Testing Swapping:\n");
    
    int intA = 10;
    int intB = 20;        
    printf("before: a = %d b = %d\n", intA, intB);
    SwapValue(&intA, &intB, sizeof(int));
    printf("after: a = %d b = %d\n", intA, intB);
    
    char chA = 'A';
    char chB = 'B';
    printf("before: a = %c b = %c\n", chA, chB);
    SwapValue(&chA, &chB, sizeof(char));
    printf("after: a = %c b = %c\n", chA, chB);    
    
    char *charA = "Hello";
    char *charB = "World!";    
    printf("before: %s %s\n", charA, charB);    
    SwapValue(&charA, &charB, sizeof(char *));
    printf("after: %s %s\n", charA, charB);        
    
    printf("Done testing Swapping.\n");
}

// Function to test sorting int arrays.
static void testSort(const char *name, void (sort)(int *base, int n)) {
    int arr[N];
    double elapsed;
    Randomize(arr, N);

    printf("Test for %s:\n", name);

    #if VERBOSE
    printf("Unsorted Array\n");    
    printIntArray(arr, N);
    #endif    
    
    Timer(); // Start timer.
    sort(arr, N);
    elapsed = Timer(); // Stop timer.
    
    #if VERBOSE
    printf("Sorted Array\n");    
    printIntArray(arr, N);

    int n = (int) N;
    DelDups(arr, &n);
    printf("Sorted Array without duplicates\n");    
    printIntArray(arr, n);    
    #endif
    
    PrintTime(elapsed);
    printf("\n");
}