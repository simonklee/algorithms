#include "utils.h"

// O(N^2) efficiency and substantional slower then Selections Sort, actually.
void BubbleSort(int *base, int n) {
    int i, j;
    for (i = (n - 1); i > 1; i--) {
        for (j = 0; j < i; j++) {
            if (base[j] > base[j + 1]) {
                // int tmp = base[j];
                // base[j] = base[j + 1];
                // base[j + 1] = tmp;
                swap(&base[j], &base[j + 1]); 
            }
        }
    }
}

