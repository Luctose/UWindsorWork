/*
This program will determine if an inputted
number is even or odd.
COMP-1400 Lab 5
Part A - Exercise 2
Developed by: Lucas Sarweh
Version: 1
Date: 25 Oct 2020
*/

// Include standard input/output
#include <stdio.h>

// Main function where program execution starts
int main(void){
    
    // Explain what the program does
    puts("This program will determine if an inputted number is even or odd.\n"
    "--------------------------------------------------------------------");

    // Define needed variables
    int number;

    // Prompt user for an input
    printf("Please enter an integer: ");
    // Store number into memory
    scanf("%d", &number);

    // If statements will decide if the input is even, odd, or invalid
    if (number % 2 == 0){

        // Output the number is even
        printf("The number %d is even.", number);
    }
    else{

        // Output the number is odd
        printf("The number %d is odd.", number);
    }

    // Exit function using return
    return 0;

}