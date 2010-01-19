//static void shiftRight(int *base, int n, int destIndex);

void InsertionSort(int *base, int n) {
    int mark;
    int i, j;
    for (i = 1; i < n; i++) {
        mark = base[i];
        for (j = i; base[j - 1] >= mark && j > 0; j--) {
            base[j] = base[j - 1];
        }
        base[j] = mark;
    }
}

/*// Shift N elems in array to.
static void shiftRight(int *base, int n, int destIndex) {
    int i;
    for (i = n; i > destIndex; i--) {
        base[i] = base[i - 1];
    }
}*/
