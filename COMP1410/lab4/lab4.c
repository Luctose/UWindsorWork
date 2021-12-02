/* ===========================================================================
COMP-1410 Lab 4
==============================================================================
Student name: Lucas Sarweh

Replace the error with a statement citing any sources of outside help:
None

=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <string.h>

// char_swap(char *, char *) swaps two characters in a string
// Requires: pass in pointers for strings that can be modified
void char_swap(char *a, char *b);

// select_min(str) returns a pointer to the character of minimal ASCII value
//   in the string str
// requires: str is a valid string, length(str) >= 1
char * select_min(char str[]);

// str_sort(str) sorts the characters in a string in ascending order
// requires: str points to a valid string that can be modified
void str_sort(char str[]);

// Implementation of char_swap(char *, char *)
void char_swap(char *a, char *b){
    // Swap values of a and b
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Implementation of select_min(str)
char * select_min(char str[]){
  // Variables for tracking the lowest ascii value and the index of it
  int min_ascii = __INT_MAX__;
  int index = 0;
  const size_t len = strlen(str);
  // Loop through each segment of memory for the string
  for(size_t i = 0; i < len; i++){
    // When it finds a lower ascii value
    if((int)str[i] < min_ascii){
      // Make it the current one to return
      min_ascii = (int)str[i];
      index = i;
    }
  }
  // Return lowest ascii adress
  return &str[index];
}

// Implementation of str_sort(str)
void str_sort(char str[]){
  // Define the length of the string
  int len = strlen(str);
  // Loop through the string
  for(int i = 0; i < len; i++){
    // Swap current smallest ascii character with the current position
    char_swap(select_min(str + i), &str[i]);
  }
}

int main(void) {
  // Implement your test code here
  char string[] = "Hello Dude";

  // Testing char_swap()
  char_swap(string + 1, string);
  assert(strcmp(string, "eHllo Dude") == 0); // Testing swapping letters
  char_swap(string, string + 9);
  assert(strcmp(string, "eHllo Dude") == 0); // Testing swapping two identical letters
  char_swap(string + 5, string + 7);
  assert(strcmp(string, "eHllouD de") == 0); // Testing swapping space character
  char_swap(string + 8, string + 8);
  assert(strcmp(string, "eHllouD de") == 0); // Swapping same character

  // Testing select_min()
  assert(*select_min("Are you ok") == ' '); // Space is lower
  assert(*select_min("sorry") == 'o'); // Arbitrary example
  assert(*select_min("abstract") == 'a'); // a is lowest lowercase ascii and occurs twice
  assert(*select_min("e") == 'e'); // String is only one character
  assert(*select_min("samiraisbalanceD") == 'D'); // D is last and it is uppercase

  // Testing str_sort()
  char teststr[45] = "Howdy";
  str_sort(teststr);
  assert(strcmp(teststr, "Hdowy") == 0); // Regular case
  strcpy(teststr, "Cool Ghoul");
  str_sort(teststr);
  assert(strcmp(teststr, " CGhllooou") == 0); // With space
  strcpy(teststr, "Saggin");
  str_sort(teststr);
  assert(strcmp(teststr, "Saggin") == 0); // Already in order
  strcpy(teststr, "zulga");
  str_sort(teststr);
  assert(strcmp(teststr, "agluz") == 0); // Completely out of order
  strcpy(teststr, "");
  str_sort(teststr);
  assert(strcmp(teststr, "") == 0); // Empty string
  strcpy(teststr, "y");
  str_sort(teststr);
  assert(strcmp(teststr, "y") == 0); // Single character string
  strcpy(teststr, "fiauhrnfnduenfmvmdnfkoksokaiwojnvsfpvpxzz");
  str_sort(teststr);
  assert(strcmp(teststr, "aaddefffffhiijkkkmmnnnnnooopprssuuvvvwxzz") == 0); // Repeating random characters

  printf("All tests passed successfully.\n");
}