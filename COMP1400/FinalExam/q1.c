/*
COMP-1400 Final Exam Question 1
Title
Developed by: Lucas Sarweh
Version: 1
Date: 12/12/2020
*/

// Include header files
#include <stdio.h> // Standard Input/Output

// Define symbolic constants
#define SIZE 30

// Function Prototypes
int multArray(int a[], int size);

// Main function starts execution
int main(void){

    // Declare array
    int array[SIZE];
    // Initialize values
    for(int i = 0; i < SIZE; i++){
        array[i] = 0;
    }

    // Display my name
    printf("%s", "My name is: Lucas Sarweh\n"
    "***********\n");
    // Prompt user to enter 10 integers
    printf("%s", "Please enter 10 integer numbers seperated by comma, press \"Enter\" after that:\n");
    // Store numbers
    scanf("%d", &array[0]);
    for(int i = 1; i < 10; i++){
        scanf(",%d", &array[i]);
    }

    // Seperate
    puts("***********");

    // Find product and display it
    printf("The output is: %d\n", multArray(array, 10));

    // Seperate
    puts("***********");
}

// Returns multiplication of non-zero even numbers which are in the odd index positions
int multArray(int a[], int size){
    
    // Define product holder
    int product = 1;

    // Loop through array
    for(int i = 0; i < size; i++){
        // Check condition to be included
        if((i % 2 != 0) && (a[i] % 2 == 0) && (a[i] != 0)){
            // Multiply current element
            product = product * a[i];
        }
    }
    // Return product
    return product;
}