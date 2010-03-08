#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

// Compare functions are needed since binary search function doesn't know
// how to compare void *'s.
static void *Test(const void *key, const void *base,
                     size_t nmemb, size_t size,
                     int (*compar)(const void *, const void *));

static int intComp(const void *a, const void *b) {
    int *aptr = (int *)a;
    int *bptr = (int *)b;
    return *aptr - *bptr;
}

static int strComp(const void *a, const void *b) {
    char *aptr = *(char **)a;
    char *bptr = *(char **)b;
    return strcmp(aptr, bptr);
}

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
    char *cha = "ABC", *chb = "ABC";
    printf("strComp(%c, %c) == %d\n", *cha, chb[0], strComp(cha, &chb[0])); // 0
    printf("strComp(%c, %c) == %d\n", *(cha + 1), chb[0], strComp((cha + 1), &chb[0])); // 1
    printf("strComp(%c, %c) == %d\n\n", cha[0], chb[1], strComp(&cha[0], &chb[1])); // -1*/

    printf("Test BinarySearchG on int array:\n");
    int *res, key = 9;
    int arr[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    if ((res = BinarySearchG(&key, arr, N, sizeof(int), intComp)) != NULL)
        printf("%d\n", *res);

    key = 10;
    if ((res = BinarySearchG(&key, arr, N, sizeof(int), intComp)) != NULL)
        printf("%d\n", *res);
    else printf("not found\n\n");

    printf("Test BinarySearchG on char array:\n");
    char *arr2[] = {"ABC", "DEF", "GHI", "JKL", "MNS", "OPQ", "RST", "UVW", "XYZ"};

    if ((res = BinarySearchG(arr2, arr2, 9, sizeof(char *), strComp)) != NULL)
        printf("%d\n", *res);
    else printf("not found\n");

    printf("\nArithmetics: %s, %s, %s\n", arr2[0], *(arr2 + 1), *(arr2 + 2));
    printf("pointers: %p, %p, %p\n", &arr2[0], (arr2 + 1), (arr2 + 2));

    printf("\nCast arrays to void *\n");
    void *varr2 = (void *)arr2;
    void *varr = (void *)arr;

    int elm_size2 = sizeof(char **); // 8
    int elm_size = sizeof(int); // 4

    printf("Proof of concept: (char*)varr + 0 * elm_size == varr === ptr\n");
    // char * array
    printf("%s,\t%s,\t%p,\t%p\n", *(char **)varr2
                                , *(char **)((char *) varr2 + 2 * elm_size2)
                                , (char *)varr2 + 0 * elm_size2
                                , (char *)varr2 + 2 * elm_size2);
    // int array.
    printf("%d,\t%d,\t%p,\t%p\n\n", *(int *)varr
                                  , *(int *)((char *) varr + 0 * elm_size)
                                  , (char *)varr + 0 * elm_size
                                  , varr);

    // The Important tests. Does it work?
    void *result = Test(&arr2[2], arr2, 9, sizeof(char *), strComp);
    void *result2 = Test(&arr[2], arr, N, sizeof(int), intComp);

    #if VERBOSE
    printf("Char * Array results:\n");
    printf("expected: %p,\t%s\n", &arr2[2], arr2[2]);
    printf("result:   %p,\t%s\n\n", result, *(char **)result);

    printf("Int Array results:\n");
    printf("expected: %p,\t%d\n", &arr[2], arr[2]);
    printf("result:   %p,\t%d\n\n", result2, *(int *)result2);
    #endif
    return 0;
}

static void *Test(const void *key, const void *base,
                     size_t nmemb, size_t size,
                     int (*compar)(const void *, const void *)) {

    void * f = ((char *) base + 2 * size);
    printf("%p\n", ((char *) base + 2 * size));
    printf("%p\n", ((char *) key));
    printf("%d\n", compar(base + 2 * size, key));

    int min = 0, mid, max;
    max = (int) nmemb;

    while (min <= max) {
        mid = (min + max) / 2;
        if (compar(base + mid * size, key) < 0)
            min = mid + 1;
        else if (compar(base + mid * size, key) > 0)
            max = mid - 1;
        else
            return (void *)base + mid * size; // return address of key.
    }
    return NULL;
}
