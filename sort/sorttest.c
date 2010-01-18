#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <citrus.h>
#include "bubblesort.h"

static void testBubbleSort(Suite *suite);
static void printIntArray(int *arr, int n);

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
    //int n = 10;
    int arr[N] = {73, 19, 29, 20, 57, 1, 8, 99, 4, 28};
    int i;
    
    printf("Unsorted Array\n");    
    printIntArray(arr, N);
    
    BubbleSort(arr, N);
    printf("Sorted Array\n");
    printIntArray(arr, N);
}

static void printIntArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i == (n-1))
            printf("\n");
        else
            printf(", ");        
    }    
}
