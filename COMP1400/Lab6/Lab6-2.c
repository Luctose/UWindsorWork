/*
This will get a number from a user and
determine if it is a prime number
COMP-1400 Lab 6
Exercise 2
Developed by: Lucas Sarweh
Version: 1
Date: 2 Nov 2020
*/

// Include standard input/output
#include <stdio.h>

// The main function is where execution starts
int main(void){

    // Define variables
    int number, i, prime;

    // Assume a number is prime at the beggining
    prime = 1;

    // Welcome message
    puts("Welcome! This will determine if you inputted a prime number.");

    // Prompt to enter a number
    printf("Please enter a number: ");

    // Store input into memory
    scanf("%d", &number);

    // Use a loop to calculate if it is prime or not
    for(i = 2; i <= number / 2; i++){

        // If a number is evenly divisible by 0
        if(number % i == 0){

            // It is not a prime number
            prime = 0;
        }
    }
    // Choose whether it is a prime number
    if(prime){

        // Say it is a prime number
        printf("%d is a prime number.", number);
    }
    else{

        // Say it is not a prime number
        printf("%d is not a prime number.", number);
    }
}