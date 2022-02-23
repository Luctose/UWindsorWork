/*
Lab 1
COMP-2540
By: Lucas Sarweh
ID: 110042658 
*/

import java.util.Scanner;

/**
 * This program takes in 2 integers, m and n,
 * and outputs their greatest common divisor
 */
public class Lab1{
    /**
     * This method finds the greatest common divisor
     * of m and n.
     * @param m First operand
     * @param n Second operand
     * @return The GDC of m and n
     */
    public static int gcd(int m, int n){
        // Remainder variable
        int r = 0;

        // Loop through until m / n has 0 remainder
        while((r = m % n) != 0){
            m = n;
            n = r;
        }
        // Return result
        return n;
    }

    /**
     * This functions gives the iterations it
     * takes to find the GCD
     * @param m First operand
     * @param n Second operand
     * @return Number of iterations
     */
    public static int gcdIterations(int m, int n){
        // Remainder variable
        int r = 0;
        // Keep track of while loop iterations
        int count = 0;

        // Loop through until m / n has 0 remainder
        while((r = m % n) != 0){
            m = n;
            n = r;
            count++;
        }
        // Return iterations
        return count;
    }

    /**
     * This gives the max of two integers
     * @param x First operand
     * @param y Second operand
     * @return The max of x and y
     */
    public static int max(int x, int y){
        // Return the max of the two
        return x >= y ? x : y;
    }

    public static void main(String args[]){
        // Create scanner for standard input
        Scanner input = new Scanner(System.in);
        // Store m and n
        int m, n = 0;

        // Loop until done
        do{
            // Get input from the user
            System.out.print("Enter m: ");
            m = input.nextInt();
            System.out.print("Enter n: ");
            n = input.nextInt();
            // Calculate the GCD and print it out
            System.out.printf("The GCD of m and n is: %d\n", gcd(m, n));
            // Ask if they want to exit
            System.out.println("Do you want to exit? (Y / N): ");

        }while(Character.toUpperCase(input.next().charAt(0)) == 'N');
        // Close Scanner
        input.close();

        // Question 4
        // Initialize array to all 0's
        int maxIterations[] = new int[101];
        for(int i = 0; i < maxIterations.length; i++){
            maxIterations[i] = 0;
        }
        // Loop through possible values of m and n
        for(m = 1; m <= 100; m++){
            for(n = 1; n <= m; n++){
                // This result is used in the graph made using PlotSomeData.java and Plot.java
                maxIterations[n] = max(maxIterations[n], gcdIterations(m, n));
            }
        }
        for(int x = 1; x < maxIterations.length; x++){
            System.out.printf("maxIterations[%d] = %d\n", x, maxIterations[x]);
        }
    }
}