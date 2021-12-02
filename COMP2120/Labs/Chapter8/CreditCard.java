/*
Lab 7 (Chapter 8)
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Nov 14 2021
*/

/**
 * Stores credit card information and the methods to 
 * charge and pay credit cards
 */
public class CreditCard {
    // Fields
    // The balance of the cardholder
    private Money balance;
    // The credit limit of the cardholder
    private Money creditLimit;
    // The cardholder
    private Person owner;

    // Methods

    /**
     * Constructor initializes fields
     * @param newCardHolder New cardholder
     * @param limit Limit the card starts with
     */
    public CreditCard(Person newCardHolder, Money limit){
        // Initialize the fields
        owner = newCardHolder;
        creditLimit = new Money(limit);
        balance = new Money(0);
    }

    /**
     * Gets the balance of the card
     * @return The card balance with a seperate address
     */
    public Money getBalance(){
        return new Money(balance);
    }

    /**
     * Gets the card limit
     * @return The card limit with a seperate address
     */
    public Money getCreditLimit(){
        return new Money(creditLimit);
    }

    /**
     * Gets the cardholder details as a string
     * @return String of owner information
     */
    public String getPersonals(){
        return owner.toString();
    }

    /**
     * Charges the amount to the card given enough credit
     * @param amount Amount to be charged to the card
     */
    public void charge(Money amount){
        // Charge amount to balance only if their is enough credit
        if(creditLimit.compareTo(balance.add(amount)) >= 0){
            // Charge amount
            balance = new Money(balance.add(amount));
            System.out.println("Charge: " + amount.toString());
        }else{
            System.out.println("Exceeds credit limit");
        }
    }

    /**
     * Pays money back to the credit card account
     * @param amount Amount to pay down
     */
    public void payment(Money amount){
        // Pay the amount to the card
        System.out.println("Payment: " + amount.toString());
        balance = new Money(balance.subtract(amount));
    }
}
