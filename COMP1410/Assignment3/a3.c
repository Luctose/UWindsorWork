/* ===========================================================================
COMP-1410 Assignment 3
==============================================================================
Student name: Lucas Sarweh

Replace the error with statement citing any sources of outside help:
ERROR_NO_INTEGRITY_STATEMENT

=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
                               Question 1
                        _Structure Definitions_
---------------------------------------------------------------------------
*/

// Linked list node that holds a student record
struct snode {
  int id;
  char * name;
  struct snode * next;
};

// Student list structure
struct slist {
  struct snode * front;
};

/*
                              Question 1
                        _Function Prototypes_
---------------------------------------------------------------------------
*/

// create_list() returns an empty newly-created list of students
// note: caller must free using free_list
struct slist * create_list();

// insert_student(id, name, lst) attempts to add a student with given id and
//   name into the given list lst; if a student with that id is already in the
//   list then return false, otherwise lst is modified and true is returned
bool insert_student(int id, char name[], struct slist * lst);

// remove_student(id, lst) attempts to remove a student with given id from the
//   given list and free the memory allocated to that student; true is returned
//   if successful and false otherwise
bool remove_student(int id, struct slist * lst);

// find_student(id, lst) returns the name of the student with given id in the
//   given list lst in a dynamically-allocated string (that the caller must
//   free) or NULL if no student has that id
char * find_student(int id, struct slist * lst);

// free_node(tofree) returns the pointer of the next node passed in
// and free's the memory associated with the node tofree
// Requires: tofree to point to memory allocated dynamically
struct snode * free_node(struct snode * tofree);

// free_list (lst) deallocates all memory associated with the given list lst
//   including the memory used by the student records in the list
void free_list(struct slist * lst);

// merge_lists(out, lst1, lst2) merges the student records from lst1 and lst2
//   into the list out with the students in sorted order;
//   lst1 and lst2 are then freed
// requires: out starts as an empty list
void merge_lists(struct slist * out, struct slist * lst1, struct slist * lst2);

// print_list(lst) prints the given lists id numbers to stdout
void print_list(struct slist * lst);

// check_order(lst) returns true if the list is sorted properly and false
// if it is not sorted
bool check_order(struct slist * lst);

/*
                               Question 2
                        _Structure Definitions_
---------------------------------------------------------------------------
*/

// Tree node holding the numeric value that a word compresses to
struct treenode {
  char word[10];
  int value;
  struct treenode * left;
  struct treenode * right;
};

// Tree node wrapper structure
struct treewrap {
  struct treenode * root;
};

/*
                              Question 2
                        _Function Prototypes_
---------------------------------------------------------------------------
*/

// insert_node(word, value, tree) inserts a new node containing the given word
//   and value into the tree with given root (or NULL denoting an empty tree)
//   returns the root node of the tree following the insert
// requires: word is not already in the given tree
//           tree satisfies the ordering property
struct treenode * insert_node(char word[], int value, struct treenode * tree);

// lookup_word(word, tree) returns the numeric value associated with the given
//   word in the given tree (or 0 if the word does not appear in the tree);
//   tree points to the root node or is NULL (denoting an empty tree)
// requires: tree satisfies the ordering property
int lookup_word(char word[], struct treenode * tree);

// free_tree(tree) frees all memory associated in the tree with given root node
void free_tree(struct treenode * tree);

// create_leaf() creates a node tree node and returns its pointer
// Requires: word to be at most 9 characters
struct treenode * create_leaf(char word[], int value);

/*
                               Question 1
                        _Function Implementations_
---------------------------------------------------------------------------
*/

// Implementation of create_list()
struct slist * create_list(){
    // Allocate memory to the new list
    struct slist * lst = malloc(sizeof(struct slist));
    // Set the first node to NULL as there are no elements yet
    lst->front = NULL;
    // Return the pointer to the newly created list
    return lst;
}

