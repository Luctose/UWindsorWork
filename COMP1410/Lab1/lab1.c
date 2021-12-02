/* ===========================================================================
COMP-1410 Lab 1: Iteration and Recursion
==============================================================================
Student name: Lucas Sarweh

Cite any other sources of outside help
(e.g., websites, other students):
None

=========================================================================== */

#include <stdio.h>
#include <assert.h>

// digit_sum_iterative(n) returns the decimal sum of the digits in n
// requires: 0 <= n < 10^9
// note: implemented using iteration and not recursion
int digit_sum_iterative(int n);

// digit_sum_recursive(n) returns the decimal sum of the digits in n
// requires: 0 <= n < 10^9
// note: implemented using recursion and not iteration
int digit_sum_recursive(int n);

// last_digit(n) returns the last digit of a decimal number
// A helper function
int last_digit(int n);

// remove_last(n) returns a decimal number without the last digit
// A helper function
int remove_last(int n);

// Implementation of digit_sum_iterative(n)
int digit_sum_iterative(int n){
    // Define sum and set it to 0
    int sum = 0; 

    // Check for unwanted parameters
    if(n < 0 || n >= 1000000000){
        return 0; // Return 0 for error in assert
    }

    // Add digits until n is 0
    while(n > 0){
        sum += last_digit(n);
        n = remove_last(n);
    }
    return sum; // Return result
}

// Implementation of digit_sum_recursive(n)
int digit_sum_recursive(int n){
    // Check unwanted parameters
    if(n < 0 || n >= 1000000000){
        return 0; // Return 0 for error in assert
    }

    // Base case - when only one digit is left
    if(n / 10 == 0){
        return n;
    }
    // Recursion
    else{
        return digit_sum_recursive(remove_last(n)) + last_digit(n);
    }
}

// Implementation of last_digit(n)
int last_digit(int n){
    return n % 10;
}

// Implementation of remove_last(n)
int remove_last(int n){
    return n / 10;
}

int main(void) {
  assert(digit_sum_iterative(1234) == 10); // Given Example
  assert(digit_sum_recursive(1234) == 10);
  assert(digit_sum_iterative(7849323) == 36); // Arbitrary Number Test
  assert(digit_sum_recursive(7849323) == 36);
  assert(digit_sum_iterative(1896969594) == 0); // Bigger than 10^9 should return 0
  assert(digit_sum_recursive(1896969594) == 0);
  assert(digit_sum_iterative(-566) == 0); // Negative numbers will also return 0
  assert(digit_sum_recursive(-566) == 0);
  // Implement your test code here
  printf("All tests passed successfully.\n");
}