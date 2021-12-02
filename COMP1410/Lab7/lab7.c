/* ===========================================================================
COMP-1410 Lab 7
==============================================================================
Student name: Lucas Sarweh

Replace the error with a statement citing any sources of outside help:
None


=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

// Linked list node storing a string of at most 4 characters
struct strnode {
  char str[5];
  struct strnode * next;
};

// Linked list
struct llist {
    struct strnode * first;
};

// This creates an empty linked list
// The memory allocated from this must be freed
struct llist * llist_create(void);

// This frees everything in a linked list allocated
// using dynamic memory
void llist_destroy(struct llist * lst);

// This prints out the strings of a given linked list
// Note: I made this before reading what concat_nodes() does
void print_llist(struct llist * list);

// This takes a given llist and creates 26 nodes
// with their string elements a letter in order from
// A - Z the head being A and the tail being Z
void make_alphabet(struct llist * lst);

// create_node(str, next) creates a strnode containing the string str
//   and given next pointer; caller must free allocated memory using free_node
// requires: str has length at most 4
//           next is NULL or points to a strnode
// note: returns NULL if memory cannot be allocated
struct strnode * create_node(char str[], struct strnode * next);

// free_node(node) frees the memory associated with the given node; returns a
//   pointer to the next node in the list previously headed by the given node
// requires: node is a valid strnode allocated dynamically
struct strnode * free_node(struct strnode * node);

// concat_nodes(head, str) modifies str to be a string representation of the
//   contents of the list with given head
// requires: str points to enough memory to store the output string
//           head is NULL or points to a strnode
void concat_nodes(struct strnode * head, char * str);

// Implementation of llist_create()
struct llist * llist_create(void){
    struct llist * newlist = malloc(sizeof(struct llist));
    newlist->first = NULL;
    return newlist;
}

// Implementation of llist_destroy()
void llist_destroy(struct llist * lst){
    // Get the head node
    struct strnode * curnode = lst->first;
    // Var for assertion
    struct strnode * tempsert = malloc(sizeof(struct strnode));
    // While there are still nodes
    while(curnode){
        // This is for asserting required on free_node()
        tempsert = curnode->next;
        // Free the node while getting the next node
        curnode = free_node(curnode); // The function returns the next pointer in the list
        // Assert to make sure the deleted node->next is the same as the next node
        assert(tempsert == curnode);
    }
    // Free the tempsert just incase it already isn't NULL
    free(tempsert);
    // Free the list now that it has no nodes
    free(lst);
}

// Implementation of print_llist()
void print_llist(struct llist * list){
    // Make temp to go through the llist
    
    // While we are still going through
    while(list->first){
        // Print the current nodes string
        printf("%s ", list->first->str);
        // Go to the next node
        list->first = list->first->next;
    }
    // Newline for the next printf()
    puts("");
}

// Implementation of make_alphabet()
void make_alphabet(struct llist * lst){
    // Allocate the arrays to concatenate
    char * alph = malloc(sizeof(char) * 2);
    alph[0] = 'Z'; // Z is the begging because the llink will go backwards
    alph[1] = '\0'; // Null terminator to make a string because create_node() requires a string
    // Create a new node 26 times
    for(int i = 0; i < 26; i++){
        // Add current letter to the str of the current node
        lst->first = create_node(alph, lst->first);
        // The letter will go from Z - A
        alph[0] -= 1;
    }
    // Free alph allocated dynamically
    free(alph);
}

// Implementation of create_node()
struct strnode * create_node(char str[], struct strnode * next){
    // Allocate memory for the new node
    struct strnode * new_node = malloc(sizeof(struct strnode));
    // Make sure there was enough memory
    if(new_node == NULL){
        // Return Null
        return NULL;
    }
    // Assign the str and the next pointer
    strcpy(new_node->str, str);
    new_node->next = next;

    // Return the pointer to the new node
    return new_node;
}

// Implementation of free_node()
struct strnode * free_node(struct strnode * node){
    // Store next node before freeing node
    struct strnode * nextnode = node->next;
    // Free node
    free(node);
    // Return the next node pointer
    return nextnode; // If this is NULL the list is empty now
}

// Implementation of concat_nodes()
void concat_nodes(struct strnode * head, char * str){
    // Set current node to beggining
    struct strnode * curnode = head;
    // While still going through the llist
    while(curnode){
        // Concatenate string of current node into str
        for(int i = 0; i < strlen(curnode->str); i++, str++){
            *str = *((curnode->str) + i);
        }
        // Add a space
        if(curnode->next != NULL){
            *str = ' ';
            str++;
        }
        // Switch to the next node
        curnode = curnode->next;
    }
    // Null terminate because it should be a string
    *str = '\0';
}

int main(void) {

    // Implement your test code here
    struct llist * my_list = llist_create(); // Create the linked list
    my_list->first = NULL; // Set first node to NULL
    char * my_string = malloc(sizeof(char) * 100); // Create a string for concat_nodes()
    
    // Testing create_node()
    // Creating instances
    my_list->first = create_node("Hello", my_list->first);

    my_list->first = create_node("my", my_list->first);

    my_list->first = create_node("name", my_list->first);

    my_list->first = create_node("is", my_list->first);

    my_list->first = create_node("Lucas", my_list->first);

    // Concatenating the list node strings
    concat_nodes(my_list->first, my_string);
    // Checking if it is correct
    assert(strcmp(my_string, "Lucas is name my Hello") == 0);
    // Freeing the memory
    llist_destroy(my_list);
    // Free the string
    free(my_string);
    
    struct llist * test1 = llist_create(); // Create the linked list
    test1->first = NULL; // Set first node to NULL
    char * new_string = malloc(sizeof(char) * 100); // Create a string for concat_nodes()

    // Create an instance
    test1->first = create_node("E", test1->first);

    // Case for concat_nodes() when there is only one element
    concat_nodes(test1->first, new_string);
    // Making sure it is correct
    assert(strcmp(new_string, "E") == 0);

    // Freeing memory
    free(new_string);
    llist_destroy(test1);

    // New instance
    struct llist * tester = llist_create(); // Create the linked list
    tester->first = NULL; // Set first node to NULL
    char * otherstring = malloc(sizeof(char) * 100); // Create a string for concat_nodes()

    // Adding instances
    tester->first = create_node("He,,.-=1", tester->first); // Non letter characters

    tester->first = create_node("  ", tester->first); // Spaces

    tester->first = create_node("\n", tester->first); // Newline

    tester->first = create_node("600", tester->first); // Numbers

    // other things to test concat_nodes() for
    concat_nodes(tester->first, otherstring);
    // Make sure it is correct
    assert(strcmp(otherstring, "600 \n    He,,.-=1") == 0);
    // Free the string
    free(otherstring);
    // Free the llist
    llist_destroy(tester); // I assert free_node()'s return value inside this function

    // Alphabet Testing
    struct llist * test2 = llist_create(); // Create the new linked list
    test2->first = NULL; // Set first node to NULL
    char * string2 = malloc(sizeof(char) * 100); // Create a string for concat_nodes()
    
    // Make the nodes strings the alphabet
    make_alphabet(test2);
    // Concate the nodes strings into string2
    concat_nodes(test2->first, string2);
    // Print the string
    printf("%s\n", string2);
    
    // Free the string and the llist
    free(string2);
    llist_destroy(test2);

    printf("All tests passed successfully.\n");
}