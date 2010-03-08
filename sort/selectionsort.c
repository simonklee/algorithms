#include "utils.h"

// Selection sort. O(N^2) comparisons and O(N-1) swaps. Overall effiency is
// O(N^2). So this is still very slow.
void SelectionSort(int *base, int n) {
    int i, j;
    int *low;
    for (i = 0; i < (n - 1); i++) {
        low = &base[i];
        for (j = (i + 1); j < n; j++) {
            if (*low > base[j]) // compare value of lowest with j
                low = &base[j]; // set value address of j to
        }
        SwapInt(&base[i], low);
    }
}
