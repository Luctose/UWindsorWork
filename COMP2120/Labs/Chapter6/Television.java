/*
Lab 5 (Chapter 6)
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Oct 31 2021
*/

/**
 * The purpose of this class is to model a television
 * Lucas Sarweh 10/31/2021
 */
public class Television {
    // Fields
    private final String MANUFACTURER; // Manufacturer of the TV
    private final int SCREEN_SIZE; // The size of the TV
    private boolean powerOn; // True or false representing the on or off state
    private int channel; // The current channel
    private int volume; // The volume of the TV, 0 being low and 100 being high

    // Methods

    /**
     * Constructor initializes the fields
     * @param brand The manufacturer of the TV
     * @param size The size of the TV
     */
    public Television(String brand, int size){
        // Set the constant tv attributes
        MANUFACTURER = brand;
        SCREEN_SIZE = size;

        // Initialize variables
        powerOn = false;
        channel = 2;
        volume = 20;
    }

    /**
     * Sets the tv's channel
     * @param ch Channel to be changed to
     */
    public void setChannel(int ch){
        // Set the channel
        channel = ch;
    }

    /**
     * Switches the power from off to on or vice-versa
     */
    public void power(){
        // Set the power to the opposite
        powerOn = !powerOn;
    }

    /**
     * Increment volume by one
     */
    public void increaseVolume(){
        // Increase volume
        volume++;
    }

    /**
     * Decrement volume by one
     */
    public void decreaseVolume(){
        // Decrease volume
        volume--;
    }

    /**
     * Gives the current channel
     * @return Current channel
     */
    public int getChannel(){
        // Return the channel
        return channel;
    }

    /**
     * Gives the current volume
     * @return Current volume
     */
    public int getVolume(){
        // Return the volume
        return volume;
    }

    /**
     * Gives the manufacturer of the tv
     * @return The manufacturer
     */
    public String getManufacturer(){
        // Return the manufacturer
        return MANUFACTURER;
    }

    /**
     * Gives the tv's screen size
     * @return The screen size
     */
    public int getScreenSize(){
        // Return the screen size
        return SCREEN_SIZE;
    }
}
