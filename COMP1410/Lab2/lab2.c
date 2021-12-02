/* ===========================================================================
COMP-1410 Lab 2
==============================================================================
Student name: Lucas Sarweh

Cite any other sources of outside help
(e.g., websites, other students):
None

=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// order(a, b) orders the values pointed to by a and b so that *a <= *b;
//   returns true if the values were switched and false otherwise
// requires: a and b point to memory that can be modified
bool order(int * a, int * b);

// swap_pointers(a, b) swaps the pointer values of a and b by
// passing the adressess of the pointers
// requires: a and b point to adresses that can be modified
void swap_pointers(int ** a, int ** b);

// Implementation of order(a, b)
bool order(int * a, int * b){
  // temp is used to store a variable's while also changing the original
  int temp;

  // When a is greater swap the two values
  if(*a > *b){
    temp = *a;
    *a = *b;
    *b = temp;
    return true; // True when a swap occurs
  }
  return false; // False when a swap does not occur
}

// Implementation of swap_pointers()
void swap_pointers(int ** a, int ** b){
  // Temp will store an address to swap
  int * temp;

  // Swap the two variables pointers
  temp = *a;
  *a = *b;
  *b = temp;
}

int main(void) {
  // Perform your tests here
  int a;
  int b;

  // Tests for order(a, b)
  a = 12;
  b = 10;
  assert(a == 12 && b == 10); // Check initial value
  assert(order(&a, &b) == true); // Should return true when the swap is successfull
  assert(a < b); // Check if a is less than b
  assert(a == 10 && b == 12); // Check that the values are swapped

  // Change values for next case
  a = 10;
  b = 12;
  assert(a == 10 && b == 12); // Check initial values
  assert(order(&a, &b) == false); // Should return false because a is already smaller than b
  assert(a < b); // Make sure a < b
  assert(a == 10 && b == 12); // Make sure values did not swap

  // Change values for next case
  a = 11;
  b = 11;
  assert(a == 11 && b == 11); // Check initial values
  assert(order(&a, &b) == false); // Should return false because they are the same so no swap occurs
  assert(a == b); // They should still be equivalent
  assert(a == 11 && b == 11); // Check they are still the same

  // Tests for swap_pointers(a, b)
  a = 30;
  b = 24;
  int * a_pointer = &a; // Store a pointer address
  int * b_pointer = &b; // Store b pointer address
  assert(a == 30 && b == 24); // Check initial value of a and b
  swap_pointers(&a_pointer, &b_pointer); // Function call
  assert(a == 30 && b == 24); // Make sure the values are unchanged
  assert(a_pointer == &b && b_pointer == &a); // See if the pointers are swapped
  
  printf("All tests passed successfully.\n");
  return 0; // Main was successful
}