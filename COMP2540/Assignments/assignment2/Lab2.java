/*
Lab 2
COMP-2540
By: Lucas Sarweh
ID: 110042658 
*/
import java.awt.*;
import java.io.IOException;
import java.util.Random;

public class Lab2
{
    /**
     * Brute force MCS algorithm O(n^2)
     * Finds the maximum contiguous subsequence in an array
     * @param array The array to evaluate
     * @return An integer array containing {value, start index, end index, Iterations}
     */
    public static int[] bruteMCS(int[] array){
        // Initialize max value holder
        int maxSum = 0;
        // Current value holder
        int sum = 0;
        // Start and end indicies of the highest sequence
        int start = -1;
        int end = -1;
        // Track iterations
        int count = 0;
        // Loop through each value of the array
        for(int i = 0; i < array.length; i++){
            // Reset sum each pass
            sum = 0;
            // Loop through each subsequence of the current pass
            for(int j = i; j < array.length; j++){
                // Add next element for each increasing subsequence
                sum += array[j];
                // Greater sum found
                if(sum > maxSum){
                    // Record it's value and location
                    maxSum = sum;
                    start = i;
                    end = j;
                }
                // Increment iteration
                count++;
            }
        }
        // Return result
        return new int[] {maxSum, start, end, count};
    }

    /**
     * Better MCS algorithm O(n)
     * Finds the maximum contiguous subsequence in an array
     * @param array The array to evaluate
     * @return An integer array containing {value, start index, end index, iterations}
     */
    public static int[] goodMCS(int[] array){
        // Start and end indicies of the highest sequence
        int start = -1;
        int end = -1;
        // Max value holder
        int maxSum = 0;
        // Current value holder
        int sum = 0;
        int i = 0;
        // Track iterations
        int count = 0;
        // Loop through sequence starting at i (i only changes when the sum < 0)
        for(int j = 0; j < array.length; j++){
            // Add next element to sequence
            sum += array[j];
            // If the current sequence sum exceeds the current max
            if(sum > maxSum){
                // Make it the new max
                maxSum = sum;
                start = i;
                end = j;
            }
            // If the current sum is less than 0
            if(sum < 0){
                // Make sequence start where j + 1 is
                i = j + 1;
                // Reset sum
                sum = 0;
            }
            // Increment iteration
            count++;
        }
        // Return result
        return new int[] {maxSum, start, end, count};
    }

    /**
     * This prints the 3 result values from the MCS algorithm and the max sequence
     * @param array The sequence to be evaluated
     */
    public static void printMCS(int[] array){
        // Get the results from the algorithm for the given sequence
        int[] results = goodMCS(array);
        // Show the original sequence
        String str = String.format("Given sequence: %d", array[0]);
        for(int i = 1; i < array.length; i++){
            str += String.format(", %d", array[i]);
        }
        // Format string to print results
        str += String.format("\nTotal: %d\n" + "Start: %d\n" + "End: %d\n" 
        + "Iterations: %d\n" + "Sequence: ", results[0], results[1], results[2], results[3]);
        // Make sure there was a sequence found
        if(results[0] != 0){
            // Format to include the max sequence
            str += String.format("%d", array[results[1]]);
            for(int i = results[1] + 1; i <= results[2]; i++){
                str += String.format(", %d", array[i]);
            }
        }
        // Spacing
        str += "\n";
        // Print results
        System.out.println(str);
    }

    /**
     * Prints the 3 result values and the max sequence from the worse MCS algorithm
     * @param array The sequence to be evaluated
     */
    public static void badPrintMCS(int[] array){
        // Get the results from the algorithm for the given sequence
        int[] results = bruteMCS(array);
        // Show the original sequence
        String str = String.format("Given sequence: %d", array[0]);
        for(int i = 1; i < array.length; i++){
            str += String.format(", %d", array[i]);
        }
        // Format string to print results
        str += String.format("\nTotal: %d\n" + "Start: %d\n" + "End: %d\n" 
        + "Iterations: %d\n" + "Sequence: ", results[0], results[1], results[2], results[3]);
        // Make sure there was a sequence found
        if(results[0] != 0){
            // Format to include the max sequence
            str += String.format("%d", array[results[1]]);
            for(int i = results[1] + 1; i <= results[2]; i++){
                str += String.format(", %d", array[i]);
            }
        }
        // Spacing
        str += "\n";
        // Print results
        System.out.println(str);
    }

    /**
     * Generates an integer array with size length with
     * numbers between (-10, 10)
     * @param length Size of the array
     * @return The generated array
     */
    public static int[] randomSequence(int length){
        // New random instance
        Random rand = new Random();
        // New array with given size
        int[] array = new int[length];
        // Populate array with random numbers from (-10, 10)
        for(int i = 0; i < array.length; i++){
            array[i] = rand.nextInt(10) * (rand.nextBoolean() ? 1 : -1);
        }
        // Return array
        return array;
    }

