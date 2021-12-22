/*
Assignment 3
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

public class BankAccountException extends Exception{
    // Methods
    public BankAccountException(String error){
        super("Bank account error, " + error);
    }
}
