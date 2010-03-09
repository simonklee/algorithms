/**
 * The test class TestShellSort.
 *
 * @author  Simon Zimmermann
 */
public class TestShellSort extends junit.framework.TestCase
{
    private Shellsort shell;

    static int[] arrEven = {3, 8, 9, 10, 2, 1, 4, 5, 7, 6};
    static int[] arrOdd = {3, 8, 9, 2, 1, 4, 5, 7, 6};
    static int[] arrSmall = {1, 2};
    static int[] arrVerySmall = {1};
    static int[] arrReversed = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    static int[] arrSorted = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    protected void setUp()
    {
        int[] a = {3, 8, 9, 10, 2, 1, 4, 5, 7, 6};
        shell = new Shellsort(a);
    }

    protected void tearDown()   {}

    // Test all weird cases.
    public void testEven() {testSort(arrEven);}
    public void testOdd() {testSort(arrOdd);}
    public void testSmall() {testSort(arrSmall);}
    public void testVerySmall() {testSort(arrVerySmall);}
    public void testReversed() {testSort(arrReversed);}
    public void testSorted() {testSort(arrSorted);}

    /**
     * Private array test method.
     */
    private void testSort(int[] a) {
        shell.setArray(a);
        shell.sort();
        for (int i = 0; i < shell.getN(); i++) {
            assertEquals(i+1, shell.getArray()[i]);
        }
    }

    /**
     * Testing the shellsort class' basic method's.
     */
    public void testSetup() {

        int[] aEmpty = {};
        Shellsort shellsort1 = new Shellsort(aEmpty);
        assertEquals(aEmpty, shellsort1.getArray());
        assertEquals(0, shellsort1.getN());

        int[] a = {3, 8, 9, 10, 2, 1};
        shellsort1.setArray(a);
        assertEquals(a, shellsort1.getArray());
        assertEquals(6, shellsort1.getN());

        Shellsort shellsort2 = new Shellsort(a);
        assertEquals(a, shellsort2.getArray());
        assertEquals(6, shellsort2.getN());
    }
}

