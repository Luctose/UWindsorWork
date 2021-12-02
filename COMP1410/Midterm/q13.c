/*
Lucas Sarweh
COMP1410
Midterm
max_digit question 13
*/

// Include headers
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// Helper function max(a, b) finds max of two
int max(int a, int b);

// max_digit(int n) finds the max digit of a decimal number
// Requires: n > 0, len(n) <= 9
int max_digit(int n);

// Implementation of max(int a, int b)
int max(int a, int b){
    if(a >= b){
        return a;
    }
    else{
        return b;
    }
}

// Implementation of max_digit(int n)
int max_digit(int n){
    // Base case when n is 0 meaning there is no more digits to check
    if(n == 0){
        return 0;
    }
    // Recursion - find the max of the current digit and the next ones
    return max(max_digit(n / 10), n % 10);
}

// Main function
int main(void){
    // Testing - I assumed we did not need to test for negative numbers or overflow because
    // it said it in the question
    assert(max_digit(1336) == 6);
    assert(max_digit(101) == 1);
    assert(max_digit(0) == 0);
    assert(max_digit(944393999) == 9);
    assert(max_digit(300102) == 3);
    assert(max_digit(7777787) == 8);
    puts("All tests have passed!");
}

/*
Explaination of max_digit(int n)

Firstly, it is a recursive function so we need a base case.
The base case here is when we run out of digits to check, so
the first if statement checks if n == 0, we return 0.
Secondly, the recursion will return if the base case isn't
true which will return the maximum between the current digit
we are on and the future digits that will be called recursively.
The max(int n) helper function will take care of finding the max previously
mentioned.
*/