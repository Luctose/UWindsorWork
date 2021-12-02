/*
Assignment 2
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Nov 14 2021
*/

/**
 * Simulates a car being issued a parking ticket by an officer
 */
public class ParkingTicketSimulator {
    public static void main(String[] args){
        // Create new instances of all required objects
        ParkedCar car = new ParkedCar("Volkswagen", 1972, "Red", "147RHZM", 125);
        ParkingMeter meter = new ParkingMeter(60);
        PoliceOfficer officer = new PoliceOfficer("Joe Friday", 4788);

        // Check the parked car
        if(officer.isExpired(car, meter)){
            // Now get the ticket from the static ArrayList of all tickets
            // created by all officers and display the info
            PoliceOfficer.getParkingTicket(car).fullDetails();
        }
        // Exit threads opened from JOptionPane
        System.exit(0);
    }
}
