/*
Assignment 3
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

public class PreferredCustomerDemo {
    public static void main(String[] args){
        PreferredCustomer julie = new PreferredCustomer("Julie James", "123 Main Street", "555-1212", 
        "147-A049", true, 1750.00, 0);
        julie.calcDiscount();
        System.out.println(julie);
    }
}
