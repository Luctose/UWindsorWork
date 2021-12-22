/*
Assignment 3
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

/**
 * Team leader of the production line
 */
public class TeamLeader extends ProductionWorker{
    // Fields
    private final double bonus;
    private double reqHours;
    private double takenHours;

    // Methods
    /**
     * No arg constructor sets all fields to 0 or null
     */
    public TeamLeader(){
        super();
        bonus = 0;
        reqHours = 0;
        takenHours = 0;
    }

    public TeamLeader(String name, String number, String hireDate, int shift, double hourlyPay, 
                    double bonus, double reqHours, double takenHours){
        // Assign all fields
        super(name, number, hireDate, shift, hourlyPay);
        this.bonus = bonus;
        this.reqHours = reqHours;
        this.takenHours = takenHours;
    }

    /**
     * Gets the TeamLeaders bonus
     * @return Monthly bonus
     */
    public double getBonus(){
        // Return their monthly bonus
        return bonus;
    }

    /**
     * Gets TeamLeader's required training hours
     * @return Required training hours
     */
    public double getReqHours(){
        // Return reqHours
        return reqHours;
    }

    /**
     * Gets TeamLeader's taken training hours
     * @return Required training hours taken
     */
    public double getTakenHours(){
        // Return takenHours
        return takenHours;
    }

    /**
     * Increase training hours taken
     * @param hours Hours to be added
     */
    public void incHours(double hours){
        // Increase taken hours
        takenHours += hours;
    }

    public String toString(){
        // Return the data fields as String
        return super.toString() + String.format("Monthly Bonus: $%.2f\n", bonus) +
        String.format("Required Training Hours: %.1f\n", reqHours) +
        String.format("Training Hours Attended: %.1f\n", takenHours);
    }
}