// Implementation of insert_student()
bool insert_student(int id, char name[], struct slist * lst){
    // Check case when it needs to be inserted into the front
    if(lst->front == NULL || id < lst->front->id){
      // Allocate memory for the new first node
      struct snode * firstnode = malloc(sizeof(struct snode));
      // Check for not enough memory
      if(firstnode == NULL){
        // Exit because memory could not be allocated
        exit(137);
      }
      // Assign it's elements
      firstnode->id = id; // The ID
      firstnode->name = malloc(strlen(name) + sizeof(char)); // Allocate memory for the name plus one for '/0'
      // Check for not enough memory
      if(firstnode->name == NULL){
        // Exit because memory could not be allocated
        exit(137);
      }
      strcpy(firstnode->name, name); // The name
      firstnode->next = lst->front; // Next pointer will be the current front
      lst->front = firstnode; // Set the front pointer to the first newly created instance
      // Return true for success
      return true;
    }
    // When it needs to be inserted in the middle or the end
    // Start with the first node in the list
    struct snode * curnode = lst->front;
    // Loop through each node in the list
    while(curnode){
      // If the id we are inserting is lower than the current
      if((curnode->next == NULL && curnode->id != id) || (curnode->id < id && id < curnode->next->id)){
        // Create new node for that student
        struct snode * newnode = malloc(sizeof(struct snode));
        // Make sure there was enough memory
        if(newnode == NULL){
          // Exit because memory could not be allocated
          exit(137);
        }
        // Assign the new nodes specified elements
        newnode->id = id; // The ID
        newnode->name = malloc(strlen(name) + 1); // Allocate memory for the name
        // Check for enough memory
        if(newnode->name == NULL){
          // Exit because there was not enough memory
          exit(137);
        }
        strcpy(newnode->name, name); // The name
        newnode->next = curnode->next; // Set next pointer
        curnode->next = newnode; // Set node before to point to newnode
        // Return true for success
        return true;
      }else if(curnode->id == id){
        // When there already is this id in the list return false
        return false;
      }
      // Move to the next node
      curnode = curnode->next;
    }
}

// Implementation of remove_student()
bool remove_student(int id, struct slist * lst){
    // Case when the student to remove is the first
    if(lst->front->id == id){
      // Temp variable to avoid memory leak
      struct snode * temp = lst->front;
      // Set the front to the next node
      lst->front = temp->next;
      // Free the now unlisted node
      free(temp->name); // Free the allocation for the name
      free(temp); // Free the allocation to the node
      // Return true for success
      return true;
    }
    // Case when the student to remove is the middle or last
    struct snode * curnode = lst->front;
    // Loop through list
    while(curnode){
      // If the ID has been found
      if(curnode->next != NULL && curnode->next->id == id){
        // Use temp variable to avoid memory leak
        struct snode * tempnode = curnode->next;
        // Relink the chain
        curnode->next = tempnode->next;
        // Free the memory
        free(tempnode->name); // Free the name allocation
        free(tempnode); // Free the node allocation
        // Return true for success
        return true;
      }
      // Go to the next node
      curnode = curnode->next;
    }
    // If there was no student with the given ID return false
    return false;
}

// Implementation of find_student()
char * find_student(int id, struct slist * lst){
    // Define a current node starting at the front
    struct snode * curnode = lst->front;
    // Loop through the list
    while(curnode){
      // When we have found the id
      if(curnode->id == id){
        // Return the name of that student
        return curnode->name;
      }
      // Go to the next node
      curnode = curnode->next;
    }
    // If no student is found
    return NULL;
}

// Implementation of free_node()
struct snode * free_node(struct snode * tofree){
    // Store next node before freeing the node
    struct snode * nextnode = tofree->next;
    // Free node
    free(tofree->name); // Free memory from the name string
    free(tofree); // Free the node
    // Return the next node pointer
    return nextnode; // If this is NULL the list is empty now
}

// Implementation of free_list()
void free_list(struct slist * lst){
    // Declare a variable for the current node
    struct snode * curnode = lst->front;
    // Loop through the list
    while(curnode){
      // Free the node and preserve the next node
      curnode = free_node(curnode);
    }
    // Free the list
    free(lst);
}

// Implementation of merge_lists()
void merge_lists(struct slist * out, struct slist * lst1, struct slist * lst2){
    // Define the current nodes for list 1 and list 2 and out
    struct snode * curnode1 = lst1->front;
    struct snode * curnode2 = lst2->front;
    struct snode * curnew;
    // Ensure that the lists given are not empty
    if(curnode1 != NULL && curnode2 != NULL){
      // Find the new lists front node by comparing list 1 and list 2's front
      if(curnode1->id < curnode2->id){
        // Set the front node as well as a tracker for the out list
        out->front = curnode1;
        curnew = out->front;
        // Go to the next node of curnode1
        curnode1 = curnode1->next;
      }else{
        // Set the front node as well as a tracker for the out list
        out->front = curnode2;
        curnew = out->front;
        // Go to the next node of curnode2
        curnode2 = curnode2->next;
      }
    }else if(curnode1 == NULL && curnode2){ // Only curnode1 was empty
      // Set the front node as well as a tracker for the out list
      out->front = curnode2;
      curnew = out->front;
      // Go to the next node of curnode2
      curnode2 = curnode2->next;
    }else if(curnode2 == NULL && curnode1){ // Only curnode2 was empty
      // Set the front node as well as a tracker for the out list
      out->front = curnode1;
      curnew = out->front;
      // Go to the next node of curnode1
      curnode1 = curnode1->next;
    }
    // Loop through the nodes while atleast one of the lists has not been exhausted
    while(curnode1 || curnode2){
      // Make sure they are not NULL
      if(curnode1 && curnode2){
        // If the current node 1 is smaller
        if(curnode1->id < curnode2->id){
          // Set the next node to curnode1
          curnew->next = curnode1;
          // Go to the next curnode1
          curnode1 = curnode1->next;
          // Go to the next curnew
          curnew = curnew->next;

        // If the current node 2 is smaller
        }else if(curnode2->id < curnode1->id){
          // Set the next node to curnode2
          curnew->next = curnode2;
          // Go to the next curnode2
          curnode2 = curnode2->next;
          // Go to the next curnew
          curnew = curnew->next;
        }
      }else if(curnode1){// When only curnode2 is NULL
        // Set the next node to curnode1
        curnew->next = curnode1;
        // Go to the next curnode1
        curnode1 = curnode1->next;
        // Go to the next curnew
        curnew = curnew->next;
      }else{ // When only curnode1 is NULL
        // Set the next node to curnode2
        curnew->next = curnode2;
        // Go to the next curnode2
        curnode2 = curnode2->next;
        // Go to the next curnew
        curnew = curnew->next;
      }
    }
    // Now that the new list out is merged and in order free the original two lists
    free(lst1);
    free(lst2);
}

