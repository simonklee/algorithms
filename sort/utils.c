#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include "utils.h"

// Swap two int vars.
int swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Generic Swap function.
void SwapG(void **a, void **b) {
    void *tmp = *a;
    *a = *b;
    *b = tmp;
}

// Generic compare functions.
int IntegerCompare(const void *a, const void *b) {
    int *aptr = (int *)a;
    int *bptr = (int *)b;
    return *aptr - *bptr; 
}

int StringCompare(const void *a, const void *b) {
    char *aptr = *(char **)a;
    char *bptr = *(char **)b;
    return strcmp(aptr, bptr);
}

// Randomize int array with n numbers
void randomize(int *base, int n) {
    int i;
    for (i = 0; i < n; i++) {
        base[i] = (rand() / 10000000);
    } 
}

// Print integer arrays in a linear line. add breakline at last item.
void printIntArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i == (n-1))
            printf("\n\n");
        else
            printf(", ");        
    }    
}


// Timer, like a stop watch. Click it once, it starts. Click it a second time,
// it stops at a given time. This time is then returned. The first time 0.0 is
// returned.
double timer() {
    // just a logic button to see what to do based on if we have clicked or not.
    static int t;
    // clock_t is used to store the elapsed CPU time by a process
    static clock_t start;
    clock_t stop;

    if (t == 0) {
        t = 1;
        start = clock();
    } else {
        t = 0;
        stop = clock();
        return ((double) (stop - start)) / CLOCKS_PER_SEC;
    }
    return 0.0;
}

// Just a function to print time in min and seconds
void printTime(double time) {
    int min = 0;
    while(time >= 60) {
        time -= 60;
        min++;        
    }
    printf("Elapsed time %dm%4.3fs\n", min, time); 
}
