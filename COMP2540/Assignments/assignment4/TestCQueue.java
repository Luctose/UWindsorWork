public class TestCQueue {
    public static void main(String[] args){
        CQueue<Integer> q = new CQueue<>(Integer.class, 30);
        q.enqueue(5);
        System.out.println(q);
        System.out.println(q.dequeue());


    }
}