// Implementation of print_list()
void print_list(struct slist * lst){
  struct snode * curnode = lst->front;
  while(curnode){
    printf("%d\n", curnode->id);
    curnode = curnode->next;
  }
}

// Implementation of check_order()
bool check_order(struct slist * lst){
  // Define the current node starting at the front
  struct snode * curnode = lst->front;
  // Make sure the list wasn't empty
  if(curnode == NULL){
    // An empty list is a sorted list
    return true;
  }
  // Loop through the list
  while(curnode->next){
    // If it's not sorted
    if(curnode->id > curnode->next->id){
      // Return false
      return false;
    }
    // Go to the next node
    curnode = curnode->next;
  }
  // Everything is in order so return true
  return true;
}

/*
                               Question 2
                        _Function Implementations_
---------------------------------------------------------------------------
*/

// Implementation of insert_node()
struct treenode * insert_node(char word[], int value, struct treenode * tree){
  // Check if it is empty
  if(tree == NULL){
    // make the root node
    tree = create_leaf(word, value);
  // When the given word is lower
  }else if(strcmp(word, tree->word) < 0){
    // If we have reached the end
    if(tree->left == NULL){
      // Create the new leaf here
      tree->left = create_leaf(word, value);
    }else{
      // Insert into next layer
      insert_node(word, value, tree->left);
    }
  // When the given word is higher
  }else if(strcmp(word, tree->word) > 0){
    // If we have reached the end
    if(tree->right == NULL){
      // Create the new leaf here
      tree->right = create_leaf(word, value);
    }else{
      // Insert into next layer
      insert_node(word, value, tree->right);
    }
  }
  // Return the root node
  return tree;
}

// Implementation of lookup_word() - For some reason it keeps returning 0 even if the words are found, I don't know why.
int lookup_word(char word[], struct treenode * tree){
  // If the tree is empty
  if(tree == NULL){
    // Tree is empty therefore the word is not in the tree
    return 0;
  // When we have found the word  
  }else if(strcmp(word, tree->word) == 0){
    // Return the number
    return tree->value;
  // Tree needs to go to the left
  }else if(strcmp(word, tree->word) < 0){
    // Lookup the ones to the left
    return lookup_word(word, tree->left);
  // Tree needs to go to the right
  }else if(strcmp(word, tree->word) > 0){
    // Lookup the ones to the right
    return lookup_word(word, tree->right);
  }
}

// Implementation of free_tree()
void free_tree(struct treenode * tree){
  // When the tree is empty
  if(tree == NULL){
    return;
  }
  // Free left side of current tree
  free_tree(tree->left);
  // Free right side of current tree
  free_tree(tree->right);
  // Free current tree
  free(tree);
}

// Implementation of create_leaf()
struct treenode * create_leaf(char word[], int value){
  // Allocate memory for the new leaf
  struct treenode * newleaf = malloc(sizeof(struct treenode));
  // Make sure the memory was allocated
  if(newleaf == NULL){
    // There was not enough memory
    exit(137);
  }
  // Store the given values
  strcpy(newleaf->word, word); // The word
  newleaf->value = value; // The number
  newleaf->right = NULL; // Leaves will have NULL
  newleaf->left = NULL; // right and left pointers

  // Return the new leaf's pointer
  return newleaf;
}

/*
                                _Main_
---------------------------------------------------------------------------
*/

