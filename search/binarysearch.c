#include <stdio.h>

static void shiftLeft(int *base, int *n, int l);
static void shiftRight(int *base, int *n, int l);

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

// Delete will do a lookup for the item, then shift all items to the left if 
// its found. Shifting to left will override the index. 
// Shifting left will decrease n.
int BinaryDelete(int *key, int *base, int *n) {
    int index;
    if ((index = BinarySearch(key, base, *n)) == -1) {
        return -1;
    }
    shiftLeft(base, n, index); 
    return index;
}

// Insert into ordered Array with O(log n) lookup and O(n/2) insertion.
int BinaryInsert(int *key, int *base, int *n, int MAX) {
    int min = 0, max = *n, mid;
    
    // make sure we dont go outside range of array.
    if (*n + 1 > MAX) {
        return -1;
    }

    // find the insertion point. 
    while (min < max) {
        mid = (min + max) / 2;
        if (base[mid] < *key) 
            min = mid + 1;
        else 
            max = mid;
    }
    
    // dont want duplicates.
    if (base[min] == *key) {
        return -1;
    }
    
    // make space for insertion by shifting array to the right.
    shiftRight(base, n, min); 
    
    // insert the new key.
    base[min] = *key;
    return min;
}

// linear decrease of array.
static void shiftLeft(int *base, int *n, int l) {
    int i;
    for (i = l; i < *n; i++) {
        base[i] = base[i + 1];
    }
    *n -= 1;
}

// linear increase of array.
static void shiftRight(int *base, int *n, int l) {
    int i;
    for (i = *n; i > l; i--) {
        base[i] = base[i - 1];
    }
    *n += 1;
}
