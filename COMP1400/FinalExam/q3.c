/*
COMP-1400 Final Exam Question 3
Title
Developed by: Lucas Sarweh
Version: 1
Date: 12/12/2020
*/

// Include header files
#include <stdio.h> // Standard Input/Output
#include <stdlib.h>

// Define symbolic constants

// Define function prototypes
void append(char array[]);
void replace(char array[], int start, int end);

// Main function starts execution
int main(void){
    
    // Define variables
    char source[60];
    char key[15];
    int start, end;
    int yes = 0;\
    int size;

    // Prompt user for inputs
    printf("%s", "Please enter a string: ");
    scanf("%s", source);
    printf("%s", "Please enter the keyword: ");
    scanf("%s", key);
    // Find size of the string
    for(size = 0; key[size] != '\0'; size++);

    append(source);


}

// Function declaration
void append(char array[]){

    // Keep track of indicies
    int i;
    int k;

    // Define my name string
    char myName[] = "Lucas";
    char newString[60];

    // Count size of array
    for(i = 0; array[i] != '\0'; i++){
        // Add input array
        newString[i] = array[i];
    }

    // Loop through
    for(k = 0; myName[k] != '\0'; i++, k++){
        // Add name to new array
        newString[i] = myName[k];
    }
    // Add terminating null
    newString[i] = '\0';

    // Print new array
    printf("%s\n", newString);

}

// Declaration
void replace(char array[], int start, int end){
    
    // Keep track
    int i = 0;
    int k = 0;
    int l = 0;
    int m = 1;

    // Define my name string
    char myName[] = "Lucas";
    char newString[60];

    // Count size of array
    for(i = 0; array[k] != '\0'; i++){
        if(i >= start && myName[l] != '\0'){
            // Add name
            newString[i] = myName[l];
            l++;
            if(m){
                k = k + (end - start);
                m = 0;
            }
            
        }else if(i < start || i > end){
            // Add input array
            newString[i] = array[k];
            k++;
        }
    }
    // Add terminating null
    newString[i] = '\0';

    printf("%s\n", newString);
}