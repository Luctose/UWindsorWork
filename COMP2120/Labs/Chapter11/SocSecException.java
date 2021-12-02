/*
Lab 9 (Chapter 11)
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 1 2021
*/

/**
 * Exception for wrong social security number format
 */
public class SocSecException extends Exception
{
    /**
     * Constructor initializes an Exception with an error message
     * @param error
     */
    public SocSecException(String error){
        super("Invalid social security number, \n" + error);
    }
}