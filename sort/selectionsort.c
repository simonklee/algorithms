#include "utils.h" // includes swap function.

// Selection sort. O(N^2) comparisons and O(N-1) swaps. Overall effiency is
// O(N^2). So this is still very slow. 
void SelectionSort(int *base, int n) {
    int i, j;
    int *low;
    for (i = 0; i < n; i++) {
        low = &base[i];
        for (j = i; j < n; j++) {
            if (*low > base[j])
                low = &base[j];
        }
        swap(&base[i], low);
    }
} 
