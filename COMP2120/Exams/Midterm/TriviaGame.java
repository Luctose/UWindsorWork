/*
Midterm
Lucas Sarweh
ID: 110042658
COMP-2120
Sat Oct 30 2021
*/

import java.util.ArrayList;
import java.util.Scanner;
import java.io.*;

public class TriviaGame {
    public static void main(String[] ags){
        // First open the trivia file
        File file = new File("trivia.txt");
        // Make a scanner with the file as a parameter
        Scanner info = new Scanner(file);

        // New ArrayList
        ArrayList<String> quest = new ArrayList<String>();

        // Extract info from text file
        while(info.hasNext()){
            quest.add(info.nextLine());
        }

        // Creat an ArrayList of questions
        ArrayList<Question> questions = new ArrayList<Question>();

        // Initialize the ArrayList of questions based on the trivia file
        for(int i = 0; i < (quest.size() / 6); i++){
            questions.add(new Question(quest, i * 6));
        }

        // Initialize players
        Player one = new Player();
        Player two = new Player();

        // Scanner for input
        Scanner keyboard = new Scanner(System.in);
        int guess = 0;

        for(int count = 1; count - 1 < questions.size(); count++){
            if(count % 2 == 1){ // Player 1
                System.out.println("Questions for player 1:");
                // Display question
                questions.get(count - 1).dispQuestion();
                System.out.print("Enter the number of the correct answer: ");
                guess = keyboard.nextInt();
                if(guess == Integer.parseInt(questions.get(count - 1).getCorrect())){
                    System.out.println("Correct!");
                    one.right();
                }else{
                    System.out.printf("Incorrect. The answer was %d\n", Integer.parseInt(questions.get(count - 1).getCorrect()));
                }

            }else{ // Player 2
                System.out.println("Questions for player 2:");
                // Display question
                questions.get(count - 1).dispQuestion();
                System.out.print("Enter the number of the correct answer: ");
                guess = keyboard.nextInt();
                if(guess == Integer.parseInt(questions.get(count - 1).getCorrect())){
                    System.out.println("Correct!");
                    two.right();
                }else{
                    System.out.printf("Incorrect. The answer was %d\n", Integer.parseInt(questions.get(count - 1).getCorrect()));
                }

            }
        }
        System.out.println("Game Over!");
        System.out.printf("Player 1's points: %d\n", one.getPoints());
        System.out.printf("Player 2's points: %d\n", two.getPoints());

        if(one.getPoints() > two.getPoints()){
            System.out.println("Player 1 wins!");
        }else{
            System.out.println("Player 2 wins!");
        }
    }
}
