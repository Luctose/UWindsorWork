/*
Assignment 3
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

/**
 * Exception thrown when the employee number is invalid
 */
public class EmployeeNumberException extends Exception{
    /**
     * Creates new EmployeeNumberException
     * @param error String explaining specific error
     */
    public EmployeeNumberException(String error){
        super("Invalid employee number, " + error);
    }
}
