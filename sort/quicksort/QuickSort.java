
/**
 * @author  Simon Zimmermann
 */
public class QuickSort
{
    private int[] array;
    private int n;

    public QuickSort(int[] array) {
        this.array = array;
        this.n = array.length;

    }

    /**
     * Do Quicksort on array.
     */
    public void sort() {
        qsort(0, n);
    }
    
    private void qsort(int left, int right) {}
   
    /**
     * Partition will move items bigger then piv from left to 
     * the right end of the array, replacing smaller items
     * on the right, in a swap. 
     */
    public int partition(int left, int right, int piv) {
        while (true) {
            while (left < right) {
                if (array[left] > piv) 
                    break;
                left++;
            }
            while (left < right && array[--right] > piv);
    
            if (left >= right)
                break;
            swap(left, right);
        }
        return left;
    }    

    /**
     * Simple swap on internal array.
     */
    private void swap(int a, int b) {
        int tmp = array[a];
        array[a] = array[b];
        array[b] = tmp;
    }
    
    /**
     * Append to the end of the array.
     */
    public void append(int data) {
        array[n] = data;
        n++;
    }

    /**
     * @return Retrieve the last item in array or -1;
     */
    public int get() {
        if (n > 0) {
            n--;
            return array[n];
        }
        return -1;
    }
    
    /**
     * Print array.
     */
    public void print() {
        for(int i = 0; i < n; i++)
            System.out.print(array[i] + " ");
        System.out.println();
    }
    
    // Get and set methods.
    public int getN() {return n;}
    public int[] getArray() {return array;}

    public void setArray(int[] a) {
        this.array = a;
        this.n = array.length;
    }    
}
