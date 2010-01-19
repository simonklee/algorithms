#ifndef __UTILS_H
#define __UTILS_H

#include <sys/types.h>

// Swap integers
int swap(int *a, int *b);
void SwapG(void **a, void **b);

// Generic compare functions.
int IntegerCompare(const void *a, const void *b);
int StringCompare(const void *a, const void *b);

// Initialize a int array with N random numbers.
void randomize(int *base, int n);

// Print a int array with N numbers.
void printIntArray(int *arr, int n);

// Timer, like a stop watch. Click it once, it starts. Click it a second time,
// it stops at a given time. This time is then returned. The first time 0.0 is
// returned.
double timer();

// Just a function to print time in min and seconds
void printTime(double time);
#endif
