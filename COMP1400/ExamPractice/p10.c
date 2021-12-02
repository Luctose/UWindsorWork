/*
Sample problem 10
Lucas Sarweh
*/

// Include header files
#include <stdio.h>
// Define macros
#define SIZE 10

int main(void){
    // Declare integer array
    int num[SIZE];
    int sum = 0;

    // For loop to ask user what values are
    for(int i = 0; i < SIZE; i++){

        // Prompt user for number
        printf("Enter number %d: ", i + 1);
        // Store Entry to memory
        scanf("%d", &num[i]);
    }
    // Loop through array
    for(int j = 0; j < SIZE; j++){
        // Find even index and odd numbers
        if((num[j] % 2) != 0 && (j % 2) == 0){
            // Add current element to sum
            sum += num[j];
        }
    }
    // Print result
    printf("%d", sum);

    // Exit function
    return 0;
}