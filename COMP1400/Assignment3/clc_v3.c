/*
A command-line calculator
Assignment 3
Developed by: Lucas Sarweh
Version: 3
Date: 05 Dec 2020
*/

// Include standard input/output
#include <stdio.h>
// Include math
#include <math.h>
// Include standard library
#include <stdlib.h>
// Include string header for advanced operation using variables
#include <string.h>
// Other library
#include <ctype.h>

// Global variables used in all function (The ones the user creates)
double a = 0;
double b = 0;
double c = 0;
double d = 0;
double e = 0;

// Function stores user calculation in static array
int answers(double answer, int recall, int erase){

    // Static array for storage
    static double calcuations[100];
    // Static index for array
    static size_t index = 0;
    // Element for user to choose which answer
    char element;

    // If erase
    if(erase){
        
        // Delete all memory of calculations[]
        index = 0; // I can just do this because everything is dependent on this variable and the array will be overwritten as we go
    }
    // if/else for recalling or new calculation
    else if(recall){
        
        // Say how much memory was used
        printf("%zu answers have been stored.\n", index);
        if(index == 0){
            // Exit function
            return 0;
        }

        // While loop for user to see what has been stored to memory
        do{

            // Prompt user to choose one of the stored answers
            printf("Choose a past answer from 1 to %zu or 0 for every answer.\n"
            "Enter e or E to return to options: ", index);
            // Store answer to memory
            scanf(" %c", &element);
            // Display the desired answer
            if(element == 'E' || element == 'e'){
                // Exit function
                return 0;
            }else{
                // Convert char to int
                element = element - '0';
            }
            if(element < 0 || element > index){

                puts("That is out of range try again.");
            }else if(element == 0){

                // Recall calculations
                for(int i = 0; i < index; i++){

                    printf("[%d]: %lf\n", i + 1, calcuations[i]);
                }
            }else{

                printf("%lf\n", calcuations[element - 1]);
            }
        }while(1);
        
    }else{

        // Store new calculations
        calcuations[index] = answer;
        // Add to index for next 
        index += 1;
    }
    // Return 0
    return 0;
}

// Function prompts and gets user input
char prompt(void){

    char userInput;

    // Give a prompt message
    printf("%s", "-------------------------------------------------------------------\n"
    "Select one of the following items:\n"
    "B) - Binary Mathematical Operations, such as addition and subtraction.\n"
    "U) - Unary Mathematical Operations, such as square root and log.\n"
    "A) - Advanced Mathematical Operations, using variables, arrays.\n"
    "V) - Define variables and assign them values.\n"
    "M) - Select M to see the memory.\n"
    "R) - Select to erase the memory.\n"
    "E) - Exit\n");

    // Gets the user input and stores it into the variable
    scanf(" %c", &userInput);

    // return userInput
    return userInput;
}

// This function returns the highest number
double max(double num1, double num2){

    // Determine which is higher
    if(num1 > num2){
        // Return num1
        return num1;
    }else{
        // Return num2 if num1 isn't higher
        return num2;
    }
}

// This function returns the lowest number
double min(double num1, double num2){

    // Determine which is lower
    if(num1 < num2){
        // Return num1
        return num1;
    }else{
        // Return num2 if num1 isn't lower
        return num2;
    }
}

