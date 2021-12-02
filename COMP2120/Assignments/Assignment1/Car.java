/*
Assignment 1
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Oct 24 2021
*/

/**
 * Car instances record the model and make of a car and
 * allow to car to accelerate and brake
 */
public class Car {
    // Declaring fields
    private int yearModel; // Car's year model
    private String make; // Make of the car
    private int speed; // Speed of the car

    /**
     * Constructor initializes the fields of the new instance
     * @param model The car's year model
     * @param makeinit The car's make
     */
    public Car(int model, String makeinit){
        // Initialize fields
        yearModel = model;
        make = makeinit;
        speed = 0;
    }

    /**
     * Accessor for the field yearModel
     * @return The car's yearModel
     */
    public int getYearModel(){
        // Return the object's yearModel
        return yearModel;
    }

    /**
     * Accessor for the field make
     * @return The car's make
     */
    public String getMake(){
        // Return the object's make
        return make;
    }

    /**
     * Accessor for the field speed
     * @return The car's speed
     */
    public int getSpeed(){
        // Return the object's speed
        return speed;
    }

    /**
     * Mutator for the field speed that speeds up the car
     */
    public void accelerate(){
        // Accelerate the car
        speed += 5;
    }

    /**
     * Mutator for the field speed that slows down the car
     */
    public void brake(){
        // Slow down the car
        speed -= 5;
    }
}
