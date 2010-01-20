#ifndef __BUBBLESORT_H
#define __BUBBLESORT_H

// O(N^2) efficiency and substantional slower then Selections Sort due to less
// swapping.
void BubbleSort(int *base, int n); 

// OddEven sort is a variant of Bubblesort.
void OddEvenSort(int *base, int n);
#endif
