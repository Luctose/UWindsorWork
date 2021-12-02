/*
This program will display the multiplication
table of an inputted number
COMP-1400 Lab 6
Exercise 4
Developed by: Lucas Sarweh
Version: 1
Date: 2 Nov 2020
*/

// Include standard input/output
#include <stdio.h>

// Program execution starts at main
int main(void){

    // Define variables
    int number, i;

    // Welcome message
    puts("Welcome! This program will display the multiplication\n"
    "table of an inputted number.\n"
    "--------------------------------------------------------");

    // Prompt user for input
    printf("Please input an integer: ");

    // Store input to memory
    scanf("%d", &number);

    // Loop to calculate and output the table and it's values
    for(i = 1; i <= 10; i++){
        printf("%d X %d = %d\n", number, i, number * i);
    }
}