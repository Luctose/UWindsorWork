/*
Assignment 2
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Nov 14 2021
*/

// GUI
import javax.swing.JOptionPane;

/**
 * Creates a parking ticket to an illegally parked car 
 * and notes the details of the vehicle and fine 
 * along with the issuing officer
 */
public class ParkingTicket {
    // Fields
    private final int FINE; // The amount charged to an illegally parked car
    private ParkedCar car; // The car that is being issued a ticket
    private PoliceOfficer officer; // The officer issuing the ticket
    private int meter; // The meter paid

    // Methods

    // Constructor
    /**
     * Constructor initializes fields
     * @param car The ParkedCar object being fined
     * @param meter The time the car payed for
     * @param officer The issuing officer
     */
    public ParkingTicket(ParkedCar car, PoliceOfficer officer, int meter){
        // Set the car and officer objects and the time payed on the meter
        this.car = car;
        this.meter = meter;
        this.officer = officer;

        // Calculate the fine taking advantage of integer division
        FINE = 25 + ((this.car.getDeltaTime() - this.meter - 1) / 60) * 10;
    }

    // Accessors
    /**
     * Shows the full details of the car in question 
     * Requires System.exit() before program return
     */
    public void carReport(){
        // Show the details of the car in question
        JOptionPane.showMessageDialog(null, car);
    }

    /**
     * Shows the time the car was parked illegally and the fine 
     * Requires System.exit() before program return
     */
    public void fineReport(){
        // Show the time parked illegally and the fine issued
        JOptionPane.showMessageDialog(null, this);
    }

    /**
     * Shows the info of the officer who issued the ticket 
     * Requires System.exit() before program return
     */
    public void officerDetails(){
        // Show the officer who issued the tickets details
        JOptionPane.showMessageDialog(null, officer);
    }

    /**
     * Shows the full details of the ticket 
     * including the vehicle, fine, and officer 
     * Requires System.exit() before program return
     */
    public void fullDetails(){
        // Show all the details of the ticket
        carReport();
        officerDetails();
        fineReport();
    }

    /**
     * Gets the car associated with the ticket
     * @return ParkedCar object
     */
    public ParkedCar getCar(){
        // Return the car associated with the ticket
        return car;
    }

    /**
     * Sends ticket info into a String
     * @return String containing ticket info
     */
    public String toString(){
        // Return the fields as strings
        return String.format("Minutes Illegally Parked: %d\n", car.getDeltaTime() - meter)
        + String.format("Fine: $%d.00\n", FINE);
    }
}
