/*
Assignment 3
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

public class Customer extends Person{
    // Fields
    private String custNumber;
    private boolean mailList;

    // Methods
    public Customer(){
        super();
        custNumber = null;
        mailList = false;
    }

    public Customer(String name, String address, String number, String custNumber, boolean mailList){
        super(name, address, number);
        this.custNumber = custNumber;
        this.mailList = mailList;
    }

    public String getCustNum(){
        return custNumber;
    }

    public boolean onMailList(){
        return mailList;
    }

    public void setCustNum(String custNumber){
        this.custNumber = custNumber;
    }

    public void setMailList(boolean mailList){
        this.mailList = mailList;
    }

    public String toString(){
        return super.toString() + String.format("Customer Number: %s\n", custNumber) +
               String.format("Mailing List: %s\n", (mailList ? "YES" : "NO"));
    }
}
