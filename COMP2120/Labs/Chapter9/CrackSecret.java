/*
Lab 8 (Chapter 9)
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Nov 21 2021
*/

// Imports
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/**
 * This class is a driver to crack the secret code from secret.txt
 */
public class CrackSecret {
    public static void main(String[] args) throws FileNotFoundException, IOException{
        // Create connection to file
        BufferedReader file = new BufferedReader(new FileReader("secret.txt"));
        // String array will hold the contents of the file
        String[] line = new String[20];
        // String builder will build the secret message
        StringBuilder secret = new StringBuilder();

        // Split the words into seperate tokens
        line = file.readLine().split(" ");
        // Close the file
        file.close();

        // Append every 5th words 1st character to the secret word starting at the first
        secret.append(Character.toUpperCase(line[0].charAt(0)));
        for(int i = 1; i < line.length; i++){
            if(i % 5 == 0){
                secret.append(Character.toUpperCase(line[i].charAt(0)));
            }
        }
        // Print secret message
        System.out.println(secret);
    }
}
