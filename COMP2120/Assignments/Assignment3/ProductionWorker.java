/*
Assignment 3
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

/**
 * Child of Employee adds a wage and shift type
 */
public class ProductionWorker extends Employee{
    // Fields
    private int shift;
    private double hourlyPay;

    // Methods
    /**
     * No arg constructor initializes fields to zero
     */
    public ProductionWorker(){
        // Initialize all fields to 0 or null
        super();
        shift = 0;
        hourlyPay = 0;
    }

    /**
     * Intialize fields to specified values
     * @param shift 1 or 2 shift corresponds to day or night shift, respectivley
     * @param hourlyPay Pay per hour
     */
    public ProductionWorker(String name, String number, String hireDate, int shift, double hourlyPay){
        // Set the parent fields
        super(name, number, hireDate);
        // Set the fields
        this.shift = shift;
        this.hourlyPay = hourlyPay;
    }

    /**
     * Gets the type of shift 1 or 2
     * @return The type of shift
     */
    public int getShift(){
        // Return the shift
        return shift;
    }

    /**
     * Gets the employees wage
     * @return Wage of employee
     */
    public double getWage(){
        // Return employees wage
        return hourlyPay;
    }

    /**
     * Sets the shift of the employee
     * @param shift Shift to set to
     */
    public void setShift(int shift){
        // Set the shift
        this.shift = shift;
    }

    /**
     * Sets a new wage for the employee
     * @param hourlyPay The new pay to set to
     */
    public void setWage(double hourlyPay){
        // Set the new wage
        this.hourlyPay = hourlyPay;
    }

    public String toString(){
        // Return string of data from this and super
        return super.toString() + "Shift: " + (shift == 1 ? "Day\n" : "Night\n") +
                String.format("Hourly Pay Rate: $%.2f\n", hourlyPay);
    }
}