// The main function
int main(void) {
  // Perform your testing here

  // Question 1

  // Making two lists with student data
  struct slist * my_list = create_list();
  insert_student(110042658, "Lucas Sarweh", my_list); // Inserting into an empty list
  insert_student(676543455, "Joe Shmoe", my_list); // Inserting at the end
  insert_student(345657454, "Chicken Vickens", my_list); // Inserting in the middle
  insert_student(865756466, "Todd Howard", my_list); // Inserting at the end
  insert_student(343243442, "Reggie Fils-aime", my_list); // Inserting in the middle
  struct slist * other_list = create_list();
  insert_student(420344344, "Tim Cook", other_list); // Inserting into an empty list
  insert_student(939838333, "Bill Gates", other_list); // Inserting at the end
  insert_student(209339933, "Phil Swift", other_list); // Inserting at the front
  insert_student(122230332, "Tom Bergeron", other_list); // Inserting at the front
  insert_student(725454354, "Kurt Cobaine", other_list); // Inserting in the middle
  // Testing find_student()
  assert(strcmp(find_student(110042658, my_list), "Lucas Sarweh") == 0); // Front
  assert(strcmp(find_student(345657454, my_list), "Chicken Vickens") == 0); // Middle
  assert(strcmp(find_student(725454354, other_list), "Kurt Cobaine") == 0); // Middle
  assert(strcmp(find_student(939838333, other_list), "Bill Gates") == 0); // End
  assert(find_student(323434300, other_list) == NULL); // Not in the list
  assert(find_student(744554311, my_list) == NULL); // Not in the list

  // Create an empty list to store the list merge
  struct slist * merger = create_list();
  // Merge the two lists
  merge_lists(merger, my_list, other_list);
  // Make sure it is in order
  assert(check_order(merger));
  // Print it's id's for fun
  print_list(merger);

  // Create empty lists
  struct slist * empty_list1 = create_list();
  struct slist * empty_list2 = create_list();
  struct slist * empty_list3 = create_list();
  // Test case when merge_lists takes two empties
  merge_lists(empty_list3, empty_list1, empty_list2);
  assert(check_order(empty_list3));

  // Create empty lists
  struct slist * single_list1 = create_list();
  struct slist * single_list2 = create_list();
  struct slist * single_list3 = create_list();
  // Put one student record in 1 and 2
  insert_student(5229388, "Carl Sagin", single_list1);
  insert_student(3931223, "Bob Baby", single_list2);
  // Test case when merge_lists take two with only one element
  merge_lists(single_list3, single_list1, single_list2);
  assert(check_order(single_list3));

  // Free all the lists and its data
  free_list(merger);
  free_list(empty_list3);
  free_list(single_list3);

  // Question 2

  // Tree structure wrapper initialization
  struct treewrap * my_tree = malloc(sizeof(struct treewrap));
  my_tree->root = NULL;
  // Temp variable for reading from user
  char temp[10];
  // New number generator for new words
  int new_value = 1;
  // Make sure scanf succeeds
  int success = 0;

  while(true){
    // Enter the prompt
    printf("%s", "Enter a word or a period to exit: ");
    // Get the input
    success = scanf("%s", temp);
    // If scanf reads a single period
    if(success && strcmp(".", temp) == 0){
      // Print the period
      printf("%s\n", ".");
      // Exit we are done
      break;
    }
    // scanf reading words
    else if(success){
      // Check if this has been seen before
      if(lookup_word(temp, my_tree->root) != 0){
        // When it has been seen print it's number to the screen
        printf("%d\n", lookup_word(temp, my_tree->root));
      }else{
        // The word has not been seen yet so insert it into the tee and give it a number
        insert_node(temp, new_value, my_tree->root);
        new_value += 1; // Increment the value for the next word
        // Print the new word onto the screen
        printf("%s\n", temp);
      }
    }
  }
  if(my_tree->root != NULL){
    // Free the tree nodes
    free_tree(my_tree->root);
  }
  // Free the wrapper
  free(my_tree);

  // Testing lookup_word()

  struct treewrap * test_tree = malloc(sizeof(struct treewrap));
  test_tree->root = NULL;

  // Case when list is empty
  assert(lookup_word("hello", test_tree->root) == 0);

  // Inserting words
  insert_node("hey", 1, test_tree->root);
  insert_node("tommy", 2, test_tree->root);
  insert_node("pi", 3, test_tree->root);

  assert(lookup_word("hey", test_tree->root) == 1); // Word at front
  assert(lookup_word("tommy", test_tree->root) == 2); // Word in middle
  assert(lookup_word("pi", test_tree->root) == 3); // Word at end
  assert(lookup_word("chalice", test_tree->root) == 0); // Word doesn't exist

  // Free memory
  free_tree(test_tree->root);
  free(test_tree);

  printf("%s\n", "All tests have passed successfully!");
}