/*
Assignment 2
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Nov 14 2021
*/

/**
 * Acts as a parking meter
 */
public class ParkingMeter {
    // Fields
    private int timeBought; // Time a car is allowed to park

    // Methods

    // Constructor
    public ParkingMeter(int timeBought){
        // Set the time bought
        this.timeBought = timeBought;
    }
    // Accessors
    /**
     * Getter retrieves the time that was bought on the meter
     * @return The time amount of time a car bought at the meter
     */
    public int getTimeBought(){
        // Return the time bought
        return timeBought;
    }
}
