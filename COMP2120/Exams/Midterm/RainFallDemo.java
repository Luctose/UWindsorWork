/*
Midterm
Lucas Sarweh
ID: 110042658
COMP-2120
Sat Oct 30 2021
*/

public class RainFallDemo {
    /**
     * The main method is where execution starts
     */
    public static void main(String[] args){
        // Make a new RainFall class
        RainFall rain = new RainFall();

        // Give some statistics
        // Total annual rainfall
        System.out.printf("The total rainfall for this year is %.1f\n", rain.totAnnualRain());

        // Average rainfall
        System.out.printf("The average rainfall for this year is %.16f\n", rain.avgMonthlyRain());

        // Highest rain month
        System.out.printf("The month with the highest amount of rain is %d with %.1f inches.\n", rain.mostIndex() + 1, rain.mostRain());

        // Lowest rain month
        System.out.printf("The month with the lowest amount of rain is %d with %.1f inches.\n", rain.leastIndex() + 1, rain.leastRain());
    }
}
