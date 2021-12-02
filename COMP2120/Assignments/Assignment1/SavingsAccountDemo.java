/*
Assignment 1
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Oct 24 2021
*/

// Import dialogue boxes
import javax.swing.JOptionPane;

public class SavingsAccountDemo{
    public static void main(String[] args){
        // List to store user input
        String input[] = {JOptionPane.showInputDialog("Enter the saving's account starting balance:"),
        JOptionPane.showInputDialog("Enter the saving's account annual interest rate:")};
        // Var to store age of account
        int age;
        // Total deposits, withdrawals, and interest amounts
        double totDep = 0;
        double totWith = 0;
        double totInt = 0;
        
        // check to make sure they didn't input nothing or cancelled
        if(input[0] != null && input[1] != null && input[0].length() > 0 && input[1].length() > 0){
            // Initialize the account
            SavingsAccount account = new SavingsAccount(Double.parseDouble(input[0]), Double.parseDouble(input[1]));
            // Ask how old the account is
            input[0] = JOptionPane.showInputDialog("How many months old is the account:");
            // Make sure they didn't input nothing or cancelled
            if(input[0] == null || input[0].length() < 0){
                // Tell user it's exiting
                JOptionPane.showMessageDialog(null, "You did not answer, Goodbye.");
            }else{
                // Set the age of the account
                age = Integer.parseInt(input[0]);
                // Iterate through each month
                for(int i = 0; i < age; i++){
                    // Do-while loop to ensure proper input from user
                    do{
                        // Get input for deposits
                        input[0] = JOptionPane.showInputDialog("Enter amount deposited during month " + String.format("%d", i + 1) + ":");
                        // Get input for withdrawals
                        input[1] = JOptionPane.showInputDialog("Enter amount withdrawn during month " + String.format("%d", i + 1) + ":");

                    }while(input[0] == null || input[0].length() <= 0 || input[1] == null || input[1].length() <= 0);
                    // Apply the deposits and withdrawals given
                    account.deposit(Double.parseDouble(input[0]));
                    totDep += Double.parseDouble(input[0]); // Add to total deposits
                    account.withdraw(Double.parseDouble(input[1]));
                    totWith += Double.parseDouble(input[1]); // Add to total withdrawals
                    // Calculate and add monthly interest
                    totInt += (account.getIntrate() / 12.0) * account.getBal(); // Add to total interest
                    account.compoundInterest();
                }
                // Display the final amounts
                JOptionPane.showMessageDialog(null, "Total deposited: $" + String.format("%.2f", totDep)
                + "\nTotal withdrawn: $" + String.format("%.2f", totWith)
                + "\nInterest earned: $" + String.format("%.2f", totInt)
                + "\nEnding balance: $" + String.format("%.2f", account.getBal()));
            }
        }else{
            // Tell them they didn't input properly and exit
            JOptionPane.showMessageDialog(null, "You did not input goodbye.");
        }

        // Exit thread opened from JOptionPane
        System.exit(0);
    }
}