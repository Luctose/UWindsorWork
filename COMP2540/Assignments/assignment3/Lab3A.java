/*
Lab 3
COMP-2540
By: Lucas Sarweh
ID: 110042658 
*/

import java.util.Scanner;

/**
 * Input string with brackets and it will tell you if it's balanced
 */
public class Lab3A
{
    public static String validBracketStack(String input){
        // Create new Stack instance
        StackInterface stack = new MyStack(input.length());
        // Loop through the string
        for(int i = 0; i < input.length(); i++){
            if(input.charAt(i) == '(' && !stack.isFull()){ // Push to the bracket stack
                stack.push("(");
            }else if(input.charAt(i) == ')' && !stack.isEmpty()){ // Pop the bracket stack
                stack.pop();
            }else if(input.charAt(i) != '(' && input.charAt(i) != ')'){ // Do nothing when it's not a character we care about

            }else{ // When there's an issue
                return "Mismatched bracket at position " + (i + 1);
            }
        }
        // Check if the stack is empty
        if(stack.isEmpty()){
            // The brackets are balanced
            return "All brackets matched";
        }
        // Stack is not empty so the brackets are not balanced
        return "Mismatched bracket at position " + input.length();
    }

    public static void main(String[] args){
        // Initialize Scanner
        Scanner keyboard = new Scanner(System.in);
        // String holder
        String input;
        do{
            // Get input
            System.out.println("Input brackets (Hit enter to exit): ");
            input = keyboard.nextLine();
            // Check the bracket stack and print the result
            System.out.println(validBracketStack(input));
        }while(!input.isEmpty()); // Type nothing to exit
        // Close resources
        keyboard.close();
    }
}