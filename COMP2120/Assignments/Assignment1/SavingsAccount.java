/*
Assignment 1
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Oct 24 2021
*/

/**
 * This class manages a savings account
 */
public class SavingsAccount {
    // Fields
    private double balance; // Account balance
    private double intrate; // Annual interest rate

    /**
     * Constructor initializes balance and interest rate
     * Requires params as doubles
     * @param bal Account balance
     * @param interest Account annual interest rate
     */
    public SavingsAccount(double bal, double interest){
        // Set balance to param
        balance = bal;
        // Set intrate to param
        intrate = interest;
    }

    /**
     * Withdraw money from account
     * @param amount Amount to be withdrawn
     */
    public void withdraw(double amount){
        // Subtract withdrawal amount from account
        balance -= amount;
    }

    /**
     * Add money to account
     * @param amount Amount given to add to balance
     */
    public void deposit(double amount){
        // Add amount to account
        balance += amount;
    }

    /**
     * Give account monthly interest
     */
    public void compoundInterest(){
        // Calculate interest and add to balance
        balance = (1 + (intrate / 12.0)) * balance;
    }

    /**
     * Accessor to get the account balance
     * @return Balance of the account
     */
    public double getBal(){
        // Give balance
        return balance;
    }

    /**
     * Accessor to get the account interest rate
     * @return Interest rate of the account
     */
    public double getIntrate(){
        // Give interest rate
        return intrate;
    }
}
