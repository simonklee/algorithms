import java.util.Random;
/**
 * @author  Simon Zimmermann
 */
public class QuickSort
{
    private int[] array;
    private int n;
    private int comp;
    private int swap;

    public QuickSort() {

    }

    /**
     * Do Quicksort on array.
     */
    public void sort() {
        comp = 0;
        swap = 0;
        long start = System.currentTimeMillis(); // start. 
        qsort(0, n-1);
        
        printStat(System.currentTimeMillis() - start);
    }
    
    private void qsort(int left, int right) {
        // since it's called recursivly we need to make it stop.
        if (right - left < 1)
            return;
        else {
            // we use the rightmost elem as pivot.
            int piv = array[right];
            
            int part = partition(left, right, piv); 
            qsort(left, part - 1);
            qsort(part + 1, right);
        }
    }
   
    /**
     * Partition will move items bigger then piv from left to 
     * the right end of the array, replacing smaller items
     * on the right, in a swap. 
     */
    public int partition(int leftPtr, int rightPtr, int piv) {
        int left = leftPtr;
        int right = rightPtr;

        while (left <= right) {
            while (array[left] < piv) {
                left++;
                comp++;
            }
            while (right > 0 && array[--right] > piv);
    
            if (left >= right)
                break;
            swap(left, right);
        }
        swap(left, rightPtr);
        return left;
    }    

    public void printStat(long time) {
        System.out.println("Swap: "+swap+", Comp: "+comp+" Time: "+time+"ms");
    }
    
    /**
     * Simple swap on internal array.
     */
    private void swap(int a, int b) {
        //System.out.println("Swap: "+array[a]+" <> "+array[b]);
        swap++;
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
        for(int i = 0; i < array.length; i++)
            System.out.print(array[i] + " ");
        System.out.println();
    }
    
    public void fill(int N) {
        array = new int[N];
        Random rand = new Random();

        for (int i = 0; i < N; i++) {
            int nr = rand.nextInt(N);
            //while (find(array, nr) > 0) {
              //  nr = rand.nextInt(N);
            //}
            array[i] = nr;
            
        }
        this.n = array.length;
    }
    
    private int find(int[] arr, int key) {
        for (int i = 0; i < arr.length; i++) 
            if (arr[i] == key)
                return i;
        return -1;
    }  
    
    
    // Get and set methods.
    public int getN() {return n;}
    public int[] getArray() {return array;}

    public void setArray(int[] a) {
        this.array = a;
        this.n = array.length;
    }    
}
