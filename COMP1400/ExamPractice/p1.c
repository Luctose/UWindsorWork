/*
Sample problem 1
Lucas Sarweh
*/

// Include header files
#include <stdio.h>

// Define macros

// Sum of integers
int sum(int n){
    
    // sum variable
    int sum = 0;

    // Display sum of integer numbers from 1 to n-1.
    for(int i = 1; i < n; i++){
        sum += i;
    }
    
    return sum;
}

// Main function
int main(void){

    // User input
    int n;

    // Prompt user
    printf("%s", "Enter an integer: ");
    // Store input to memory
    scanf("%d", &n);

    // Display result
    printf("%d", sum(n));
}