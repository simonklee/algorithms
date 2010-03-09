
/**
 * The test class TestQuickSort.
 */

public class TestQuickSort extends junit.framework.TestCase
{
    private QuickSort quick;
    static int[] arrDefault = {3, 8, 9, 10, 2, 1, 4, 5, 7, 6};
    private int[] arrBig = {13, 65, 95, 21, 47, 79, 58, 39, 45, 55};
    private int[] arrBigSorted = {13, 21, 39, 45, 47, 55, 58, 65, 79, 95};
    
    public TestQuickSort()  {
        quick = new QuickSort();


    }
    

    
    protected void setUp() {}
    protected void tearDown() {}
    
    public void testDefaultSort() {testSort(arrDefault); }
    public void testBigSort() {
        quick.setArray(arrBig);
        quick.sort();
        
        for (int i = 0; i < quick.getN(); i++) {
            assertEquals(arrBigSorted[i], quick.getArray()[i]);
        }
        
    }
    

    /**
     * Private array test method.
     */
    private void testSort(int[] a) {
        quick.setArray(a);
        quick.sort();
        for (int i = 0; i < quick.getN(); i++) {
            assertEquals(i+1, quick.getArray()[i]);
        }
    }
}
