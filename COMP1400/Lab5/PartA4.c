/*
This program takes three inputted numbers
and outputs the max and min.
COMP-1400 Lab 5
Part A - Exercise 4
Developed by: Lucas Sarweh
Version: 1
Date: 25 Oct 2020
*/

// Include standard input/output
#include <stdio.h>

// Main function where program execution starts
int main(void){
    
    // Give a description of the program
    puts("This program takes three numbers and outputs the max and min.\n"
    "--------------------------------------------------------------");

    // Define the three variables for three inputs
    int num1, num2, num3;

    //Prompt the user for 3 integers
    printf("Input three numbers to find the max and min:\n");
    // Get the three integers and store them in memory
    scanf("%d %d %d", &num1, &num2, &num3);
    
    // If statements determine what the max and min are
    // If num1 is the smallest
    if(num1 < num2 && num1 < num3){
        // If num3 is the greatest
        if(num2 < num3){

        // Output the max and min
        printf("The largest number is %d and the smallest number is %d.", num3, num1);
        }
        // If num2 is the greatest
        else{

            // Output the max and min
            printf("The largest number is %d and the smallest number is %d.", num2, num1);
        }
    }
    // If num2 is the smallest
    else if(num2 < num1 && num2 < num3){
        // If num3 is the greatest
        if(num1 < num3){

            // Output the max and min
            printf("The largest number is %d and the smallest number is %d.", num3, num2);
        }
        // If num1 is the greatest
        else{

        // Output the max and min
        printf("The largest number is %d and the smallest number is %d.", num1, num2);
        }
    }
    // If num3 is the smallest
    else{
        // If num2 is the greatest
        if(num1 < num2){

            // Output the max and min
            printf("The largest number is %d and the smallest number is %d.", num2, num3);
        }
        // If num1 is the greatest
        else{

            // Output the max and min
            printf("The largest number is %d and the smallest number is %d.", num1, num3);
        }
    }

    // Exit function using return
    return 0;

}