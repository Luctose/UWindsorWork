/*
Lab 8 (Chapter 10)
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Nov 21 2021
*/

public class SavingsAccount extends BankAccount{
    // Fields
    private double rate = 0.025;
    private int savingsNumber = 0;
    private String accountNumber;

    // Methods

    public SavingsAccount(String name, int amount){
        super(name, amount);
        accountNumber = super.getAccountNumber() + "-" + savingsNumber;
    }

    public SavingsAccount(SavingsAccount original, int amount){
        super(original, amount);
        savingsNumber++;
        accountNumber = super.getAccountNumber() + "-" + savingsNumber;
    }

    public void postInterest(){
        super.deposit(super.getBalance() * (rate / 12));
    }

    public String getAccountNumber(){
        return accountNumber;
    }
}
