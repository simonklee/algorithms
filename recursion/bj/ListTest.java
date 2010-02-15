import java.util.Random;

public class ListTest
{
    private List<Integer> intList;

    public ListTest()
    {       
        // Test Int sorting
        intList = new List();
        fillInt(20);
        
        System.out.print("Unsorted: "); intList.Print();
        
        Sorting<Integer> s = List.Sorted(new IntComp());
        System.out.print("Sorted:   "); intList.Print(); System.out.println();
        
        Iterator i = intList.Iterator();
        Node n = (Node)i.next();
        System.out.println(n.Data());
    }

    private void fillInt(int amount) {
        Random rand = new Random();
        for (int i = 0; i <= amount; i++) {
            intList.Push(rand.nextInt(99));    
        }
    }
    
    /**
     * Callback function to compare our int data.
     * 
     * if (o1 == o2)
     *     return 0;
     * else if (o1 > o2)
     *     return 1;
     * return -1;
     * 
     */
    static class IntComp implements Comperator<Integer> {
        public final int compare(Integer o1, Integer o2) {
            return o1.compareTo(o2);
        }
    }

}