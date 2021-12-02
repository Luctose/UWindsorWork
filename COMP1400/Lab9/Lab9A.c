/*
Lab 9 - Exercise A
Bubble Sort
Developed by: Lucas Sarweh
22 Nov 2020
Version: 1
*/

// Include standard input/output
#include <stdio.h>
// Include standard library
#include <stdlib.h>
// Include time header
#include <time.h>
// Include integral limits
#include <limits.h>

// User defined function prototypes
void makeRandom(int array[], size_t size);
void bubbleSort(int array[], size_t size);

// Main function starts program execution
int main(void){

    // Declare size
    size_t size;

    // Declare timer vairables
    time_t start, end;
    // Variable to store difference of two times
    double elapsedTime;

    // Get user input for array size
    printf("%s", "Input the size of the list: ");
    scanf("%zu", &size);
    
    // Declare the array using user input for size
    int randomArray[size];
    // Randomize array
    makeRandom(randomArray, size);
    // Print array
    printf("%s", "The randomized array is: {");
    for(size_t i = 0; i < size; i++){
        printf("%7d", randomArray[i]);
    }

    // Newline
    puts("\t}");
    
    // Start timer just before bubble sort begins
    time(&start);

    // Bubble sort array
    bubbleSort(randomArray, size);

    // End timer right after bubble sort ends
    time(&end);
    // Calculate the elapsed time
    elapsedTime = difftime(end, start);

    // Print array
    printf("%s", "\nThe sorted array is: {");
    for(size_t i = 0; i < size; i++){
        printf("%7d", randomArray[i]);
    }
    // Display elapsed time
    printf("\t}\nElapsed time in seconds: %.1lf\n", elapsedTime);
}

// Function makes random array
void makeRandom(int array[], size_t size){

    // Set seed for random list elements
    srand((unsigned)time(NULL)); // Based off current time
    // Set the random list values
    for(size_t i = 0; i < size; ++i){

        // Set random number to current element
        array[i] = rand();
    }
}

// Bubble sort function
void bubbleSort(int array[], size_t size){

    // Define variables for loop
    size_t pass; // Tracks outer loop
    size_t i; // Tracks inner loop
    int temp; // Extra variables allows interchanging of elements of the array
    unsigned int swaps = 0; // If a pass does not swap anything at all it is already sorted

    // For loop used to bubble sort
    for(pass = 0; pass < size; pass++, swaps = 0){
        for(i = 0; i < (size - pass); i++){
            
            // If current element is greater then next element
            if(array[i] > array[i + 1]){
                
                // Interchange those two elements
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                // Make it not exit
                swaps += 1;
            }
        }
        // If it is sorted early
        if(swaps == 0){

            // Exit the loop
            pass = size;
        }
    }
}