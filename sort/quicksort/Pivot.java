import java.util.Random;

public class Pivot
{
    private int[] array = {3, 8, 9, 10, 2, 1, 4, 5, 7, 6};
    private int n;
    private int piv;

    public Pivot() {
        this.n = array.length;
    }
    
    public int genPiv() {
        Random rand = new Random();
        return array[rand.nextInt(n)];
    }
    
    public int getPiv() {
        return this.piv;
    }
    
    public int partition(int left, int right, int piv) {
        this.piv = piv;
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
    
    private void swap(int a, int b) {
        int tmp = array[a];
        array[a] = array[b];
        array[b] = tmp;
    }
    
    public void print() {
        for(int i = 0; i < n; i++) {
            if (i == piv) {
                System.out.print(" <> ");    
            }
            System.out.print(array[i] + " ");

        }
        System.out.println(" |");
    }
    
    public int getN() {
        return n;
    }
    
    public int[] getArray() {
        return array;
    }

    public void setArray(int[] a) {
        this.array = a;
        this.n = array.length;
    }
}