// Function to calculate binary operations
void binary(void){

    // Define needed variables
    char operator;
    char flush;
    double operandOne, operandTwo;
    int finished = 1;

    // Do while loop for invalid inputs
    while(finished){
        // First get the user input of two operands and an operator
        printf("%s", "Please enter the first number:\n");
        // read input and make sure it is a valid number
        if(scanf("%lf", &operandOne) != 1){

            // scanf fails tell the user you inputted wrong and continue
            puts("That is an invalid input! Try again.");
            // Remove invalid input from input buffer
            while((flush = getchar()) != '\n' && flush != EOF) {}
            continue;
        }
        // Prompt user and input operator
        printf("%s", "Please enter the operation (+, -, *, /, %%, P(for power), X(for maximum), I(for minimum)):\n");
        scanf(" %c", &operator);

        // Second prompt
        printf("%s", "Please enter the second number:\n");
        // read input and make sure it is a valid number
        if(scanf("%lf", &operandTwo) != 1){

            // scanf fails tell the user you inputted wrong and continue
            puts("That is an invalid input! Try again.");
            // Remove invalid input from input buffer
            while((flush = getchar()) != '\n' && flush != EOF) {}
            continue;
        }

        // Switch statement to determine which operation
        switch (operator){

            // Addition
            case '+':
                printf("The result is: %f\n", operandOne + operandTwo);
                answers(operandOne + operandTwo, 0, 0);
                break;
            
            // Subtraction
            case '-':
                printf("The result is: %f\n", operandOne - operandTwo);
                answers(operandOne - operandTwo, 0, 0);
                break;
            
            // Multiplication
            case '*':
                printf("The result is: %f\n", operandOne * operandTwo);
                answers(operandOne * operandTwo, 0, 0);
                break;
            
            // Division
            case '/':
                // Catch division by 0 using an if statement
                if(operandTwo != 0){
                    printf("The result is: %f\n", operandOne / operandTwo);
                    answers(operandOne / operandTwo, 0, 0);
                }else{
                    // Say it cannot be calculated
                    puts("You cannot divide by 0! Try again.");
                    continue;
                }
                break;
            
            // Remainder
            case '%':
                // Catch division by 0 using an if statement
                if(operandTwo != 0){
                printf("The result is: %d\n", (int)operandOne % (int)operandTwo);
                answers((int)operandOne % (int)operandTwo, 0, 0);
                }else{
                    // Say it cannot be calculated
                    puts("You cannot divide by 0! Try again.");
                    continue;
                }
                break;
            
            // Power
            case 'P':
            case 'p':
                printf("The result is: %f\n", pow(operandOne, operandTwo));
                answers(pow(operandOne, operandTwo), 0, 0);
                break;
            
            // Maximum
            case 'X':
            case 'x':
                printf("The result is: %f\n", max(operandOne, operandTwo));
                answers(max(operandOne, operandTwo), 0, 0);
                break;
            
            // Minimum
            case 'I':
            case 'i':
                printf("The result is: %f\n", min(operandOne, operandTwo));
                answers(min(operandOne, operandTwo), 0, 0);
                break;
            
            // Default
            default:
                puts("That was not a valid option!");
                continue;
        }

        // We are done the loop set finished to 0
        finished = 0;

    }
}

// Function to calculate unary operations
void unary(void){
    // Define needed variables
    char operator;
    char flush;
    double operandOne;
    int finished = 1;

    // Do while loop for invalid inputs
    while(finished){

        // Prompt user and input operator
        printf("%s", "Please enter the operation ( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) ):\n");
        scanf(" %c", &operator);

        // Get the operand
        printf("%s", "Please enter a number:\n");
        // read input and make sure it is a valid number
        if(scanf("%lf", &operandOne) != 1 || ((operator == 'S' || operator == 's' || operator == 'L' || operator == 'l') && operandOne < 0)){

            // scanf fails tell the user you inputted wrong and continue
            puts("That is an invalid input! Try again.");
            // Remove invalid input from input buffer
            while((flush = getchar()) != '\n' && flush != EOF) {}
            continue;
        }

        // Switch statement to determine which operation
        switch (operator){

            // Square root
            case 'S':
            case 's':
                printf("The result is: %lf\n", sqrt(operandOne));
                answers(sqrt(operandOne), 0, 0);
                break;
            
            // Logarithm
            case 'L':
            case 'l':
                printf("The result is: %lf\n", log(operandOne));
                answers(log(operandOne), 0, 0);
                break;
            
            // Exponential
            case 'E':
            case 'e':
                printf("The result is: %lf\n", exp(operandOne));
                answers(exp(operandOne), 0, 0);
                break;
            
            // Ceiling
            case 'C':
            case 'c':
                printf("The result is: %lf\n", ceil(operandOne));
                answers(ceil(operandOne), 0, 0);
                break;
            
            // Floor
            case 'F':
            case 'f':
                printf("The result is: %lf\n", floor(operandOne));
                answers(floor(operandOne), 0, 0);
                break;
            
            // Default
            default:
                puts("That was not a valid option!");
                continue;
        }

        // We are done the loop set finished to 0
        finished = 0;
    }
}

