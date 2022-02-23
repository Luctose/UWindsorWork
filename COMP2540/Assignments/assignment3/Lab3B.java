/*
Lab 3
COMP-2540
By: Lucas Sarweh
ID: 110042658 
*/

import java.util.Scanner;
import java.util.regex.*;

/**
 * Post-fix calculator
 */
public class Lab3B {

    public static void postCalc(Scanner keyboard){
        // String holder
        String input;
        // Stack to track items
        StackInterface stack = new MyStack(100);
        // Regex, accept integers, +, -, *, and =
        Pattern accept = Pattern.compile("(\\-?\\d+)|[\\*\\+\\-]");
        Pattern integer = Pattern.compile("\\-?\\d+");
        Matcher match;
        // Temp variable
        Integer temp = 0;
        // Flag for invalid expression
        boolean invalid = false;
        // Prompt the user
        System.out.println("Enter expression with one item per line:");
        // Loop for each input
        do{
            // Get input
            input = keyboard.nextLine();
            // Make a Matcher object based off the input
            match = accept.matcher(input);
            if(match.matches()){ // If they match use the info
                if(integer.matcher(input).matches()){ // If it's an operand
                    if(stack.size() < 100){ // Check if there's enough space
                        // Push the operand to the stack
                        stack.push(Integer.parseInt(input));
                    }else{ // Not neccesarily invalid just not enough dedicated memory
                        invalid = true;
                        System.out.print("Expression too large, ");
                    }
                }else{ // If it's an operator
                    if(stack.size() > 1){ // Atleast 2 to use an operator
                        switch(input){
                            case "+": // Addition operator
                            temp = (Integer)stack.pop();
                            temp = (Integer)stack.pop() + temp;
                            stack.push(temp);
                            break;
                            case "-": // Subtraction operator
                            temp = (Integer)stack.pop();
                            temp = (Integer)stack.pop() - temp;
                            stack.push(temp);
                            break;
                            case "*": // Multiplication operator
                            temp = (Integer)stack.pop();
                            temp = (Integer)stack.pop() * temp;
                            stack.push(temp);
                            break;
                            default: // This should never be reached
                            System.out.print("Default reached, error, ");
                        }
                    }else{ // Invalid expression
                        invalid = true;
                        System.out.print("Not enough operands to perform operator, ");
                    }
                }
            }else if(!input.equals("=")){ // Invalid input
                System.out.println("Not a valid operand or operator, try again.\n(This attempt will not be considered)");
            }
        }while(!input.equals("=") && invalid == false); // Equal sign and invalid expression ends loop

        // Make sure there is only one on the stack left
        if(stack.size() != 1 && invalid == false){
            invalid = true;
            System.out.println("Too many operands, ");
        }

        // If an invalid flag was caught abort
        if(invalid == true){
            System.out.println("Abort.");
        }else{ // Everything is OK
            // Output result
            System.out.println((Integer)stack.pop());
        }
    }

    public static void main(String[] args){
        // Scanner to try again
        Scanner input = new Scanner(System.in);
        do{
            // Do post-fix calcualtor
            postCalc(input);
            // Ask if they want to try again
            System.out.print("Do you want to try again? (Y / N): ");
        }while(input.nextLine().equalsIgnoreCase("Y")); // Exit on Yes
        // Close Scanner
        input.close();
    }
}
