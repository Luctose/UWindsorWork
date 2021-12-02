/*
COMP-1400 Midterm
Question 5 - Sequence
Developed by: Lucas Sarweh
Version: 1
Date: 14 Nov 2020
*/

// Include standard input/output
#include <stdio.h>

// Function calculates the factorial of a number
int factorial(int n){

    // Define output
    int output = n;
    // Take away 1 from n as output already has the first number
    n -= 1;

    // For loop for calculating factorial
    for(int i = 0; i + 1 < n ; i++){

        output *= (n - i);
    }

    // Return output if succesful
    return output;

}

// Main function is where program execution starts
int main(void){

    // done for exiting
    int done = 1;
    int number = 0;
    double sum = 0.5;

    // While user still playing
    while(done){

        // Prompt user for input
        printf("Please enter a positive integer value (between 1 and 7, inclusive): ");
        // Store into memory
        scanf("%d", &number);

        // If number too big
        if(number <= 0){

            // Give message and continue
            puts("Invalid input. Try again.");
            continue;

        }else if(number >= 8){
            
            // Give message and continue
            puts("Invalid input. Try again.");
            continue;
        }

        printf("1/2 ");

        // Calculate 1/n! sequence
        for(int i = number - 3; i >= 0; i--){

            sum += factorial(number - i);
            printf("+ 1/%d", factorial(number - i));

        }
        printf(" = %.2f\n", sum);

        printf("Do you want to play again? (1 = yes, 0 = no): ");
        scanf("%d", &done);
    }

}