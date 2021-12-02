/*
Lab 6 (Chapter 7)
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Nov 7 2021
*/

// Scanner
import java.util.Scanner;

public class Average
{
    // Fields
    private int[] data;
    private double mean;

    // Methods

    /**
     * Constructor asks user for scores and stores them, 
     * as well as sorting the data and calculating the mean
     */
    public Average(){
        // Init data
        data = new int[5];

        // Keyboard input
        Scanner keyboard = new Scanner(System.in);

        // Get the user scores
        for(int i = 0; i < data.length; i++){
            // Prompt user for input
            System.out.printf("Enter score %d: ", i + 1);
            data[i] = keyboard.nextInt();
        }
        // Sort and calculate the mean
        selectionSort();
        calculateMean();
    }

    /**
     * Calculates the mean of the data field and stores it in mean
     */
    public void calculateMean(){
        // Keep track of sum total
        int sum = 0;

        // Loop through each score
        for(int i = 0; i < data.length; i++){
            sum += data[i];
        }
        // Store the mean
        mean = (double)sum / (double)data.length;
    }

    /**
     * Converts the data of the object to a String, 
     * Requires data to be sorted
     */
    public String toString(){
        // String to store the data and return
        String str = "Data: " + Integer.toString(data[0]);
        // Loop through the data
        for(int i = 1; i < data.length; i++){
            // Concatenate each int to the string
            str = str.concat(", " + Integer.toString(data[i]));
        }
        // Concatenate the mean
        str = str.concat("\nMean: " + Double.toString(mean));

        // Return the completed String
        return str;
    }

    /**
     * This sorts the integer array data using selection 
     * sort. The array is sorted in descending order
     */
    public void selectionSort(){
        // Store max variable of each pass
        int max;
        int maxIndex;
        // Selection Sort
        for(int i = 0; i < data.length; i++){
            // Reset current pass index and max value
            max = Integer.MIN_VALUE;
            maxIndex = i;
            // See which is biggest of unsorted data
            for(int j = i; j < data.length; j++){
                if(max < data[j]){
                    max = data[j];
                    maxIndex = j;
                }
            }
            // Swap the largest value with the current index being sorted
            data[maxIndex] = data[i];
            data[i] = max;
        }
    }
}