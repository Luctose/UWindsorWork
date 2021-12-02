/*
Assignment 1
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Oct 24 2021
*/

// Import Message dialogue boxes
import javax.swing.JOptionPane;

/**
 * Tests the Car class
 */
public class CarDemo {
    public static void main(String[] args){
        // Create an instance of a car
        Car porsche = new Car(2004, "Porsche");
        // Print the status
        JOptionPane.showMessageDialog(null, "Current status of the car:\n" +
        "Year model: " + String.format("%d\n", porsche.getYearModel()) +
        "Make: " + porsche.getMake() +
        "\nSpeed: " + String.format("%d\n", porsche.getSpeed()));

        JOptionPane.showMessageDialog(null, "Accelerating...");
        // Accelerate 5 times
        for(int i = 0; i < 5; i++){
            porsche.accelerate();
        }
        // Show it's speed
        JOptionPane.showMessageDialog(null, "Now the speed is " + String.format("%d\n", porsche.getSpeed()));

        JOptionPane.showMessageDialog(null, "Braking...");
        // Brake 5 times
        for(int i = 0; i < 5; i++){
            porsche.brake();
        }
        // Shows it's speed
        JOptionPane.showMessageDialog(null, "Now the speed is " + String.format("%d\n", porsche.getSpeed()));

        // Exit thread
        System.exit(0);
    }
}
