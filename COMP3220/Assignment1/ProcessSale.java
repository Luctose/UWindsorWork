import java.util.Scanner;

public class ProcessSale {
    public static void main(String[] args){
        
        Item[] itemList = new Item[6];
        // Available items
        itemList[0] = new Item("chicken", 13.39, 1);
        itemList[1] = new Item("beef", 12.99, 1);
        itemList[2] = new Item("garlic", 0.88, 5);
        itemList[3] = new Item("onion", 1.99, 2);
        itemList[4] = new Item("yogurt", 4.49, 2);
        itemList[5] = new Item("potato", 15.39, 1);

        // Enter customer info
        Scanner in = new Scanner(System.in);
        System.out.print("Enter name: ");
        String cname = in.nextLine();
        System.out.print("Enter address: ");
        String caddress = in.nextLine();
        System.out.print("Enter number: ");
        String cnumber = in.nextLine();

        Customer myself = new Customer(cname, caddress, cnumber);

        // Initialize sale
        Sale nextSale = new Sale(myself);

        int choice = 0;
        while(choice != 7){
            System.out.print("Choose an item to add:\n1 - Chicken\n2 - Beef\n3 - Garlic\n4 - Onion\n5 - Yogurt\n6 - Potato\n7 - Checkout\n: ");
            choice = in.nextInt();
            if(choice != 7){
                nextSale.addItem(itemList[choice - 1]);
            }
        }
        // Print reciept
        nextSale.printReceipt();

        in.close();
    }
}
