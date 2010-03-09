/**
 * The test class TestQuickSort.
 */

public class TestQuickSort extends junit.framework.TestCase
{
    private QuickSort quick;
    
    static int[] arrDefault = {3, 8, 9, 10, 2, 1, 4, 5, 7, 6};
    
    public TestQuickSort()  {
        quick = new QuickSort(arrDefault);
    }
    protected void setUp() { }
    protected void tearDown() { }
    
    public void testDefaultSort() {testSort(arrDefault); }
    
    /**
    * Private array test method.
    */

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
