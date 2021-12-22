/*
Assignment 3
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

/**
 * Demo class of the ShiftSupervisor
 */
public class ShiftSupervisorDemo {
    public static void main(String[] args){
        // "Hire" new supervisors
        ShiftSupervisor supervisor1 = new ShiftSupervisor("John Smith", "123-A", "11-15-2005", 48000.00, 6500.00);
        ShiftSupervisor supervisor2 = new ShiftSupervisor("Joan Jones", "222-L", "12-12-2005", 55000.00, 8000.00);

        // Print the supervisor's info
        System.out.println("Here's the first shift supervisor.\n" + supervisor1);
        System.out.println("Here's the second shift supervisor.\n" + supervisor2);
    }
}
