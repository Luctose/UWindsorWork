/*
Midterm
Lucas Sarweh
ID: 110042658
COMP-2120
Sat Oct 30 2021
*/

// Import scanner
import java.util.Scanner;

/**
 * This class stores each of the months total rain and 
 * gives statistics based on the data
 */
public class RainFall {
    // Fields
    private double[] monthRain = new double[12];

    // Methods

    public RainFall(){
        // Open a scanner for keyboard
        Scanner keyboard = new Scanner(System.in);
        // Stores input
        double input = 0;

        // Set all the months
        for(int i = 0; i < 12; i++){
            // Prompt to input
            System.out.printf("Input month %d: ", i + 1);
            // Ask for input
            input = keyboard.nextDouble();
            // Make sure it's valid
            if(input >= 0){
                monthRain[i] = input;
            }else{
                monthRain[i] = 0;
            }
        }
        // Close the keyboard
        keyboard.close();
    }

    /**
     * Returns the annual rainfall by summing all the monthly rainfall, 
     * Accessor
     * @return The annual rainfall
     */
    public double totAnnualRain(){
        // Initialize variable to store the sum
        double sum = 0;
        // Sum all of the months rainfall
        for(double val : monthRain){
            // Add val to the sum
            sum += val;
        }
        // Return the sum at the end
        return sum;
    }

    /**
     * Returns the average monthly rain for the year, 
     * Accessor
     * @return Average monthly rain
     */
    public double avgMonthlyRain(){
        // To track the sum
        double sum = 0;
        // sum all the months
        for(double val : monthRain){
            sum += val;
        }
        // Calculate average and return it
        return sum / 12;
    }

    /**
     * Gets the month with the most rainfall
     * @return Month with highest rainfall
     */
    public double mostRain(){
        // Used to keep track of largest variable
        double most = monthRain[0];
        // See which has the most rain
        for(int i = 1; i < monthRain.length; i++){
            // Compare
            if(most < monthRain[i]){
                most = monthRain[i];
            }
        }
        // Return the month with the most rainfall
        return most;
    }

    /**
     * Gets the month with the least rainfall
     * @return The month with the least rainfall
     */
    public double leastRain(){
        // Used to keep track of smallest variable
        double least = monthRain[0];
        // See which has the least rain
        for(int i = 1; i < monthRain.length; i++){
            // Compare
            if(least > monthRain[i]){
                least = monthRain[i];
            }
        }
        // Return the month with the least rainfall
        return least;
    }

    /**
     * Gets the month index with most rainfall
     * @return index with largest value
     */
    public int mostIndex(){
        // Used to keep track of largest variable
        double most = monthRain[0];
        int index = 0;
        // See which has the most rain
        for(int i = 1; i < monthRain.length; i++){
            // Compare
            if(most < monthRain[i]){
                most = monthRain[i];
                index = i;
            }
        }
        // Return the month index with the most rainfall
        return index;
    }

    /**
     * Gets the month index with least rainfall
     * @return index with least value
     */
    public int leastIndex(){
        // Used to keep track of smallest variable
        double least = monthRain[0];
        int index = 0;
        // See which has the least rain
        for(int i = 1; i < monthRain.length; i++){
            // Compare
            if(least > monthRain[i]){
                least = monthRain[i];
                index = i;
            }
        }
        // Return the month index with the least rainfall
        return index;
    }
}
