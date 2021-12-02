/*
Lucas Sarweh
row_sums() Question 14
COMP1410
Midterm
*/

// Include headers
#include <stdio.h>

// row_sums() computes the sum of each row stored
// in another array
// Requires: n and m > 0, m <= 10, len(sum) >= n
void row_sums(int n, int m, int matrix[][10], int sums[]);

// Implementation of row_sums()
void row_sums(int n, int m, int matrix[][10], int sums[]){
    // Loop through the n rows and add each row and store them
    for(int i = 0; i < n; i++){
        for(int k = 0; k < m; k++){
            sums[i] += matrix[i][k];
        }
    }
}

// Main function
int main(void){
    // Example matrix
    int ex[4][10] = {{5, 6, 21, 4}, {7, 9, 6, 5}, {7, 7, 7, 7}, {0, 1, 2, 3}};
    // Storage array
    int store[10] = {0};
    // Call row_sums
    row_sums(4, 4, ex, store);

    for(int j = 0; j < 4; j++){
        printf("%3d", store[j]);
    }
}

/*
Explanation of row_sums()

Start with two for loops - 
The outer for looping to each row
the inner for looping each element
inside each row (column)
Inside the loops add the current elements
of the matrix to the current element of sums
for storage (element of sums changes when row changes).
*/