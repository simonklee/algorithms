#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <citrus.h>
#include "bubblesort.h"

static void testBubbleSort(Suite *suite);

int main(int argc, char **argv) {
    Suite *suite;

    // allocate memory.
    suite = malloc(sizeof (Suite *));
    memset(suite, 0, sizeof *suite);
    
    // run tests.
    testBubbleSort(suite);
    
    // view summary.
    Summary(suite);

    // clean end.
    free(suite);
    return 0;
}

static void testBubbleSort(Suite *suite) {
    int arr[10] = {73, 19, 29, 20, 57, 1, 8, 99, 4, 28};
    int i;
    
    printf("Unsorted Array\n");    
    for (i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
    
    BubbleSort(arr, 10);
    printf("Sorted Array\n");
    for (i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
}
