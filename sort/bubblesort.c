#include "utils.h"

// O(N^2) efficiency and substantional slower then Selections Sort due to less
// swapping.
void BubbleSort(int *base, int n) {
    int i, j;
    for (i = (n - 1); i > 1; i--) {
        for (j = 0; j < i; j++) {
            if (base[j] > base[j + 1]) {
                // int tmp = base[j];
                // base[j] = base[j + 1];
                // base[j + 1] = tmp;
                SwapInt(&base[j], &base[j + 1]);
            }
        }
    }
}

// OddEven sort is a variant of Bubblesort.
void OddEvenSort(int *base, int n) {
    int j, i;
    for (i = 0; i < ((n + 1)/2); i++) {
        for (j = 0; j < (n-1); j += 2) {
            if (base[j] > base[j + 1])
                SwapInt(&base[j], &base[j+1]);
        }
        for (j = 1; j < (n-1); j += 2) {
            if (base[j] > base[j+1])
                SwapInt(&base[j], &base[j+1]);
        }
    }
}