// This function defines variables for the user
void variable(void){

    // Variable to store letter user wants defined
    char name;
    // Temporary variable for user input
    double temp;
    // Variable to flush stdin
    char flush;
    // Variable to finish while loop
    int finished = 1;

    while(finished){

        // Prompt user to enter a variable
        printf("%s", "Please enter the name of the variable ( A single character between 'a' to 'e' ):\n");
        //Store input and get don't accept invalid values
        if(scanf(" %c", &name) != 1){

            // Say it was not a character
            printf("%s", "That is not a valid input. Try again.\n");
            // Flush out the stdin
            while((flush = getchar()) != '\n' && flush != EOF) {}
            continue;
        }

        // User input for the value of the variable
        printf("%s", "Please enter the value of the variable:\n");
        //Store input and get don't accept invalid values
        if(scanf(" %lf", &temp) != 1){

            // Say it was not a number
            printf("%s", "That is not a valid input. Try again.\n");
            // Flush out the stdin
            while((flush = getchar()) != '\n' && flush != EOF) {}
            continue;
        }

        // Switch statement to determine which variable
        switch(name){

            // Variable a
            case 'a':
                // Store the chosen number into a
                a = temp;
                break;
            
            // Variable b
            case 'b':
                // Store the chosen number into b
                b = temp;
                break;
            
            // Variable c
            case 'c':
                // Store the chosen number into c
                c = temp;
                break;
            
            // Variable d
            case 'd':
                // Store the chosen number into d
                d = temp;
                break;
            
            // Variable e
            case 'e':
                // Store the chosen number into e
                e = temp;
                break;
            
            // Default
            default:
                // Say the input was invalid
                printf("%s", "That was not a valid input. Try again.");
                continue;

        }

        // We have gone through the switch so we are done the while
        finished = 0;
    }
}

