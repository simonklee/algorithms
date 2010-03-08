#ifndef __UTILS_H
#define __UTILS_H

#include <sys/types.h>

// Swap values, addresses etc.
int SwapInt(int *a, int *b);
void SwapAddress(void **a, void **b);
void SwapValue(void *aAddr, void *bAddr, int elemSize);

// Generic compare functions.
int IntegerCompare(const void *a, const void *b);
int StringCompare(const void *a, const void *b);

// Initialize a int array with N random numbers.
void Randomize(int *base, int n);

// Delete duplicates in an ordered array.
void DelDups(int *base, int *n);

// Print a int array with N numbers.
void PrintIntArray(int *arr, int n);

// Timer, like a stop watch. Click it once, it starts. Click it a second time,
// it stops at a given time. This time is then returned. The first time 0.0 is
// returned.
double Timer();

// Just a function to print time in min and seconds
void PrintTime(double time);
#endif
