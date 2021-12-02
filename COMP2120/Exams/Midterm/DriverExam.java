/*
Midterm
Lucas Sarweh
ID: 110042658
COMP-2120
Sat Oct 30 2021
*/

import java.util.Scanner;

public class DriverExam {
    // Fields
    private char[] correct = new char[]{'B', 'D', 'A', 'A', 'C',
    'A', 'B', 'A', 'C', 'D'};

    private char[] student = new char[10];

    // Methods

    /**
     * Constructor Gets the answers from the student
     */
    public DriverExam(){
        // Make keyboard Scanner
        Scanner keyboard = new Scanner(System.in);
        // User's answers to be stored
        char answer;
        // Tell user the exam is starting
        System.out.println("Enter your answers to the exam questions.");

        // Ask user for answers stored to student[]
        for(int i = 0; i < 10; i++){
            // Loop until answer is valid
            do{
                // Prompt for input
                System.out.printf("Question %d: ", i + 1);
                // Get answer from student
                answer = ((keyboard.nextLine()).toUpperCase()).charAt(0);
            }while(!(DriverExam.isValid(answer)));
            // After it is valid store it to the students answers
            student[i] = answer;
        }
        // Close Scanner
        keyboard.close();
    }

    /**
     * Returns if the answer is a valid character
     * @param answer The character to be tested
     * @return True or false for valid or not valid
     */
    public static boolean isValid(char answer){
        if(answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D'){
            return true;
        }
        // Tell user it's invalid
        System.out.println("ERROR: Valid answers are A, B, C, or D.");
        return false;
    }

    /**
     * Sees if the student has passed or not
     * @return True or false depending on pass or fail
     */
    public boolean passed(){
        // Keep track of their correct answers
        int grade = 10;
        // Compare each answer
        for(int i = 0; i < 10; i++){
            if(correct[i] != student[i]){
                // Take away a point
                grade -= 1;
            }
        }
        if(grade >= 7){
            // They passed
            return true;
        }else{
            // They failed
            return false;
        }
    }

    /**
     * The total correct questions a student got
     * @return The total correct answers
     */
    public int totalCorrect(){
        // Keep track of total
        int total = 0;

        for(int i = 0; i < 10; i++){
            if(correct[i] == student[i]){
                // Add one to total
                total += 1;
            }
        }
        // Return the total correct
        return total;
    }

    /**
     * The total incorrect questions a student got
     * @return The total incorrect answers
     */
    public int totalIncorrect(){
        // Keep track of total
        int total = 0;

        for(int i = 0; i < 10; i++){
            if(correct[i] != student[i]){
                // Add one to total
                total += 1;
            }
        }
        // Return the total incorrect
        return total;
    }

    /**
     * Returns the questions numbers the student got wrong
     * @return An address to an integer array containing wrong questions
     */
    public int[] questionsMissed(){
        // Make array to store the questions missed
        int[] missed = new int[10];
        // Keep track of index of missed[]
        int index = 0;
        for(int i = 0; i < 10; i++){
            if(correct[i] != student[i]){
                // Save incorrect question
                missed[index] = i + 1;
                index += 1;
            }
        }
        // Return missed questions
        return missed;
    }
}