// Advanced binary function
void advancedBinary(void){

    // Define needed variables
    char operator;
    char flush;
    double operandOne, operandTwo;
    char strOne, strTwo;
    int finished = 1;

    // Do while loop for invalid inputs
    while(finished){
        // First get the user input of two operands and an operator
        printf("%s", "Please enter the first number or variable:\n");
        // read input and make sure it is a valid number
        scanf(" %c", &strOne);

        // Check if there are bad inputs
        if(!isdigit(strOne)){

            // See if it is a valid variable
            switch(strOne){

                // Var a
                case 'a':
                    operandOne = a;
                    break;
                
                // Var b
                case 'b':
                    operandOne = b;
                    break;
                
                // Var c
                case 'c':
                    operandOne = c;
                    break;
                
                // Var d
                case 'd':
                    operandOne = d;
                    break;
                
                // Var e
                case 'e':
                    operandOne = e;
                    break;
                
                // Default
                default:
                    puts("That is an invalid input! Try again.");
                    // Remove invalid input from input buffer
                    while((flush = getchar()) != '\n' && flush != EOF) {}
                    continue;
            }
        }else{

            // Input is a digit so just set that digit to operand
            operandOne = (double)strOne;
        }
        
        
        // Prompt user and input operator
        printf("%s", "Please enter the operation (+, -, *, /, %%, P(for power), X(for maximum), I(for minimum)):\n");
        scanf(" %c", &operator);

        // Second prompt
        printf("%s", "Please enter the second number or variable:\n");
        // read input and make sure it is a valid number
        scanf(" %c", &strTwo);

        // Check if there are bad inputs
        if(!isdigit(strTwo)){

            // See if it is a valid variable
            switch(strTwo){

                // Var a
                case 'a':
                    operandTwo = a;
                    break;
                
                // Var b
                case 'b':
                    operandTwo = b;
                    break;
                
                // Var c
                case 'c':
                    operandTwo = c;
                    break;
                
                // Var d
                case 'd':
                    operandTwo = d;
                    break;
                
                // Var e
                case 'e':
                    operandTwo = e;
                    break;
                
                // Default
                default:
                    puts("That is an invalid input! Try again.");
                    // Remove invalid input from input buffer
                    while((flush = getchar()) != '\n' && flush != EOF) {}
                    continue;
            }
        }else{

            // Input is a digit so just set operand to that
            operandTwo = (double)strTwo;
        }

        // Switch statement to determine which operation
        switch (operator){

            // Addition
            case '+':
                printf("The result is: %f\n", operandOne + operandTwo);
                answers(operandOne + operandTwo, 0, 0);
                break;
            
            // Subtraction
            case '-':
                printf("The result is: %f\n", operandOne - operandTwo);
                answers(operandOne - operandTwo, 0, 0);
                break;
            
            // Multiplication
            case '*':
                printf("The result is: %f\n", operandOne * operandTwo);
                answers(operandOne * operandTwo, 0, 0);
                break;
            
            // Division
            case '/':
                // Catch division by 0 using an if statement
                if(operandTwo != 0){
                    printf("The result is: %f\n", operandOne / operandTwo);
                    answers(operandOne / operandTwo, 0, 0);
                }else{
                    // Say it cannot be calculated
                    puts("You cannot divide by 0! Try again.");
                    continue;
                }
                break;
            
            // Remainder
            case '%':
                // Catch division by 0 using an if statement
                if(operandTwo != 0){
                printf("The result is: %d\n", (int)operandOne % (int)operandTwo);
                answers((int)operandOne % (int)operandTwo, 0, 0);
                }else{
                    // Say it cannot be calculated
                    puts("You cannot divide by 0! Try again.");
                    continue;
                }
                break;
            
            // Power
            case 'P':
            case 'p':
                printf("The result is: %f\n", pow(operandOne, operandTwo));
                answers(pow(operandOne, operandTwo), 0, 0);
                break;
            
            // Maximum
            case 'X':
            case 'x':
                printf("The result is: %f\n", max(operandOne, operandTwo));
                answers(max(operandOne, operandTwo), 0, 0);
                break;
            
            // Minimum
            case 'I':
            case 'i':
                printf("The result is: %f\n", min(operandOne, operandTwo));
                answers(min(operandOne, operandTwo), 0, 0);
                break;
            
            // Default
            default:
                puts("That was not a valid option!");
                continue;
        }

        // We are done set while control variable to 0
        finished = 0;
    }
}

