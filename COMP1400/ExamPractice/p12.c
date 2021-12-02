/*
Sample problem 12
Lucas Sarweh
*/

// Include header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototype
void readUser(int num[], size_t size);
void bubbleSort(int array[], size_t size);
int findBig(int array[], size_t size);
void printArray(int array[], size_t size);
int averageArray(int array[], size_t size);

int main(void){
    // Set seed for program
    srand(time(NULL));

    // Define number of inputs
    size_t size = rand() % 50;
    // Define array
    int num[size];

    // Get numbers from user
    readUser(num, size);
    // Sort array
    bubbleSort(num, size);
    // Print array
    printArray(num, size);
    // Display biggest value
    printf("Largest value = %d\n", findBig(num, size));
    // Calculate and print average of array
    printf("Array average = %d\n", averageArray(num, size));
}

// Declaration
void readUser(int num[], size_t size){
    
    // Get valid input
    for(int i = 0; i < size; i++){
        // Incase the input is out of range
        do{
            // Prompt user for input
            printf("[%d] Enter an integer between -50000 to 5000000: ", i + 1);
            // Store to memory
            scanf("%d", &num[i]);
            // Let them know they inputted wrong
            if(num[i] < -50000 || num[i] > 5000000){
                printf("%s", "That input is invalid! Try again.\n");
            }
        }while(num[i] < -50000 || num[i] > 5000000);
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

int findBig(int array[], size_t size){

    // Define locals
    int biggest = INT_MIN;

    // Loop through the array
    for(int i = 0; i < size; i++){
        // Check for bigger number
        if(biggest < array[i]){

            // Make it the biggest
            biggest = array[i];
        }
    }
    // Return biggest number
    return biggest;
}

// Print items of an array
void printArray(int array[], size_t size){

    // Print first element
    printf("{%d", array[0]);

    // Loop through each element
    for(int i = 1; i < size; i++){
        // Print out current element
        printf(", %d", array[i]);
    }

    // Print last bit
    puts("}");
}

// Find the average of an array
int averageArray(int array[], size_t size){

    // Define locals
    int average = 0;

    // Loop through every item
    for(int i = 0; i < size; i++){
        // Add up the items
        average += array[i];
    }
    // Divide by size for average
    average = average / size;

    // Return average
    return average;
}