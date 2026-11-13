import java.util.ArrayList;
import java.util.Iterator;

public class Sale {
    ArrayList<Item> cart;
    Customer cust;
    double total;

    public Sale(Customer cust){
        this.cust = cust;
        this.cart = new ArrayList<Item>();
        this.total = 0;
    }

    public void addItem(Item item){
        this.cart.add(item);
        this.total += item.itemTotal();
    }

    public void printReceipt(){
        System.out.printf("Customer: %s\n", cust.getName());
        Iterator<Item> iter = cart.iterator();
        while(iter.hasNext()){
            Item curItem = iter.next();
            System.out.printf("%dx %s --- $%.2f\n", curItem.getQuantity(), curItem.getName(), curItem.itemTotal());
        }
    }
}
