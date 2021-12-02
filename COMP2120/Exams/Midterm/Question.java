/*
Midterm
Lucas Sarweh
ID: 110042658
COMP-2120
Sat Oct 30 2021
*/

import java.util.ArrayList;

public class Question {
    // Fields
    private String question;
    private String ans1;
    private String ans2;
    private String ans3;
    private String ans4;
    private String correct;

    // Methods

    public Question(ArrayList<String> list, int number){
        // Get the question wanted into the Strings
        question = list.get(number);
        ans1 = list.get(number + 1);
        ans2 = list.get(number + 2);
        ans3 = list.get(number + 3);
        ans4 = list.get(number + 4);
        correct = list.get(number + 5);
    }

    public void dispQuestion(){
        // Display the question
        System.out.println(question);
        System.out.println(ans1);
        System.out.println(ans2);
        System.out.println(ans3);
        System.out.println(ans4);
    }

    public String getCorrect(){
        // Return correct answer
        return correct;
    }
}
