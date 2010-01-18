#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// Swap two int vars.
int swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
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
