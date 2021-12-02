/* ===========================================================================
COMP-1410 Assignment 1
==============================================================================
Student name: Lucas Sarweh

Cite any other sources of outside help
(e.g., websites, other students):
None

=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// choose(n,m) returns how many ways there are to choose m items from
//   a set of n items
// requires: 0 <= m, 0 <= n
int choose(int n, int m);

// num_divisors_up_to_k(n,k) returns the number of positive divisors
//   of n that are less than or equal to k
// requires: 1 <= k <= n
int num_divisors_up_to_k(int n, int k);

// is_prime(n) returns true if n is a prime number and false otherwise
// requires: 1 <= n
bool is_prime(int n);

// collatz(n) returns the number of steps it takes to reach 1 by
//   by repeatedly applying the Collatz mapping on n; prints each
//   number in the sequence starting at n
// requires: 1 <= n
int collatz(int n);

// Implementation of choose(n, m)
int choose(int n, int m){
  // return 0 if function conditions are not met
  if (m > n || m < 0){ // No need to check for n < 0
    return 0;
  }
  // Base case when you are choosing 0 or choosing the whole list
  else if(m == 0 || m == n){
    return 1;
  }
  // Recursion
  else{
    return choose(n - 1, m) + choose(n - 1, m - 1);
  }
}

// Implementation of num_divisors_up_to_k(n, k)
int num_divisors_up_to_k(int n, int k){
  // Return 0 for invalid function parameters
  if(k < 1 || k > n){
    return 0;
  }
  // Base case when the divisor is 1
  else if(k == 1){
    return 1;
  }
  // Recursion when the current k value is divisible
  else if(n % k == 0){
    return num_divisors_up_to_k(n, k - 1) + 1;
  }
  // Recursion when the current k value is not divisible
  else{
    return num_divisors_up_to_k(n, k - 1);
  }
}

// Implementation of is_prime(n)
bool is_prime(int n){
  // Return false for invalid inputs
  if(n < 1){
    return false;
  }
  // Return true if the number of divisors up to itself is 2
  // Hence the definition of a prime number (n and 1)
  else if(num_divisors_up_to_k(n, n) == 2){
    return true;
  }
  // Return false otherwise
  return false;
}

// Implementation of collatz(n)
int collatz(int n){
  // Check invalid parameters when n <= 0
  if(n <= 0){
    puts("Error: Invalid input");
    return 0;
  }
  // Base case when n == 1
  else if(n == 1){
    printf("%d\n", n);
    return 0;
  }
  // When n is odd
  else if(n % 2 == 1){
    printf("%d -> ", n);
    return collatz(3*n + 1) + 1;
  }
  // When n is even
  else if(n % 2 == 0){
    printf("%d -> ", n);
    return collatz(n / 2) + 1;
  }
  
}

int main(void) {
  // Testing choose(n, m) using asserts
  assert(choose(4, 2) == 6); // Given example
  assert(choose(7, 3) == 35); // Success
  assert(choose(6, 6) == 1); // Base case m == n
  assert(choose(4, 0) == 1); // Base case when m == 0
  assert(choose(5, 7) == 0); // m greater than n causes error
  assert(choose(-2, 4) == 0); // Negative numbers cause errors
  assert(choose(3, -1) == 0); // Negative numbers cause errors

  // Testing num_divisors_up_to_k(n, k)
  assert(num_divisors_up_to_k(78, 1) == 1); // Base case when k == 1
  assert(num_divisors_up_to_k(9, 3) == 2); // Successful test
  assert(num_divisors_up_to_k(27, 27) == 4); // Successful test
  assert(num_divisors_up_to_k(-1, 6) == 0); // Negative n value causes error
  assert(num_divisors_up_to_k(6, -1) == 0); // Negative k value causes error
  assert(num_divisors_up_to_k(8, 19) == 0); // When k > n causes an error
  assert(num_divisors_up_to_k(56, 0) == 0); // Dividing by 0 is a crime against humanity

  // Testing is_prime(n)
  assert(is_prime(1) == false); // 1 is not a prime number
  assert(is_prime(86) == false); // 86 is not a prime number
  assert(is_prime(7) == true); // 7 is a prime number
  assert(is_prime(53) == true); // 53 is a prime number
  assert(is_prime(0) == false); // Returns false on anything below 1
  assert(is_prime(-11) == false); // Returns false on negative numbers

  // Testing collatz(n) (These asserts will also trigger the sequence text from printf)
  assert(collatz(5) == 5); // Example
  assert(collatz(67) == 27); // Odd start
  assert(collatz(24) == 10); // Even start
  assert(collatz(0) == 0); // Invalid parameter when n <= 0
  assert(collatz(-67) == 0); // Negative numbers invalid
  assert(collatz(1) == 0); // Base case takes 0 steps

  // Define variable for user input
  int input;

  // First prompt
  printf("Please enter an integer for collatz (Char to exit): ");
  // User input collatz
  while(scanf("%d", &input)){
    // Call collatz with user input
    collatz(input);
    // Flush stdin incase they put a float
    fflush(stdin);
    // Prompts during iteration
    printf("Please enter an integer for collatz (Char to exit): ");
  }

  puts("All tests have passed successfully!");
}
