/*
Sample problem 2
Lucas Sarweh
*/

// Include header files
#include <stdio.h>

// Define macros

// Get positive factors of integer
int factors(int n){

    // Sum variable
    int sum = 0;

    for(int i = 1; i <= n / 2; i++){
        // Check if it is divisible
        if(n % i == 0){
            // Print the divisor
            printf("%d, ", i);
            sum += i;
        }
    }

    // Return the sum
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

    printf("\n%d", factors(n));
}