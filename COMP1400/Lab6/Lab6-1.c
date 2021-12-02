/*
This program will read 10 integers from
the user and find their sum and average
COMP-1400 Lab 6
Exercise 1
Deveolped by: Lucas Sarweh
Version: 1
Date: Nov 1 2020
*/

// Include standard input/output
#include <stdio.h>

// Program execution begins in main function
int main(void){

    // Define needed variables sum (adding input),
    // i (tracking for loop), read (temp. stores inputs),
    // average (float to store the average with greater precision)
    int sum, i, read;
    float average;

    // Prompt for numbers outside loop
    puts("Enter 10 integers\n"
    "---------------------------------");

    // Loop will get ask and store each of the 10 integers
    for(i = 1; i <= 10; i++){

        // Ask user for integer 1-10
        printf("Integer %d: ", i);

        // store input temporarily
        scanf("%d", &read);

        // Add the input to the sum
        sum += read;
    }

    // Calculate the average of the 10 numbers
    average = sum / 10.0;
    
    // Print out the result (The sum and average)
    printf("The sum of the numbers is %d\n"
    "---------------------------------\n"
    "The average of the numbers is %.1f\n", sum, average);
}