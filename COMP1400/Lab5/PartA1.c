/*
This program computes the remainder
of the division of two numbers.
COMP-1400 Lab 5
Part A - Exercise 1
Developed by: Lucas Sarweh
Version: 1
Date: 25 Oct 2020
*/

// Include standard input/output
#include <stdio.h>

// Main function where program execution starts
int main(void){

    // Introduce what the program does
    puts("This program will calculate the remainder of the\ndivision of two numbers inputted by the user.\n"
    "-----------------------------------------------------------------\n");

    // Define variables needed for program
    int num1, num2;

    // Prompt user for input
    printf("Input the first integer operand: ");
    // Take the input and store it in memory
    scanf("%d", &num1);
    // Prompt user for input
    printf("Input the second integer operand: ");
    // Take the input and store it in memory
    scanf("%d", &num2);

    // Display the desired result to the user
    printf("The remainder of %d divided by %d is %d", num1, num2, num1 % num2);

    // Exit function using return
    return 0;

}