/*
COMP-1400 Final Exam Question 5
Title
Developed by: Lucas Sarweh
Version: 1
Date: 12/12/2020
*/

// Include header files
#include <stdio.h> // Standard Input/Output
#include <stdlib.h>
#include <time.h>

// Define symbolic constants

// Main function starts execution
int main(void){
    
    // User input
    int n;
    // for sorting
    int temp;
    // Track to play again
    int again;
    
    // Set seed
    srand(time(NULL));

    // Loop to try again
    do{
        // Catch invlaid inputs
        do{

            // Prompt user for input
            printf("%s", "Enter a valid integer number (n): ");
            scanf("%d", &n); // Store to memory
            if(n < 1){
                puts("That is an invalud input.");
            }
        }while(n < 1);

        // Declare the array of random ints using n
        int num[n];

        // Loop through each element
        for(int i = 0; i < n; i++){
            // Assign random numbers
            num[i] = (rand() % 999) + 1;
        }

        // Sort array from largest to smallest (Reverse bubble sort)
        for(int i = 0; i < n; i++){
            for(int k = 0; k < (n - i); k++){
                if(num[k] < num[k + 1]){
                    // Interchange those two elements
                    temp = num[k];
                    num[k] = num[k + 1];
                    num[k + 1] = temp;
                }
            }
        }

        // Print array
        for(int i = 0; i < n; i++){
            // Print each element
            printf("%d, ", num[i]);
        }

        // Ask if they want to play again
        printf("%s", "Would you like to play again (1 for yes, 0 for no): ");
        scanf("%d", &again);

    }while(again);

    // Thank the player
    puts("Thanks for playing my game! Bye.");
}