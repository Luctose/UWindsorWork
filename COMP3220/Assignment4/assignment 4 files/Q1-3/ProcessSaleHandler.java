import java.util.Scanner;

public class ProcessSaleHandler {
    public static void main(String[] args){
        this.Start("Quebec");
    }

    public void Start(String area){
        Store myStore = new Store();
        Register reg1 = myStore.getRegister();
        String curin = null;

        System.out.println("Welcome to the store.\n");

        reg1.makeNewSale(area);
        Scanner inp = new Scanner(System.in);

        do{
            System.out.print("Please enter an item (100,200,220,313,500) or finish (0): ");
            curin = inp.nextLine();

            if(Integer.parseInt(curin) > 0){
                System.out.print("How many? ");
                reg1.enterItem(new ItemID(Integer.ParseInt(curin)), Integer.parseInt(inp.nextLine()));
            }

        }while(!curin.equals("0"));

        System.out.print("Enter money tendered: ");
        curin = inp.nextLine();

        reg1.makePayment(new Money(Double.parseDouble(curin)));

        reg1.endSale();

        System.out.println("Sale Complete");
    }
}