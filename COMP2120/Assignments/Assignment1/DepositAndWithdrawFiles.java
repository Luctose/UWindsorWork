/*
Assignment 1
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Oct 24 2021
*/

// Import ArrayList
import java.util.ArrayList;
// Import Scanner
import java.util.Scanner;
// Import input / output
import java.io.*;
// Import dialogue boxes
import javax.swing.JOptionPane;

public class DepositAndWithdrawFiles {
    public static void main(String[] args) throws IOException{
        // Get interest from user
        String input = JOptionPane.showInputDialog("Enter the accounts interest rate:");
        // Check for proper input
        if(input != null && input.length() > 0){
            // Initialize the account object
            SavingsAccount account = new SavingsAccount(500.00, Double.parseDouble(input));
            // Open file holding the deposits and withdrawals
            File newfile = new File("Deposits.txt");
            File newerfile = new File("Withdrawals.txt");

            // Make scanners
            Scanner depositScan = new Scanner(newfile);
            Scanner withdrawScan = new Scanner(newerfile);

            // Make array list for storage
            ArrayList<Double> deposits = new ArrayList<Double>();
            ArrayList<Double> withdrawals = new ArrayList<Double>();

            // Populate the array for deposits
            while(depositScan.hasNext()){
                deposits.add(depositScan.nextDouble());
            }
            // Populate the array for withdrawals
            while(withdrawScan.hasNext()){
                withdrawals.add(withdrawScan.nextDouble());
            }
            // Close scanner
            depositScan.close();
            withdrawScan.close();

            // Add the deposits to the account
            for(double val : deposits){
                account.deposit(val);
            }
            // Add the withdrawals to the account
            for(double val : withdrawals){
                account.withdraw(val);
            }
            
            // Show interest
            JOptionPane.showMessageDialog(null, "Interest earned: $" + String.format("%.2f", (account.getIntrate() / 12.0) * account.getBal()));
            // Add interest to bal
            account.compoundInterest();
            // Show balance
            JOptionPane.showMessageDialog(null, "Ending balance: $" + String.format("%.2f", account.getBal()));

        }else{
            // Invalid input, exit
            JOptionPane.showMessageDialog(null, "No input, goodbye.");
        }
        // Exit thread
        System.exit(0);
    }
}
