#include <stdio.h>

static void shiftLeft(int *base, int n, int l);
static void shiftRight(int *base, int n, int l);

// dichotomic search algorithm with 0(log n) effiency
int BinarySearch(int *key, int *base, int n) {
    int min = 0, max = n, mid;
    
    while (min <= max) {
        mid = (min + max) / 2;
        if (base[mid] < *key)
            min = mid + 1;
        else if (base[mid] > *key)
            max = mid - 1;
        //else if (base[mid] == *key) 
        // if not bigger or not smaller, then === key
        else 
            return mid;            
    }
    return -1;
} 

// recursive solution.
// see: http://en.wikipedia.org/wiki/Binary_search_algorithm#Recursive
int BinarySearch2(int *key, int *base, int min, int max) {
    if (max < min)
        return -1;
    int mid = (min + max)  / 2;
    if (base[mid] > *key)
        return BinarySearch2(key, base, min, mid - 1);
    else if (base[mid] < *key)
        return BinarySearch2(key, base, mid + 1, max);
    else 
        return mid;            
}
void BinaryDelete(int *key, int *base, int *n) {}
void BinaryInsert(int *key, int *base, int *n, int max) {}


