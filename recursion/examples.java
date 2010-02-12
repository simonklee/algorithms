import java.util.*;

public class examples {

    public static int mult(int x, int y) {
        if (y > 1) 
            return x + mult(x, y-1);
         else if (y < -1)
            return mult(x, y+1) - x;
         else
            return x;
    }   
    
    public static int choose(int m, List<String> cand) {
        List<String> team = new ArrayList<String>();
        select(team, cand, m);
        return 0;
    }
    
    private static void select(List<String> selected, List<String> cand, int m) {
        if (m == 0) {
            System.out.print("Team:");
            for (String s : selected) System.out.print(" "+s);
        }
        else {
            ArrayList<String> usedhere = new ArrayList<String>(used);
            for (String s : cand) {
                if (!selected.contains(s) && !usedhere.contains(s)) {
                    selected.add(s);
                    select(selected, usedhere, m - 1);
                    selected.remove(s);
                    usedhere.add(s);
                }
            }
        }
    }
    
    public static void main(String [ ] args) {
        System.out.println(mult(2, 2));
        //String []s = { "Per", "Kari", "Ola", "nordmann"};
        ArrayList<String> cand = new ArrayList<String>();//asList(s);
        cand.add("Per");
        cand.add("Kari");
        cand.add("Kongen");
        cand.add("Ari");
        cand.add("Mertha");
        select(new ArrayList<String>(), cand, 5);
        
    }
}
