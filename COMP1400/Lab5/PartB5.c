/*
This program intakes the first twelve
ISBN-13 and outputs the check digit.
COMP-1400 Lab 5
Part B - Exercise 5
Developed by: Lucas Sarweh
Version: 1
Date: 25 Oct 2020
*/

// Include standard input/output
#include <stdio.h>

// Main function where program execution starts
int main(void){
    
    // Define needed variables
    int digits[11]; // Array for stroing ISBN-13
    const int MAX = 12; // Constant of length of array
    int i; // keeps track of array index in for loop
    int sum = 0; // Stores results from arrays

    // Description of program
    puts("This program gets the first 12 digits of ISBN-13\n"
    "and outputs the check digit.\n"
    "---------------------------------------------------");

    // Prompt user for an input
    printf("Input the first twelve digits of an ISBN-13: ");
    // Store the inputs into memory
    scanf("%1d %1d %1d %1d %1d %1d %1d %1d %1d %1d %1d %1d", &digits[0], &digits[1], &digits[2], &digits[3],
    &digits[4], &digits[5], &digits[6], &digits[7], &digits[8], &digits[9], &digits[10], &digits[11]);

    // Loop through each element of array
    // Alternate between multiplaying by 1 and 3
    // and add each result to sum
    for (i = 0; i < MAX; i++){
        if(i % 2 == 0){
            sum += digits[i];
        }
        else{
            sum += (3 * digits[i]);
        }
    }

    // Get remainder of sum / 10
    sum = sum % 10;

    // Subtract sum from 10 to get the check digit
    sum = 10 - sum;

    printf("Check digit: %d", sum);

    // Exit function using return
    return 0;

}