/*
COMP-1400 Midterm
Question 3 - Equality
This program determines if two numbers
are equal based on Alice's definition
Developed by: Lucas Sarweh
Version: 1
Date: 14 Nov 2020
*/

// Include standard input/output
#include <stdio.h>

// Main function is where program execution starts
int main(void){

    // Introduce program to user
    puts("This program determines if two numbers\n"
    "are equal based on Alice's definition\n"
    "-----------------------------------------");\

    // Define variables
    int firstInteger, secondInteger, i;
    int sum1 = 0;
    int sum2 = 0;
    int done = 1; // For exiting program

    // Main while loop of program
    while(done){
        
        // Prompt user for the first input
        printf("Please enter the first integer number: ");
        // Store answer to memory
        scanf("%d", &firstInteger);

        // Prompt user for the second input
        printf("Please enter the second integer number: ");
        // Store answer to memory
        scanf("%d", &secondInteger);

        // For loop to check the length of each value entered
        for(i = 1; firstInteger > 0; i++){

            // Calculate summation and length in for loop
            sum1 += firstInteger % 10;
            firstInteger = firstInteger / 10;
            
        }

        // Store the length
        firstInteger = i;

        // For loop to check the length of each value entered
        for(i = 1; secondInteger > 0; i++){

            // Calculate summation and length in for loop
            sum2 += secondInteger % 10;
            secondInteger = secondInteger / 10;

        }
        
        // Store the length
        secondInteger = i;

        // if statement will determine if they are equal and sum the same
        if(firstInteger == secondInteger && sum1 == sum2){

            // Say the are equal
            puts("The numbers are equal.");
        }
        // else if to determine why they are not equal
        else if(firstInteger != secondInteger){

            // Say they are different length
            puts("The numbers have different length.");
        }
        // else if to determine why they are not equal
        else{

            // Say they are not equal
            puts("The numbers are not equal.");
        }

        // Exit loop incase invalid answer
        do{
            // Prompt user if they want to play again
            printf("Would you like to try again? (1 = yes, 0 = no): ");
            // Store answer to memory
            scanf("%d", &done);

            // If the answer is invalid
            if(done != 1 && done != 0){
                
                // Tell them it is not valid
                puts("That is not a valid answer.");
            }

        }while(done != 1 && done != 0);
    }

}