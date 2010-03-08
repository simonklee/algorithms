import java.util.Random;

public class ListTest
{
    public ListTest()
    {
        // Test Int sorting
        List list1 = new List();
       // fillIntSorted(list1, 7);
        list1.Push(24);
        list1.Push(21);
        list1.Push(16);
        list1.Push(11);
        list1.Push(4);

        List list2 = new List();
        list2.Push(25);
        list2.Push(20);
        list2.Push(15);
        list2.Push(10);
        list2.Push(5);

        System.out.print("LIST1:\n"); list1.Print();System.out.println();
        System.out.print("LIST2:\n"); list2.Print();System.out.println();

        List res = merge(list1, list2);
        res.Print();

    }

   public void fillIntSorted(List list, int amount) {
        Random rand = new Random();
        int tmp;
        int prev = 0;
        int i = 0;
        while (i <= amount) {
           tmp = rand.nextInt(99);
           if (tmp > prev && tmp < (prev + 10)) {
               list.Push(tmp);
               prev = tmp;
               i++;
           }
        }
    }

    private void fillInt(List list, int amount) {
        Random rand = new Random();
        for (int i = 0; i <= amount; i++) {
            list.Push(rand.nextInt(99));
        }
    }

    public List merge(List list1, List list2) {
        List result =  new List();

        while (!list1.IsEmpty()  && !list2.IsEmpty()) {
            if (list1.First().Data() < list2.First().Data())
                result.PushLast(list1.Pop());
            else
                result.PushLast(list2.Pop());
        }

        while (!list1.IsEmpty())
            result.PushLast(list1.Pop());

        while (!list2.IsEmpty())
            result.PushLast(list2.Pop());

        return result;
    }
}
