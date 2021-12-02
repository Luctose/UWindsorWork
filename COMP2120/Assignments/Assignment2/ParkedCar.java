/*
Assignment 2
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Nov 14 2021
*/

/**
 * Stores the information of a parked car and time parked
 */
public class ParkedCar
{
    // Fields
    private String make; // Cars make
    private int model; // Year model
    private String colour; // Colour of the car
    private String licenseNum; // License number
    private int timeParked; // Minutes the car has been parked

    // Methods
    
    // Constructor
    /**
     * Constructor initializes all the fields
     * @param make The make of the car
     * @param model The year model of the car
     * @param colour The colour of the car
     * @param licenseNum The license plate number
     * @param timeParked The time the car was parked
     */
    public ParkedCar(String make, int model, String colour, String licenseNum, int timeParked){
        // Initialize all the fields
        this.make = make;
        this.model = model;
        this.colour = colour;
        this.licenseNum = licenseNum;
        this.timeParked = timeParked;
    }

    // Accessors
    /**
     * Getter that retrieves the make field
     * @return The make of the car
     */
    public String getMake(){
        // Return the make field
        return make;
    }

    /**
     * Getter that retrieves the model field
     * @return The model of the car
     */
    public int getModel(){
        // Return the model of the car
        return model;
    }

    /**
     * Getter that retrieves the colour field
     * @return The colour of the car
     */
    public String getColour(){
        // Return the colour of the car
        return colour;
    }

    /**
     * Getter that retrieves the licenseNum field
     * @return The license plate number of the car
     */
    public String getLicense(){
        // Return the license number of the car
        return licenseNum;
    }

    /**
     * Getter that retrieves the timeParked field
     * @return The time elasped the car has been parked
     */
    public int getDeltaTime(){
        // Return the time the car has been parked
        return timeParked;
    }

    /**
     * Returns all info about the car to a String
     * @return String containing info about the car
     */
    public String toString(){
        // Return the cars info as a string
        return "Car Data:\n" + String.format("Make: %s\n", this.getMake())
        + String.format("Model: %d\n", this.getModel()) + String.format("Colour: %s\n", this.getColour())
        + String.format("License Number: %s\n", this.getLicense()) + String.format("Minutes Parked: %d\n", this.getDeltaTime());
    }

    /**
     * Checks if two ParkedCar objects are the same
     * @param car The ParkedCar being compared against the caller
     * @return True or false for equal or not equal, respectively
     */
    public boolean equals(ParkedCar car){
        // Compare the fields of the two ParkedCar objects
        if(make.equals(car.getMake()) && model == car.getModel() && colour.equals(car.getColour())
        && licenseNum.equals(car.getLicense()) && timeParked == car.getDeltaTime()){
            // Then this ParkedCar is the same as the calling one
            return true;
        }
        // They are not the same
        return false;
    }
}