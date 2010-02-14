
public class recursion
{
    public static int loop(int []arr, int n) {        
        if (n < arr.length) { 
            System.out.println("arr["+ n +"] found " + loop(arr, ++n));
        }
        return n * 2;
    }
    
    public static void loopTest() {
        int []a = {1, 2, 3, 4, 5, 6, 7};
        loop(a, 0);
    }
}
