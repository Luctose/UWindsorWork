import java.util.ArrayList;
public class Test{
    public static void main(){
        ArrayList<Bucket> buckets = new ArrayList<Bucket>();
        List

        for(int i = 0; i < 100; ++i){
            for(int j = 0; j < 100; ++j){
                if((j + 1) % (i + 1) == 0){
                    buckets.get(i).add(j + 1);
                }
            }
        }
    }
}