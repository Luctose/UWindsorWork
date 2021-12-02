/*
COMP-1400 Midterm
Question 1 - Quadratic
This program will calculate a quadratic function
Developed by: Lucas Sarweh
Version: 1
Date: 14 Nov 2020
*/

// Include standard input/output
#include <stdio.h>

// Main function is where program execution starts
int main(void){

    // Define needed variables a, b, c, and x
    int a, b, c, x;

    // Give a welcome message
    puts("Welcome! This program will calculate the value of\n"
    "a quadratic at any x value.\n"
    "----------------------------------------------------");

    // Prompt the user for input
    printf("Please enter four integer numbers for a, b, c, and x: ");
    // Take users answer and store it in memory
    scanf("%d %d %d %d", &a, &b, &c, &x);

    // If statement to catch a possible overflow for large values of x
    if(x > 40000 || x < -40000){

        // Give an overflow message
        puts("Possible Overflow. Goodbye.");
        
        // Return to exit function
        return 0;
    }

    // Calculate and print the result of ax^2 + bx + c
    printf("Q(%d) = %d * %d^2 + %d * %d + %d = %d", x, a, x, b, x, c, a * (x * x) + (b * x) + c);

    // Return to exit program
    return 0;
}