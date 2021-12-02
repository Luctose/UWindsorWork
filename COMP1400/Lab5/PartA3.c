/*
This program determines if an inputted
number is a leap year or not.
COMP-1400 Lab 5
Part A - Exercise 3
Developed by: Lucas Sarweh
Version: 1
Date: 25 Oct 2020
*/

// Include standard input/output
#include <stdio.h>

// Main function where program execution starts
int main(void){
    
    // Define needed variable
    int year;

    // Give a message of what this program does
    puts("This program determines if an inputted year is a leap year.\n"
    "------------------------------------------------------------");

    // Prompt user for a year
    printf("Please enter a year: ");
    // Take the inputted year and store it in memory
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0)){

        // Output the year entered is a leap year
        printf("The year %d is a leap year.", year);
    }
    else{

        // Output the year entered is not a leap year
        printf("The year %d is not a leap year", year);
    }

    // Exit function using return
    return 0;

}