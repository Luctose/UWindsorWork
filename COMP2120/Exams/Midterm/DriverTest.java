/*
Midterm
Lucas Sarweh
ID: 110042658
COMP-2120
Sat Oct 30 2021
*/

public class DriverTest {
    /**
     * Where the execution starts
     * @param args Input from OS
     */
    public static void main(String[] args){
        // Create DriverExam object whos constructor asks for input
        DriverExam test = new DriverExam();

        // Show correct answers
        System.out.printf("Correct answers: %d\n", test.totalCorrect());
        // Show incorrect answers
        System.out.printf("Incorrect answers: %d\n", test.totalIncorrect());

        // Say if they passed or failed
        if(test.passed() == true){
            System.out.println("You passed the exam.");
        }else{
            System.out.println("You failed the exam.");
        }

        // Get questions they missed
        int[] missedQ;
        missedQ = test.questionsMissed();

        // Show what questions they missed
        System.out.println("You missed the following questions:");
        for(int i = 0; i < 10; i++){
            if(missedQ[i] > 0){
                System.out.printf("%d ", missedQ[i]);
            }
        }
    }
}
