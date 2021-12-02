/*
Lab 9 - Exercise B
Array Number Frequency
Developed by: Lucas Sarweh
22 Nov 2020
Version: 1
*/

// Include standard input/output
#include <stdio.h>
// Include time
#include <time.h>
// Include standard lib
#include <stdlib.h>
// Define the size of our array
#define SIZE 30

// User defined function prototypes
void makeRandom(int array[]);
unsigned int findKey(int array[], int key);

// Main function begins execution
int main(void){

    // Initialize key
    int userInput;
    // Initialize array
    int array[SIZE];

    // Randomize array
    makeRandom(array);

    // Do while loop so the user inputs in given range
    do{
        // Prompt and get the key from the user
        printf("%s", "Please enter the desired number (between 0 and 20 inclusive): ");
        scanf("%d", &userInput);
        // If input is out of range
        if(userInput < 0 || userInput > 20){

            // Tell user it is invalid
            puts("That input is invalid!");
        }
    }while(userInput < 0 || userInput > 20);

    // Use findKey function and print the return value
    printf("In the array with the values: {%d", array[0]);
    for(int j = 1; j < SIZE; j++){ // Iterate through each element of the array

        // Print current element
        printf(", %d", array[j]);
    }
    // Print last part of the statement
    printf("} %d's frequency is %u.", userInput, findKey(array, userInput));
}

// Definition of makeRandom which randomizes an array
void makeRandom(int array[]){

    // Set seed for random list elements
    srand((unsigned)time(NULL)); // Based off current time
    // Set the random list values
    for(size_t i = 0; i < SIZE; ++i){

        // Set random number (between 0 and 20) to current element
        array[i] = rand() % 21;
    }
}

// Definition of findKey which determines how many times a value appears in an array and returns that value
unsigned int findKey(int array[], int key){

    // Keeps track of how many of the given value is in the given list
    unsigned int counter = 0;

    // Iterate through each item in the list
    for(size_t i = 0; i < SIZE; i++){
        
        // Check if the current element is the same as the key
        if(array[i] == key){

            // Then add one to the counter
            counter += 1;
        }
    }

    // Return the frequency of the key in the given array
    return counter;
}