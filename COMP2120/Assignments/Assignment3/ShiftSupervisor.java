/*
Assignment 3
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

/**
 * Supervisor of the factory production line
 */
public class ShiftSupervisor extends Employee{
    // Fields
    private double salary;
    private double bonus;

    // Methods
    /**
     * No args constructor sets all fields to 0 or null
     */
    public ShiftSupervisor(){
        super();
        this.salary = 0;
        this.bonus = 0;
    }

    /**
     * Initializes all fields to specified values
     * @param name Employee name
     * @param number Employee number
     * @param hireDate Employee hire date
     * @param salary Supervisor salary
     * @param bonus Supervisor bonus
     */
    public ShiftSupervisor(String name, String number, String hireDate, double salary, double bonus){
        super(name, number, hireDate);
        this.salary = salary;
        this.bonus = bonus;
    }

    /**
     * Gets the salary of the supervisor
     * @return The salary
     */
    public double getSalary(){
        // Return their salary
        return salary;
    }

    /**
     * Gets the bonus of the supervisor
     * @return The bonus
     */
    public double getBonus(){
        // Return their bonus
        return bonus;
    }

    /**
     * Sets a new salary for a supervisor
     * @param salary The salary to set to
     */
    public void setSalary(double salary){
        // Set a new salary
        this.salary = salary;
    }

    /**
     * Increases the current salary by the specified amount
     * @param increase The amount to increase by
     */
    public void incSalary(double increase){
        // Increase the current salary
        this.salary += increase;
    }

    /**
     * Sets a new bonus for a supervisor
     * @param bonus Bonus to set to
     */
    public void setBonus(double bonus) {
        // Set the bonus
        this.bonus = bonus;
    }

    /**
     * Increases the bonus by a specified amount
     * @param increase Amount to increment bonus
     */
    public void incBonus(double increase){
        // Increment bonus
        this.bonus += increase;
    }

    public String toString(){
        // String of all data fields
        return super.toString() + String.format("Annual Salary: $%.2f\n", salary) +
                String.format("Production Bonus: $%.2f\n", bonus);
    }
}
