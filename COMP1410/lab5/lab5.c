/* ===========================================================================
COMP-1410 Lab 5
==============================================================================
Student name: Lucas Sarweh

Replace the error with a statement citing any sources of outside help:
None

=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Definition of structure for storing student information
struct student {
  int id;
  char name[20];
};

// find_id(id, arr, n, found_name) searches for a student with given id in arr;
//   returns true if such a student is found and found_name is updated to
//   hold the student's name; otherwise returns false
// requires: arr has length n
//           students in arr have unique ids
//           found_name points to enough memory to hold a name
bool find_id(int id, struct student arr[], int n, char * found_name);

// find_name(name, arr, n, ids) searches for student(s) with given name in arr;
//   returns the number of students found and the array ids is updated to
//   contain the id numbers of those students
// requires: arr has length n
//           students in arr have unique ids
//           ids points to enough memory to hold the found student ids
int find_name(char * name, struct student arr[], int n, int ids[]);

// change_name(s, new_name) renames the student s to have the name given by
//   new_name
// requires: s points to a valid student that can be modified
//           new_name points to a valid string of length at most 19
void change_name(struct student * s, char * new_name);

// Implementation of find_id()
bool find_id(int id, struct student arr[], int n, char * found_name){
    // Search for the student
    for(int i = 0; i < n; i++){
        // When the student is found
        if(id == arr[i].id){
          // Copy name to found_name list
          strcpy(found_name, arr[i].name);
          // Return true
          return true;
        }
    }
    // Return false when not found
    return false;
}

// Implementation of find_name()
int find_name(char * name, struct student arr[], int n, int ids[]){
  
  // Store how many students
  int student_count = 0;
  // Index keeps track of how many times we went through the same name
  int index = 0;

  // Search for student
  for(int i = 0; i < n; i++){
    // If the name to search for is the current structs name
    if(strcmp(name, arr[i].name) == 0){
      student_count += 1; // Add to the number of students with the same name
      ids[index] = arr[i].id; // Add their student id to the storage list
      index += 1; // Add one to the index of the storage list

    }
  }
  // Return number of students found
  return student_count;
}

// Implementatation of change_name()
void change_name(struct student * s, char * new_name){
  // Copy the new name to the location pointed to by structs name attribute
  strcpy(s->name, new_name);
}

int main(void) {
  // Instances
  struct student s1 = {1234567, "Alice"};
  struct student s2 = {3141593, "Bob"};
  struct student s3 = {8675309, "Eve"};
  struct student s4 = {110042658, "Lucas"};
  struct student s5 = {5643244, "Bob"};
  
  // Create array of our people structure
  struct student array[7] = {s1, s2, s3, s4, s5};

  // Storage arrays
  char found_name[20];
  int ids[20] = {0};

  // Testing find_id()
  assert(find_id(1234567, array, 7, found_name) == true); // Regular example
  assert(strcmp(found_name, "Alice") == 0); // Updates name

  assert(find_id(110042658, array, 7, found_name) == true); // My student id
  assert(strcmp(found_name, "Lucas") == 0); // Updates name

  assert(find_id(544433228, array, 7, found_name) == false); // Example when it is not in the list
  assert(strcmp(found_name, "Lucas") == 0); // Name does not update

  assert(find_id(-33336655, array, 7, found_name) == false); // When the id is a negative integer
  assert(strcmp(found_name, "Lucas") == 0); // Name does not update

  // Testing find_name()
  assert(find_name("Eve", array, 7, ids) == 1); // Make sure there is only one name "Eve" found
  assert(ids[0] == 8675309); // Check id

  assert(find_name("Lucas", array, 7, ids) == 1); // My name
  assert(ids[0] == 110042658); // Check id

  assert(find_name("Bart", array, 7, ids) == 0); // No name found
  assert(ids[0] == 110042658); // Id is same as before

  assert(find_name("Bob", array, 7, ids) == 2); // Example when there is multiple occurences
  assert(ids[0] == 3141593 && ids[1] == 5643244); // Check both id's were stored

  assert(find_name("p", array, 7, ids) == 0); // Fastest case single character and no common first chars for strcmp()
  assert(ids[0] == 3141593); // Not a name so id's are not updated

  // Testing change_name()
  change_name(&array[0], "Coolio");
  assert(strcmp(array[0].name, "Coolio") == 0); // Testing normal name change

  change_name(&array[1], "Bob");
  assert(strcmp(array[1].name, "Bob") == 0); // Changing to the same name

  change_name(&array[2], "");
  assert(strcmp(array[2].name, "") == 0); // Changing name to an empty string

  change_name(&array[3], "Sarweh");
  assert(strcmp(array[3].name, "Sarweh") == 0); // Changing my firstname to my lastname

  // Implement your test code here
  printf("All tests passed successfully.\n");
}