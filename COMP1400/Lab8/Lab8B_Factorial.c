/*
Lab 8 Part B - Factorial
COMP-1400
This program defines a function for
factorial and then prints examples.
Developed by: Lucas Sarweh
Version: 1
Date: 16 Nov 2020
*/

// Include standard input/output
#include <stdio.h>
#include <limits.h>

// Function returns the factorial of a positive integer number (Largest possible is 20!)
unsigned long long int factorial(int n){

    // Define the output value (defined as a very large positive integer)
    unsigned long long int output = n;
    n -= 1; 

    // Loop to multiply the starting integer until we reach 1
    // (stop at 2 because 1 does nothing saving time)
    for(int i = 0; i + 1 < n; i++){

        // multiply output by the current value
        output *= (n - i);
    }

    // Return the output after the calculations
    return output;
}

// Main function begins program execution
int main(void){

    // Print the factorial of various numbers
    printf("%llu, %llu, %llu, %llu, %llu, %llu\n", factorial(2), factorial(3), factorial(4), factorial(5), factorial(10), factorial(15));
}