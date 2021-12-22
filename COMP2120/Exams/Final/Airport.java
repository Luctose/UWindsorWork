import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

/*
Final Exam
Lucas Sarweh
ID: 110042658
COMP-2120
Dec 17 2021
*/

/**
 * This class manages an airports airplanes
 */
public class Airport
{
    // Fields
    Queue<String> waitTakeoff;
    Queue<String> waitLand;
    ArrayList<String> alreadyLT;

    /**
     * Initialize instance variables
     */
    public Airport(){
        waitTakeoff = new LinkedList<>();
        waitLand = new LinkedList<>();
        alreadyLT = new ArrayList<>();
    }

    /**
     * Adds a plane to the take off queue
     * @param number
     */
    public void addTakeOff(String number){
        waitTakeoff.add(number);
    }

    /**
     * Adds a plane to the land queue
     * @param number
     */
    public void addLanding(String number){
        waitLand.add(number);
    }

    public String handleNextAction(){
        if(waitLand.size() > 0){
            alreadyLT.add("Flight " + waitLand.peek() + " landed.\n");
            return "Flight " + waitLand.remove() + " is landing.";
        }else if(waitTakeoff.size() > 0){
            alreadyLT.add("Flight " + waitTakeoff.peek() + " taken-off.\n");
            return "Flight " + waitTakeoff.remove() + " is taking off.";
        }
        return "No plane is waiting to land or take-off.";
    }

    public String waitingPlanes(){
        String string = "";
        if(waitTakeoff.size() <= 0 && waitLand.size() <= 0){
            return "No plane is in the landing and take-off queues.";
        }
        else if(waitTakeoff.size() > 0){
            string = string + "Planes waiting for take-off\n---------------------------\n";
            for(String i : waitTakeoff){
                string = string + i + "\n";
            }
        }else if(waitLand.size() > 0){
            string = string + "Planes waiting for landing\n---------------------------\n";
            for(String j : waitLand){
                string = string + j + "\n";
            }
        }
        return string;
    }

    public String log(){
        if(alreadyLT.size() <= 0){
            return "No activity exists.";
        }
        String string = "List of the landing/take-off activities\n---------------------------------------\n";
        for(String i : alreadyLT){
            string = string + i;
        }
        return string;
    }

    public void log(String filename) {
        String string = "List of the landing/take-off activities\n---------------------------------------\n";
        for(String i : alreadyLT){
            string = string + i;
        }
        try{
            System.out.println("Writing the airport log to the file...");
            FileWriter f = new FileWriter(filename);
            f.write(string);
            System.out.println("Done");
            f.close();
        }catch(IOException e){
            System.out.println(e.getMessage());
        }
    }
}
