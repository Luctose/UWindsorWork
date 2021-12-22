/*
Assignment 3
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

/**
 * Demo for the TeamLeader class
 */
public class TeamLeaderDemo {
    public static void main(String[] args){
        // "Hire" new team leaders
        TeamLeader leader1 = new TeamLeader("John Smith", "123-A", "11-15-2005", 1, 16.50, 500.00, 5.0, 2.5);
        TeamLeader leader2 = new TeamLeader("Joan Jones", "222-L", "12-12-2005", 2, 18.50, 600.00, 7.0, 3.5);

        // Print the team leader's info

        System.out.println("Here's the first team leader.\n" + leader1);
        System.out.println("Here's the second team leader.\n" + leader2);
    }
}
