
public class recursion
{
    public static int loop(int []arr, int n) {        
        if (n < arr.length) { 
            System.out.println("arr["+ n +"] found " + arr[n]);
            return loop(arr, ++n);
        }
        return 0;
    }
    
    public static void loopTest() {
        int []a = {1, 2, 3};
        loop(a, 0);
    }
}
