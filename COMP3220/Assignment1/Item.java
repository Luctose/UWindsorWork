public class Item {
    String itemName;
    double price;
    int quantity;

    public Item(String name, double price, int quantity){
        this.itemName = name;
        this.price = price;
        this.quantity = quantity;
    }

    public double itemTotal(){
        return this.price * this.quantity;
    }

    public String getName(){
        return this.itemName;
    }

    public int getQuantity(){
        return this.quantity;
    }
}
