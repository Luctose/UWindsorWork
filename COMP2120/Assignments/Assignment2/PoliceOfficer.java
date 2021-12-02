/*
Assignment 2
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Nov 14 2021
*/

// ArrayList
import java.util.ArrayList;

/**
 * Simulates a police officer checking for 
 * parking violations
 */
public class PoliceOfficer {
    // Fields
    private int badgeNum; // Police officers badge number
    private String name; // Police officers name
    // Arraylist of ParkingTickets accumulated from all officers
    private static ArrayList<ParkingTicket> tickets = new ArrayList<ParkingTicket>();

    // Methods

    // Constructor
    /**
     * Constructor initializes the name and badgenumber of the officer
     * @param name
     * @param badgeNum
     */
    public PoliceOfficer(String name, int badgeNum){
        // Initialize the fields
        this.name = name;
        this.badgeNum = badgeNum;
    }

    // Accessors
    /**
     * Gets a parking ticket belonging to a specified car
     * @param car The car the parking ticket belongs to
     * @return The parking ticket of the car
     */
    public static ParkingTicket getParkingTicket(ParkedCar car){
        // If the list is empty don't return
        if(tickets.isEmpty()){
            // Return null pointer
            return null;
        }
        // Loop through the list
        for(ParkingTicket ticket : tickets){
            // Comapre the car we are trying to find with the current ticket
            if(ticket.getCar().equals(car)){
                // When found we return its ticket
                return ticket;
            }
        }
        // The car was not found return null
        return null;
    }

    /**
     * Converts the info of the officer to a string
     * @return String containing officer info
     */
    public String toString(){
        // Convert the officers info into the String and return it
        return "Officer Data:\n" + String.format("Name: %s\n", name) + String.format("BadgeNumber: %d\n", badgeNum);
    }

    // Mutators
    /**
     * Officer checks if the car being checked still has time 
     * left on its parking meter and if it doesn't write a new
     * ticket to them
     * @param car The car being evaluated
     * @param meter The meter the car is parked
     * @return True or false for illegally parked or not, respectively
     */
    public boolean isExpired(ParkedCar car, ParkingMeter meter){
        // Compare the cars time parked with the time they paid for
        if(car.getDeltaTime() <= meter.getTimeBought()){
            // The car is not parked illegally
            return false;
        }
        // Create a new ticket
        tickets.add(new ParkingTicket(car, this, meter.getTimeBought()));
        // Return true as the car is parked illegally
        return true;
    }
}
