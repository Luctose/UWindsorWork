/* ===========================================================================
COMP-1410 Lab 6
==============================================================================
Student name: Lucas Sarweh

Replace the error with a statement citing any sources of outside help:
In change_name() the first line allocating memory to temp, I used realloc()
and it was giving me a trace/breakpoint trap error when freeing memory and
I sent Isaac Kilbourne (a student) my code and he said not to use realloc()
so instead I changed it to malloc() and it worked (Had to do with freeing
and then reallocating the pointer for the name).

=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of structure for storing student information
struct student {
  int id;
  char * name;
};

// create_student(id, name) creates a new student record with given id and name;
//   allocates memory to store structure and name (caller must free)
// requires: name is a valid string
struct student * create_student(int id, char * name);

// free_student(s) frees the memory associated with the student record s
// requires: s is a student record created using dynamic memory allocation
void free_student(struct student * s);

// change_name(s, new_name) renames the student s to have the name given by
//   new_name; allocates memory to hold new_name (caller must free)
//   returns true if the name was successfully changed and false otherwise
// requires: s points to a valid student and new_name points to a valid
//   string created using dynamic memory allocation
bool change_name(struct student * s, char * new_name);

// Implementation of create_student()
struct student * create_student(int id, char * name){
    // Allocate dynamic memory
    struct student * new = (struct student *) malloc(1 * sizeof(struct student));
    // If the request fails
    if(new == NULL){
      // Terminate using code for not enough memory
      puts("Not enough memory.");
      exit(137);
    }
    // Allocate dynamic memory for the name
    new->name = (char *) malloc(1 * sizeof(strlen(name) + 1));
    // If the request fails
    if(new->name == NULL){
      // Terminate using code for not enough memory
      puts("Not enough memory.");
      exit(137);
    }
    // Assign the students credentials
    new->id = id;
    for(int i = 0; i < strlen(name) + 1; i++){
      new->name[i] = name[i];
    }
    // Return adress
    return new;
}

// Implementation of free_student()
void free_student(struct student * s){
    // Free memory
    free(s->name);
    free(s);
}

// Implementation of change_name()
bool change_name(struct student * s, char * new_name){
    // Temp variable incase the request fails (Don't want to delete original pointer)
    char * temp = (char*) malloc(strlen(new_name) + 1); // Re allocate
    // If the request fails
    if(temp == NULL){
      puts("Not enough memory.");
      // Not enough memory return false and leave original unchanged
      return false;
    }
    // If successful change to new pointer
    s->name = temp;
    // Change the name
    for(int i = 0; i < strlen(new_name) + 1; i++){
      s->name[i] = new_name[i];
    }
    // Return true for success
    return true;
}

int main(void) {
  // Implement your test code here
  // Creating students
  struct student * my_ptr = create_student(110042658, "Lucas");
  struct student * test1 = create_student(54676556, "Clark");
  struct student * test2 = create_student(456787654, "Bobman XII");

  // Making sure they were created properly
  assert(strcmp(test1->name, "Clark") == 0);
  assert(strcmp(test2->name, "Bobman XII") == 0);
  assert(strcmp(my_ptr->name, "Lucas") == 0);
  
  // Testing name changes
  // Making sure my computer isn't potato
  if(change_name(test1, "Bossman") && change_name(test2, "Jimbo") && change_name(my_ptr, "Samer")){
    assert(strcmp(test1->name, "Bossman") == 0); // Changing smaller string to larger one
    assert(strcmp(test2->name, "Jimbo") == 0); // Changing bigger string to smaller one
    assert(strcmp(my_ptr->name, "Samer") == 0); // Changing name to name of same length
  }else{
    puts("Asserts skipped, not enough memory");
  }

  // Free the memory
  free_student(my_ptr);
  free_student(test1);
  free_student(test2);
  printf("All tests passed successfully.\n");
}