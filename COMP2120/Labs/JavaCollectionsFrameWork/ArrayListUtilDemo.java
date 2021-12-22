import java.util.ArrayList;

public class ArrayListUtilDemo {
    public static void main(String[] args){
        ArrayList<Integer> newlist = new ArrayList<Integer>();
        newlist.add(3);
        newlist.add(6);
        newlist.add(4);
        newlist.add(9);
        System.out.println(ArrayListUtil.GiveReverseArray(newlist));
        ArrayListUtil.reverseArray(newlist);
        System.out.println(newlist);
    }
}