// Advanced unary function
void advancedUnary(void){

    // Define needed variables
    char operator;
    char flush;
    double operand;
    char str;
    int finished = 1;

// Do while loop for invalid inputs
    while(finished){

        // Get operator
        printf("%s", "Please enter the operation ( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) ):\n");
        // Store operator
        scanf(" %c", &operator);
        // First get the user input of two operands and an operator
        printf("%s", "Please enter a number or variable:\n");
        // read input and make sure it is a valid number
        scanf(" %c", &str);

        // Check if there are bad inputs
        if(!isdigit(str)){

            // See if it is a valid variable
            switch(str){

                // Var a
                case 'a':
                    operand = a;
                    break;
                
                // Var b
                case 'b':
                    operand = b;
                    break;
                
                // Var c
                case 'c':
                    operand = c;
                    break;
                
                // Var d
                case 'd':
                    operand = d;
                    break;
                
                // Var e
                case 'e':
                    operand = e;
                    break;
                
                // Default
                default:
                    puts("That is an invalid input! Try again.");
                    // Remove invalid input from input buffer
                    while((flush = getchar()) != '\n' && flush != EOF) {}
                    continue;
            }
        }else{

            // Input is a digit so just set that digit to operand
            operand = (double)str;
        }

        // Switch statement to determine which operation
        switch (operator){

            // Square root
            case 'S':
            case 's':
                printf("The result is: %lf\n", sqrt(operand));
                answers(sqrt(operand), 0, 0);
                break;
            
            // Logarithm
            case 'L':
            case 'l':
                printf("The result is: %lf\n", log(operand));
                answers(log(operand), 0, 0);
                break;
            
            // Exponential
            case 'E':
            case 'e':
                printf("The result is: %lf\n", exp(operand));
                answers(exp(operand), 0, 0);
                break;
            
            // Ceiling
            case 'C':
            case 'c':
                printf("The result is: %lf\n", ceil(operand));
                answers(ceil(operand), 0, 0);
                break;
            
            // Floor
            case 'F':
            case 'f':
                printf("The result is: %lf\n", floor(operand));
                answers(floor(operand), 0, 0);
                break;
            
            // Default
            default:
                puts("That was not a valid option!");
                continue;
        }

        // We are done the loop set finished to 0
        finished = 0;
    }
}

// Advanced operation with defined variables
void advanced(void){
    
    // User input variable
    char userInput;
    int done = 1;

    // While to keep doing this
    while(done){
        // Give a prompt message
        printf("%s", "-------------------------------------------------------------------\n"
        "Please select your option ( B (Binary operation), U (Unary operation), E (Exit and back to the main menu))\n");
        scanf(" %c", &userInput);
        // Decide for unary or binary
        switch(userInput){

            // Binary
            case 'B':
            case 'b':
                // Run advanced binary function
                advancedBinary();
                break;
                
            // Unary
            case 'U':
            case 'u':
                // Run advanced unary function
                advancedUnary();
                break;
            
            // Exit
            case 'E':
            case 'e':
                // Exit function
                done = 0;;
        }
    }
}

// This function decides the kind of math the user will do
int decide(char userInput){

    // Decide what kind of operation
    switch(userInput){

        // Binary
        case 'B':
        case 'b':
            // Run binary function
            binary();
            break;
            
        // Unary
        case 'U':
        case 'u':
            // Run unary function
            unary();
            break;
            
        // Advanced
        case 'A':
        case 'a':
            advanced();
            break;
            
        // Variables
        case 'V':
        case 'v':
            // Run variable function
            variable();
            break;
        
        // Past results
        case 'M':
        case 'm':
            answers(0, 1, 0);
            break;
        
        // Erase memory
        case 'R':
        case 'r':
            answers(0, 0, 1);
            break;
            
        // Exit
        case 'E':
        case 'e':
            // Say a goodbye message to the user
            printf("Thank you for using my calculator. Goodbye!\n");
            // Set done to 0 to exit program
            return 0;
            
        // Default (Invalid input)
        default:
            // Tell them it is invalid
            puts("The option you chose is invalid.");
            break;
        }
    // Return 1 to keep going
    return 1;
}

// Main function starts the program
int main(void){

    // Introductory message
    puts("Welcome to my Command-Line Calculator (CLC)\n"
    "Developed by: Lucas Sarweh\n"
    "Version: 3\n"
    "Date: 05 Dec 2020");

    // Define variable that is used to exit loop
    int done = 1;
    
    // Variable that stores user choice
    char userInput;

    // Beggining of main loop
    while(done){

        // Use input function
        userInput = prompt();

        // Logic to decide which operation they chose
        done = decide(userInput);

    }
    // End of loop

    return 0;

    // End of program
}