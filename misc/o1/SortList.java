import java.util.Random;

public class SortList
{
    private List list;

    public SortList()
    {
        list = new List();
        fill(2);
        list.Print();
        Sort();
        list.Print();
    }
    
    public void Sort() {
        Node mark;
        Node reverse;
        Node current = list.First().Next();
        while (current != null) {
            mark = current;
            reverse = current;
            while (reverse.Prev() != null && reverse.Prev().Data() > mark.Data()) {
                reverse = reverse.Prev();
            }
            if (mark != reverse) {
                list.Move(mark, reverse);
            }
            current = current.Next();
        }
    }
    
    private void fill(int amount) {
        Random rand = new Random();
        for (int i = 0; i <= amount; i++) {
            list.Push(rand.nextInt(99));    
        }
    }
}