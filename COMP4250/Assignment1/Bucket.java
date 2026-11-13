import java.util.ArrayList;

public class Bucket(){
    ArrayList<int> bucketlist;

    public Bucket(){
        bucketlist = new ArrayList<int>();
    }

    add(int num){
        bucketlist.add(num);
    }
}