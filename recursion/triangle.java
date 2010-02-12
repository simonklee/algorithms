public class triangle {
    
    public triangle() {
    
    }
    
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
    
    public static int triangleTotal(int n) {
        int total = 0;
        do {
            total += n;
            n--;
        } while (n > 0);
        return total;
    }
    
    public static int triangleTotalRecur(int n) {
        if (n > 0) {
            return (n + triangleTotalRecur(--n));
        }      
        return 0;
    }
    
    public static void triTest() {
        for (int i = 1; i <= 10; i++) {
            for (int j = 10; j >= 1; j--) {
                if (5 == j)
                    System.out.print(triangleTotalRecur(i));
                else
                    System.out.print("x");
            }
            System.out.println();
        }
    }
    
    public static void main(String []args) {
        loopTest();
        //triTest();       
    }
}
