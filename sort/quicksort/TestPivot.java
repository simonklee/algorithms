
public class TestPivot extends junit.framework.TestCase
{
    private Pivot piv;
    
    static int[] arrEven = {3, 8, 9, 10, 2, 1, 4, 5, 7, 6};
    
    public TestPivot()
    {
        piv = new Pivot();
    }
    
    // Test all weird cases.
    public void testEven() {testPiv(arrEven);}
    
    protected void setUp()   {   }
    protected void tearDown()   {   }
    
    private void testPiv(int[] arr) {
        for (int i = 0; i < piv.getN(); i++) {
            int pivr = piv.partition(0, piv.getN(), i+1);
            assertEquals(i+1, pivr);
            
            int[] resArr = piv.getArray();
            int esum = 0, gsum = 0;

            // Calculate total sum of elems on left side of array.
            for (int j = 0; j < pivr; j++) {
                esum += j+1;
                gsum += resArr[j];
            }
            assertEquals(esum, gsum);

            // reset array.
            piv.setArray(arr);
        }
        
    }
}
