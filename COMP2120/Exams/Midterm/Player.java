/*
Midterm
Lucas Sarweh
ID: 110042658
COMP-2120
Sat Oct 30 2021
*/

public class Player {
    // Fields
    private int points;

    // Methods
    public Player(){
        // Initialize points to 0
        points = 0;
    }

    public void right(){
        // Got a point right
        points += 1;
    }

    public int getPoints(){
        // Returns points
        return points;
    }
}
