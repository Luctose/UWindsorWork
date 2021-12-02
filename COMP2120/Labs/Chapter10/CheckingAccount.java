/*
Lab 8 (Chapter 10)
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Nov 21 2021
*/

/**
 * This class runs intances of checking accounts
 */
public class CheckingAccount extends BankAccount{
    // Fields
    private final double FEE = 0.15;

    // Methods

    /**
     * Constructor initializes an account with the checking account number extension
     * @param name The name of the account holder
     * @param amount The starting balance of the account
     */
    public CheckingAccount(String name, double amount){
        super(name, amount);
        super.setAccountNumber(super.getAccountNumber() + "-10");
    }

    /**
     * Withdraws from the account with the checking withdrawal fee
     * @return If the account had sufficient funds
     */
    public boolean withdraw(double amount){
        return super.withdraw(amount + FEE);
    }
}
