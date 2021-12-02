/*
Lab 8 Part C - Decimal - Binary Conversion
COMP-1400
This program converts a positive decimal
number into a binary number.
Developed by: Lucas Sarweh
Version: 1
Date: 16 Nov 2020
*/

// Include standard input/output
#include <stdio.h>

// Function returns a binary given a decimal
long long int decimalToBinary(int decimal){

    // Declare variable binary
    long long int binary = 0;
    long long int temp = 0;
    int even = 0;

    // If decimal is even
    if(decimal % 2 == 0){

        // Keep track of it being even
        even = 1;
    }

    // For loop to calculate the binary
    for(int i = 1; decimal > 0; i++){

        if(decimal % 2){
        // Conversion
            temp += 1;
        }
        temp *= 10;
        // Reduce decimal
        decimal = decimal / 2;
    }
    // Flip number as the binary calculates it backwards
    for(int i = 0; temp > 0; i++){

        // Add the last digit of temp while staying in the correct number column
        binary = binary * 10 + (temp % 10);

        // Shorten temp
        temp = temp / 10;
    }

    // If it is even originally add an extra 0 at the end
    if(even){

        // Multiply by 10
        binary *= 10;
    }
    // Return the binary number
    return binary;
}

// Main function begins program execution
int main(void){

    printf("%lld, %lld, %lld, %lld, %lld", decimalToBinary(1), decimalToBinary(2), decimalToBinary(10), decimalToBinary(1001), decimalToBinary(90250));
}