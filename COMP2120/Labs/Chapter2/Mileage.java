// Import required modules
import java.util.Scanner;

/*
Lab 1
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Sept 26 2021
*/

/**
    The Purpose of this program is
    to calculate the mileage of
    your car.
 */

public class Mileage 
{   // Main method of the Mileage class
    public static void main(String[] args){

        // Create Scanner object for reading user input
        Scanner keyboard = new Scanner(System.in);

        // Declare variables
        double miles;       // Miles driven
        double gallons;     // Gallons used
        double mpg;       // Miles per gallon

        // Tell the user what this program does
        System.out.println("This program will calculate the mileage on your car.");
        
        // Getting required inputs from user in order to find mileage
        // Prompt user to input miles driven
        System.out.print("Enter miles driven: ");
        // Read user input for miles
        miles = keyboard.nextDouble();
        // Prompt user for gallons used
        System.out.print("Enter gallons used: ");
        // Read in gallons used
        gallons = keyboard.nextDouble();

        // Calculate miles per gallon and store it in mpg
        // In order to find Miles per gallon of the users car
        mpg = miles / gallons;

        // Print formatted text to standard output showing results
        System.out.printf("Results\n" + "Miles driven: %.2f\n" + 
        "Gallons used: %.2f\n" + "Miles per gallon: %.2f\n", miles, gallons, mpg);
    }
}