    /**
     * Gives the maximum iterations of 10 random sequences
     * to find the MCS O(n) with given length
     * @param length The length of the sequence
     * @return The max iterations found for that length
     */
    public static int maxIterationsOfLength(int length){
        // Hold current max
        int maxIterations = 0;
        // Hold randomly generated sequence
        int[] sequence;
        // Results of the MCS algorithm
        int[] results;
        // For 10 generated sequences find the highest iterations
        for(int i = 0; i < 10; i++){
            sequence = randomSequence(length);
            results = goodMCS(sequence);
            if(results[3] > maxIterations){
                maxIterations = results[3];
            }
        }
        // Return the max
        return maxIterations;
    }

        /**
     * Gives the maximum iterations of 10 random sequences
     * to find the MCS O(n^2) with given length
     * @param length The length of the sequence
     * @return The max iterations found for that length
     */
    public static int bruteMaxIterationsOfLength(int length){
        // Hold current max
        int maxIterations = 0;
        // Hold randomly generated sequence
        int[] sequence;
        // Results of the MCS algorithm
        int[] results;
        // For 10 generated sequences find the highest iterations
        for(int i = 0; i < 10; i++){
            sequence = randomSequence(length);
            results = bruteMCS(sequence);
            if(results[3] > maxIterations){
                maxIterations = results[3];
            }
        }
        // Return the max
        return maxIterations;
    }

    /**
     * Gives an array containing the max iterations of
     * sequences of length 5 to 15 for the MCS algorithm O(n)
     * @return The array
     */
    public static int[] makeMaxIterationsArray(){
        // Make array to store max values
        int[] maxArray = new int[11];
        // Loop through each length of sequence and get max
        for(int i = 0; i < 11; i++){
            maxArray[i] = maxIterationsOfLength(i + 5);
        }
        // Return the array
        return maxArray;
    }

    /**
     * Gives an array containing the max iterations of
     * sequences of length 5 to 15 for the MCS algorithm O(n^2)
     * @return The array
     */
    public static int[] makeBruteMaxIterationsArray(){
        // Make array to store max values
        int[] maxArray = new int[11];
        // Loop through each length of sequence and get max
        for(int i = 0; i < 11; i++){
            maxArray[i] = bruteMaxIterationsOfLength(i + 5);
        }
        // Return the array
        return maxArray;
    }

    public static void main(String[] args) throws IOException{
        // Check the agorithms
        badPrintMCS(new int[] {-1, -2, -3, -4, -5, -6});
        printMCS(new int[] {-1, -2, -3, -4, -5, -6});

        badPrintMCS(new int[] {-1, 1, -1, 1, -1, 1});
        printMCS(new int[] {-1, 1, -1, 1, -1, 1});

        badPrintMCS(new int[] {-1, 2, 3, -3, 2});
        printMCS(new int[] {-1, 2, 3, -3, 2});

        badPrintMCS(new int[] {1, -5, 2, -1, 3});
        printMCS(new int[] {1, -5, 2, -1, 3});

        badPrintMCS(new int[] {-2, 2, -2, -2, 3, 2});
        printMCS(new int[] {-2, 2, -2, -2, 3, 2});

        // Plotting
        int[] goodMaxArray = makeMaxIterationsArray();
        int[] bruteMaxArray = makeBruteMaxIterationsArray();

        Plot.Data goodMCS = Plot.data();
        Plot.Data linear = Plot.data();
        Plot.Data bruteMCS = Plot.data();
        Plot.Data quadratic = Plot.data();

        for(int x = 5; x <= 15; x++){
            goodMCS.xy(x, goodMaxArray[x - 5]);
            linear.xy(x, x);
            bruteMCS.xy(x, bruteMaxArray[x - 5]);
            quadratic.xy(x, 1 + x * (x + 1) / 2);
        }

        Plot plot = Plot.plot(Plot.plotOpts().
                title("Lab 2 Question 4").
                legend(Plot.LegendFormat.BOTTOM)).
                    xAxis("x", Plot.axisOpts().range(5, 15)).
                    yAxis("y", Plot.axisOpts().range(0, 150)).
                series("y=goodMaxArray[x]", goodMCS, Plot.seriesOpts().color(Color.BLACK).lineWidth(5)).
                series("y=x", linear, Plot.seriesOpts().color(Color.GREEN).lineWidth(2)).
                series("y=bruteMaxArray[x]", bruteMCS, Plot.seriesOpts().color(Color.BLUE)).
                series("y=1+x(x+1)/2", quadratic, Plot.seriesOpts().color(Color.ORANGE));
        
        plot.save("plot", "png");
    }
}