/*
Lab 4 - Part B - Exercise 7 - C Program
Developed by: Lucas Sarweh
Version: 1
Date: 22 Oct 2020
*/

// Include standard input/output
#include <stdio.h>

// Main function starts the program
int main(void){

    // Variables need for the program
    int num1, num2;

    // Question B)
    // Print my name and my student ID
    printf("Lucas Sarweh,\n110042658\n");

    // Prompt the user to input 2 numbers
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Question A) and C)
    // Print out the answer to four different operations with a box around
    printf("-----------------------------------------------------------------\n"
    "|\t\t\t\t\t\t\t\t|\n|\t\t\t%d + %d = %d\t\t\t\t|\n|\t\t\t%d - %d = %d\t\t\t\t|\n"
    "|\t\t\t%d * %d = %d\t\t\t\t|\n|\t\t\t%d / %d = %d\t\t\t\t|\n|\t\t\t\t\t\t\t\t|\n"
    "-----------------------------------------------------------------\n",
    num1, num2, num1 + num2, num2, num1, num2 - num1, num1, num2, num1 * num2, num1, num2, num1 / num2);
    
    // Return and exit main function
    return 0;

}