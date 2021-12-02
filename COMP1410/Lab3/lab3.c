/* ===========================================================================
COMP-1410 Lab 3
==============================================================================
Student name: Lucas Sarweh

Cite any other sources of outside help
(e.g., websites, other students):
None

=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// Function returns true if two matrices are equal
// From TA in the lab section
// requires: n >= 1
bool matrix_equals(int n, int a[][3], int b[][3]);

// matrix_add(n, a, b, c) computes the sum of the n x 3 matrices a and b;
//   the result is stored in the n x 3 matrix c
// requires: n >= 1
void matrix_add(const int n, const int a[][3], const int b[][3], int c[][3]);

// negate_column(n, c, a) negates the entries in column c of the n x 3
//   matrix a
// requires: n >= 1, 0 <= c < 3
void negate_column(const int n, const int c, int a[][3]);

// negate_row(n, r, a) negates the entries in row r of the n x 3 matrix a
// requires: n >= 1, 0 <= r < n
//           a points to the (0, 0) element of an n x 3 matrix
void negate_row(const int n, const int r, int * a);

// Implementation of matrix_equals(n, a[][3], b[][3])
bool matrix_equals(int n, int a[][3], int b[][3]){
    // For each row
    for(int i = 0; i < n; i++){
        // For each column
        for(int j = 0; j < 3; j++){
            if(a[i][j] != b[i][j]){
                // Return false immediatley when we find a difference
                return false;
            }
        }
    }
    // Return true when everything is equal
    return true;
}

// Implementation of matrix_add(n, a[][3], c[][3])
void matrix_add(const int n, const int a[][3], const int b[][3], int c[][3]){
    // Loop through each row
    for(int i = 0; i < n; i++){
        // Loop through each column
        for(int j = 0; j < 3; j++){
            // Add the same elements spots to eachother
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Implementation of negate_column(n, c, a[][3])
void negate_column(const int n, const int c, int a[][3]){
    for(int i = 0; i < n; i++){
        // Only switch rows with a constant column index
        a[i][c] = a[i][c] * -1;
    }
}

// Implementation of negate_row(n, r, *a)
void negate_row(const int n, const int r, int * a){
    // Start at row you want to negate
    a += 3*r;

    // Loop through the current row to negate them
    for(int i = 0; i < 3; i++){
        *a = *a * -1;
        a++;
    }
}

int main(void) {
  int a[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
  int b[3][3] = {{0, -1, -2}, {-3, -4, -5}, {-6, -7, -8}};
  int c[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  int d[3][3] = {{0, 1, 2}, {-3, -4, -5}, {6, 7, 8}};
  int e[3][3] = {{0, -1, 2}, {3, -4, 5}, {6, -7, 8}};
  int ans1[3][3] = {{0, 0, 4}, {6, 0, 10}, {12, 0, 16}};
  int ans2[3][3] = {{0, -1, 2}, {3, -4, 5}, {6, -7, 8}};
  int ans3[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
  int ans4[3][3] = {{0, 1, 2}, {-3, -4, -5}, {-6, -7, -8}};
  int ans5[3][3] = {{0, 1, 2}, {-3, -4, -5}, {-6, -7, -8}};
  // Perform testing here, e.g., that a + b = c

  // Testing matrix_add()
  matrix_add(3, a, e, c);
  assert(matrix_equals(3, c, ans1));

  matrix_add(3, b, ans1, c);
  assert(matrix_equals(3, c, ans2));

  // Testing negate_column()
  negate_column(3, 1, e);
  assert(matrix_equals(3, e, ans3));

  negate_column(3, 0, e);
  assert(matrix_equals(3, e, ans3) == false);

  // Testing negate_row()
  negate_row(3, 2, &d[0][0]);
  assert(matrix_equals(3, d, ans4));

  negate_row(3, 0, &b[0][0]);
  assert(matrix_equals(3, b, ans5));
  
  printf("All tests passed successfully.\n");
}