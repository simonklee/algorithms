static int swap(int *a, int *b);

void BubbleSort(int *base, int n) {
    int i, j;
    for (i = (n - 1); i > 1; i--) {
        for (j = 0; j < i; j++) {
            if (base[j] > base[j + 1]) {
                // int tmp = base[j];
                // base[j] = base[j + 1];
                // base[j + 1] = tmp;
                swap(&base[j], &base[j + 1]); 
            }
        }
    }
}

static int swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
