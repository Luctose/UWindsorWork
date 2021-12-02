/*
Lab 9 (Chapter 11)
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 1 2021
*/

// Import GUI
import javax.swing.JOptionPane;

/**
 * Driver for the SocSecException
 */
public class SocSecProcessor {
    /**
     * Main method of driver
     * @param args
     * @exception SocSecException Thrown when the inputted SSN is invalid
     */
    public static void main(String[] args){
        // user input variables
        String name, ssn;
        // Flag to indicate user wants to continue or exit
        boolean done = false;
        // For JOptionPane
        int reply;

        while(!done){

            // Get the input fromt the user
            name = JOptionPane.showInputDialog(null, "Enter the name: ");
            ssn = JOptionPane.showInputDialog(null, "Enter the SSN: ");
            // Reply to yes by default
            reply = JOptionPane.YES_OPTION;

            // Check for correct format
            try {
                // Check if the SSN is valid
                if(isValid(ssn)){
                    // Repeat the valid info in the output
                    JOptionPane.showMessageDialog(null, name + " " + ssn + " is valid");
                }
            // Invalid input raises an exception
            } catch (SocSecException e) {
                // Show input given and reason
                JOptionPane.showMessageDialog(null, name + " " + ssn + "\n" + e.getMessage());
            } finally {
                // Ask user if they want to continue using Yes or No box window
                reply = JOptionPane.showConfirmDialog(null, "Continue?", "Continue?", JOptionPane.YES_NO_OPTION);
                // Exit loop if they say no
                if(reply == JOptionPane.NO_OPTION){
                    done = true;
                }
            }
        }
        // Exit thread
        System.exit(0);
    }

    /**
     * Checks if the given String is a valid Social Security Number
     * @param ssn The social security number
     * @return True or false, depending on valid or not, respectively
     * @throws SocSecException Wrong social security number format
     */
    public static boolean isValid(String ssn) throws SocSecException{
        // Check SSN length
        if(ssn.length() != 11){
            throw new SocSecException("Wrong number of characters");
        // Check SSN dashes
        }else if(ssn.charAt(3) != '-' || ssn.charAt(6) != '-'){
            throw new SocSecException("Dashes at wrong positions");
        // Check SSN characters
        }else if(hasNonDigit(ssn)){
            throw new SocSecException("Contains a character that is not a digit");
        }
        // No errors return true
        return true;
    }

    /**
     * Helper method checks a String (SSN) for illegal characters
     * @param str String to be checked
     * @return True or false, depending on whether or not it contains illegal characters
     */
    private static boolean hasNonDigit(String str){
        // Loop through String
        for(int i = 0; i < str.length(); i++){
            // If it contains illegal characters
            if(!Character.isDigit(str.charAt(i)) && str.charAt(i) != '-'){
                // Invalid character found
                return true;
            }
        }
        // No invalid character
        return false;
    }
}
