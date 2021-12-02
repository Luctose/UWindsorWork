/*
This program gets an integer from the user
and will display a right triangle pattern
based on the integer inputted
COMP-1400 Lab 6
Exercise 3
Developed by: Lucas Sarweh
Version: 1
Date: 2 Nov 2020
*/

// Include the standard input/output
#include <stdio.h>

// Program execution starts at main function
int main(void){

    // Define needed variable
    int number;

    // Welcome message and prompt
    printf("Welcome! This program will display a pattern\n"
    "Depending on the number you input\n"
    "-------------------------------------------------\n"
    "Please enter the number of rows: ");

    // Store input into memory
    scanf("%d", &number);

    // This will print an n * n right triangle
    // For every row
    for(int i = 1; i <= number; i++){
        // Print a number of asterisks depending on the number of rows
        for(int h = 1; h <= i; h++){

            // Output an asterisk
            printf("*");
        }
        // Newline for next row
        puts("");
    }
}