
public class SortedList<T> {
    private List<? super T> list;
    private Comperator<Object> comp;

    public SortedList(List<T> list, Comperator<Object> comp) {
        this.list = list;
        this.comp = comp;
    }

    public List Sort() {
        Node mark;
        Node reverse;
        Node current = list.First().Next();
        while (current != null) {
            mark = current;
            reverse = current;
            while (reverse.Prev() != null && comp.compare(reverse.Prev().Data(), mark.Data()) > 0) {
                reverse = reverse.Prev();
            }
            if (mark != reverse) {
                list.Move(mark, reverse);
            }
            current = current.Next();
        }
        return list;
    }
}
