/*
Lab 3
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Fri Oct 08 2021
*/

import java.util.Scanner;
// TASK #3 Add the file I/O import statement here
import java.io.*;

/**
   This class reads numbers from a file, calculates the
   mean and standard deviation, and writes the results
   to a file.
*/

public class StatsDemo
{
   // TASK #3 Add the throws clause
   public static void main(String[] args) throws IOException, FileNotFoundException
   {
      double sum = 0;      // The sum of the numbers
      int count = 0;       // The number of numbers added
      double mean = 0;     // The average of the numbers
      double stdDev = 0;   // The standard deviation
      String line;         // To hold a line from the file
      double difference;   // The value and mean difference

      // Create an object of type Scanner
      Scanner keyboard = new Scanner (System.in);
      String filename;     // The user input file name

      // Prompt the user and read in the file name
      System.out.println("This program calculates " +
                         "statistics on a file " +
                         "containing a series of numbers");
      System.out.print("Enter the file name:  ");
      filename = keyboard.nextLine();

      // ADD LINES FOR TASK #4 HERE
      // Create a FileReader object passing it the filename
      FileReader fr = new FileReader("Numbers.txt");
      // Create a BufferedReader object passing FileReader
      // object
      BufferedReader filer = new BufferedReader(fr);
      // Perform a priming read to read the first line of
      // the file
      line = filer.readLine();
      // Loop until you are at the end of the file
      while(line != null){
          // Convert the line to a double value and add the
          // value to sum
          sum += Double.parseDouble(line);
          // Increment the counter
          count++;
          // Read a new line from the file
          line = filer.readLine();
      }
      // Close the input file
      filer.close();
      // Store the calculated mean
      mean = sum / count;

      // ADD LINES FOR TASK #5 HERE
      // Reconnect FileReader object passing it the
      // filename
      FileReader newfr = new FileReader("Numbers.txt");
      // Reconnect BufferedReader object passing
      // FileReader object
      BufferedReader newfiler = new BufferedReader(newfr);
      // Reinitialize the sum of the numbers
      sum = 0;
      // Reinitialize the number of numbers added
      count = 0;
      // Perform a priming read to read the first line of
      // the file
      line = newfiler.readLine();
      // Loop until you are at the end of the file
      while(line != null){
          // Convert the line into a double value and
          // subtract the mean
          difference = Double.parseDouble(line) - mean;
          // Add the square of the difference to the sum
          sum += (difference * difference);
          // Increment the counter
          count++;
          // Read a new line from the file
          line = newfiler.readLine();
      }
      // Close the input file
      newfiler.close();
      // Store the calculated standard deviation
      stdDev = Math.sqrt(sum / count);

      // ADD LINES FOR TASK #3 HERE
      // Create a FileWriter object using "Results.txt"
      FileWriter fw = new FileWriter("Results.txt", true);
      // Create a PrintWriter object passing the
      // FileWriter object
      PrintWriter filew = new PrintWriter(fw);
      // Print the results to the output file
      filew.printf("Mean: %.3f\nStandard Deviation: %.3f\n", mean, stdDev);
      // Close the output file
      filew.close();
   }
}