/*
COMP-1400 Final Exam Question 2
Title
Developed by: Lucas Sarweh
Version: 1
Date: 12/12/2020
*/

// Include header files
#include <stdio.h> // Standard Input/Output

// Define symbolic constants

// Function prototype
double diff(int num);

// Main function starts execution
int main(void){
    
    // Integer stores user input
    int n;

    // Prompt user
    printf("%s", "Please enter an integer number: ");
    // Store to memory
    scanf("%d", &n);

    // Check if n is big enough
    if(n > 10){
        // Call diff using user's input as parameter and output result
        printf("The output is: %.2lf", diff(n));
    }else{
        // Tell user input is not big enough
        puts("The output is too small.");
    }
}

// Function declaration
double diff(int num){

    // Product of digits
    int proDig = 1;
    // Average of digits
    double average = 0;
    // Temp to store num without destroying
    int temp = num;
    // Number of digits
    int i;

    // Find the average of digits
    for(i = 0; temp > 0; i++){
        average = average + (temp % 10);
        temp = temp / 10;
    }
    // Divide by number of digits
    average = average / (double)i;

    // Find product of digits
    while(num > 0){
        proDig = proDig * (num % 10);
        num = num / 10;
    }

    // Return the answer
    return proDig - average;
}