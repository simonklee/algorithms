#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

// Compare functions are needed since binary search function doesn't know
// how to compare void *'s. 

static int intComp(const void *a, const void *b) {
    int *aptr = (int *)a;
    int *bptr = (int *)b;
    return *aptr - *bptr; 
}

static int strComp(const void *a, const void *b) {
    char *aptr = (char *)a;
    char *bptr = (char *)b;
    return strcmp(aptr, bptr);
}

// a more generic approach to Binary Search. First try.
void *BinarySearchG(const void *key, const void *base,
                     size_t nmemb, size_t size,
                     int (*compar)(const void *, const void *)) {
    int min = 0, mid, max;
    max = (int) nmemb;
    //mid = (min + max) / 2;
    //printf("%d\n", max);

    while (min <= max) {
        mid = (min + max) / 2;
        if (compar((void*)(base + (mid * size)), key) < 0)
            min = mid + 1;
        else if (compar((void*)(base + (mid * size)), key) > 0)
            max = mid - 1;
        else 
            return (void *)base + (mid * size); // return address of key.
    } 
    return NULL;
}

// small test
int main(int argc, char **argv) {
    printf("Test intComp:\n");
    int a, b;
      
    a = 1, b = 1;
    printf("intComp(%d, %d) == %d\n", a, b, intComp(&a, &b)); // 0
    
    a = 2, b = 1;
    printf("intComp(%d, %d) == %d\n", a, b, intComp(&a, &b)); // 1
    
    a = 1, b = 2;
    printf("intComp(%d, %d) == %d\n\n", a, b, intComp(&a, &b)); // -1
    
    printf("Test strComp:\n");
    // arrays in c, thats what i call readability!
    char *chb = "ABC", *cha = "ABC";
    printf("strComp(%c, %c) == %d\n", *cha, chb[0], strComp(cha, &chb[0])); // 0
    printf("strComp(%c, %c) == %d\n", *(cha + 1), chb[0], strComp((cha + 1), &chb[0])); // 1
    printf("strComp(%c, %c) == %d\n\n", cha[0], chb[1], strComp(&cha[0], &chb[1])); // -1
    
    printf("Test BinarySearchG:\n");
    int *res, key = 9;
    int arr[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    if ((res = BinarySearchG(&key, arr, N, sizeof(int), intComp)) != NULL)
        printf("%d\n", *res);
    
    key = 10;
    if ((res = BinarySearchG(&key, arr, N, sizeof(int), intComp)) != NULL)
        printf("%d\n", *res);
    else printf("not found\n");        
    return 0;
}

