/*
Assignment 1
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Oct 24 2021
*/

/**
 * Temperature conversions between C, F and K
 */
public class Temperature {
    // Temperature in fahrenheit
    private double ftemp;

    /**
     * Constructor of Temperature initializing the field ftemp
     * @param temp temperature in fahrenheit
     */
    public Temperature(double temp){
        // Set the given temperature into the ftemp field
        ftemp = temp;
    }

    /**
     * Sets the fahrenheit temperature into ftemp
     * @param temp Double fahrenheit temperature
     */
    public void setFahrenheit(double temp){
        // Set ftemp using parameter
        ftemp = temp;
    }

    /**
     * Access the ftemp field
     * @return A temperature in degrees fahrenheit
     */
    public double getFahrenheit(){
        // Return the fahrenheit temperature
        return ftemp;
    }

    /**
     * Access the ftemp field and return it in degrees celcius
     * @return Temperature in degrees celcius
     */
    public double getCelcius(){
        // Return the celcius temperature
        return (5.0 / 9.0) * (ftemp - 32);
    }

    /**
     * Access the ftemp field and return it in kelvin
     * @return Temperature in kelvin
     */
    public double getKelvin(){
        // Return the kelvin temperature
        return (5.0 / 9.0) * (ftemp - 32) + 273;
    }
}
