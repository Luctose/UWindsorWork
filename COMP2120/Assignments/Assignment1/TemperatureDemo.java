/*
Assignment 1
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Oct 24 2021
*/

// Import dialogue boxes
import javax.swing.JOptionPane;

/**
 * Testing the Temperature class
 */
public class TemperatureDemo {
    public static void main(String[] args){
        // Get input
        String temp = JOptionPane.showInputDialog("Enter the fahrenheit temperature:");

        // Make sure they didn't press cancel
        if(temp != null && temp.length() > 0){
            // Initialize an instance of the Temperature class
            Temperature demotemp = new Temperature(Double.parseDouble(temp));
            
            // Get the fahrenheit temperature
            // Get the celcius temperature
            // Get the Kelvin temperature
            JOptionPane.showMessageDialog(null, "Fahrenheit: " + String.format("%.2f\n", demotemp.getFahrenheit())
            + "Celcius: " + String.format("%.2f\n", demotemp.getCelcius())
            + "Kelvin: " + String.format("%.2f\n", demotemp.getKelvin()));
            
        }else{
            // Tell them they didn't answer goodbye
            JOptionPane.showMessageDialog(null, "You didn't answer goodbye.");
        }
        // Exit seperate thread
        System.exit(0);
    }
}
