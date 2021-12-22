/*
Assignment 3
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

public class PreferredCustomer extends Customer{
    // Fields
    private double purchases;
    private double discount;

    // Methods
    public PreferredCustomer(){
        super();
        purchases = 0;
        discount = 0;
    }

    public PreferredCustomer(String name, String address, String number, String custNumber, 
    boolean mailList, double purchases, double discount){
        super(name, address, number, custNumber, mailList);
        this.purchases = purchases;
        this.discount = discount;
    }

    public double getPurchases(){
        return purchases;
    }

    public double getDiscount(){
        return discount;
    }

    public void setPurchase(double purchases){
        this.purchases = purchases;
    }

    public void setDiscount(double discount){
        this.discount = discount;
    }

    public void calcDiscount(){
        if(purchases >= 2000){
            discount = 0.10;
        }else if(purchases >= 1500){
            discount = 0.07;
        }else if(purchases >= 1000){
            discount = 0.06;
        }else if(purchases >= 500){
            discount = 0.05;
        }else{
            discount = 0;
        }
    }

    public String toString(){
        return super.toString() + String.format("Purchases: $%.2f\n", purchases) +
               String.format("Discount level: %.2f\n", discount);
    }
}
