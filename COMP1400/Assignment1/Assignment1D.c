/*
A command-line calculator
Developed by: Lucas Sarweh
Version: 1
Date: 19 Oct 2020
*/

// Include standard input/output
#include <stdio.h>

// Main function starts the program
int main(void){

    // Introductory message
    printf("Welcome to my Command-Line Calculator (CLC)\n"
    "Developed by: Lucas Sarweh\n"
    "Version: 1\n"
    "Date: 19 Oct 2020\n"
    "--------------------------------------------------\n");

    // Define variable that is used to exip loop
    int done = 0;
    
    // Variable that stores user choice
    char user_input = "";

    // Beggining of main loop
    while(done == 0){
        // Prompts user for what they want to do
        printf("Select one of the following items:\n"
        "B) - Binary Mathematical Operations, such as addition and subtraction.\n"
        "U) - Unary Mathematical Operations, such as square root and log.\n"
        "A) - Advanced Mathematical Operations, using variables, arrays.\n"
        "V) - Define variables and assign them values.\n"
        "E) - Exit\n");

        // Gets the user input and stores it into the variable
        scanf("%s", &user_input);

        // if user enters "B"
            // prompt the user for the first number and store it
            // prompt the user for the operation and store it
            // prompt the user for the second number and store it
            // Output the result of num1 and num2 using the specified operator

        // if the user inputs "E"
            // Exit the loop

        // Else user selects any other letter
            // Output that we cannot yet calculate this
            // Go back the the beggining of the loop
    }
    // End of loop

    // Say a goodbye message to the user
    printf("Thank you for using my calculator. Goodbye!");

    // End of program
}