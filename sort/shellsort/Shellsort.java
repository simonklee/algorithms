/**
 * A simple shell sort implementation using Knuth's intervals,
 * based on examples in Data Structrues & Algorithms in Java by
 * Robert Lafore. 
 *
 * @author  Simon Zimmermann
 */

public class Shellsort {   
    private int[] array;
    private int n;
    
    // just statistics. 
    private int swap, comp;

    public Shellsort(int[] array) {
        this.array = array;
        this.n = array.length;
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
     * Calculate gap using Knuth's sequence.
     */
    private int calcGap() {
        int h = 1;
        while (h <= n/3) {
            h = (3 * h) + 1;
        }
        return h; 
    }
    
    /**
     * @return Reverse gap calculation based on Knuth's sequence.
     */
    private int nextGap(int h) {
        return (h - 1) / 3;
    }
    
    
    /**
     * Perform shellsort on array. 
     */
    public void sort() {
        int h = calcGap();
        int tmp, inner, outer;
        swap = 0;
        comp = 0;

        while (h > 0) {
            for (outer = h; outer < n; outer++) {
                tmp = array[outer];
                inner = outer;
                
                while (inner - h >= 0 && array[inner - h] >= tmp) {
                    array[inner] = array[inner-h];
                    inner = inner - h;
                }
                array[inner] = tmp;
            }
            h = nextGap(h);
        }
    }
        
    // Get and set methods.
    public int getN() {return n;}
    public int[] getArray() {return array;}
    
    public void setArray(int[] a) {
        this.array = a;
        this.n = array.length;
    }
}


    