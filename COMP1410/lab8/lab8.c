/* ===========================================================================
COMP-1410 Lab 8
==============================================================================
Student name: Lucas Sarweh

Replace the error with a statement citing any sources of outside help:
None

=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// Tree node storing an integer
struct node {
  int item;
  struct node * left;
  struct node * right;
};

// create_node(item, left, right) creates and returns a tree node containing
//   given item and left/right pointers; caller must free allocated memory
// requires: left, right are NULL or point to tree nodes
// note: returns NULL if memory cannot be allocated
struct node * create_node(int item, struct node * left, struct node * right);

// free_tree(node) frees the memory associated with the given node and
//   all of the node's children
// requires: root is the root of a tree allocated dynamically
void free_tree(struct node * root);

// height(root) returns the height of the tree with given root
// requires: root is NULL or points to a tree node
int height(struct node * root);

// num_leaves(root) returns the number of leaf nodes in the tree with
//   given root
// requires: root is NULL or points to a tree node
int num_leaves(struct node * root);

// max(first, second) returns the largest between first and second
int max(int first, int second);

// Implementation of create_node(item, left, right)
struct node * create_node(int item, struct node * left, struct node * right){
    // Allocate memory for the new node
    struct node * new_node = malloc(sizeof(struct node));
    // Make sure malloc succeeded
    if(new_node == NULL){
        return NULL;
    }
    // Memory was allocated and now set the attributes
    new_node->item = item;
    new_node->left = left;
    new_node->right = right;
    // Return the new node
    return new_node;
}

// Implementation of free_tree(root)
void free_tree(struct node * root){
    // When the node is NULL
    if(root == NULL){
        return;
    }
    // Free the memory allocated with the right and left nodes
    free_tree(root->left);
    free_tree(root->right);
    // Free the current root node
    free(root);
}

// Implementation of height(root)
int height(struct node * root){
    // When We have reached the end of the current path
    if(root == NULL){
        // Return 0
        return 0;
    }
    // Return the maximum between all paths; adding one increments
    // how many nodes are in that path
    return max(height(root->left), height(root->right)) + 1;
}

// Implementation of num_leaves(root)
int num_leaves(struct node * root){
    // When a node has only one child this will catch the NULL one
    if(root == NULL){
        return 0;
    }
    // We have reached a leaf so return 1 for 1 more leaf
    else if(root->left == NULL && root->right == NULL){
        return 1;
    }
    // Node in the middle of the tree will return the right and left node's number of leaves
    return num_leaves(root->left) + num_leaves(root->right);
}

// Implementation of max(first, second)
int max(int first, int second){
    if(first <= second){
        return second;
    }else{
        return first;
    }
}

int main(void) {
  // Implement your test code here
  // Create the nodes from the example picture
  struct node * node1 = create_node(10, NULL, NULL);
  // Test tree with only a root
  assert(height(node1) == 1);
  assert(num_leaves(node1) == 1);

  struct node * node2 = create_node(30, NULL, NULL);
  struct node * node3 = create_node(20, node1, node2);
  struct node * node4 = create_node(60, NULL, NULL);
  struct node * node5 = create_node(50, NULL, node4);
  struct node * root_node = create_node(40, node3, node5);
  // Test the height
  assert(height(root_node) == 3);
  // Test the number of leaves
  assert(num_leaves(root_node) == 3);
  // Test tree without any elements
  assert(height(NULL) == 0);
  assert(num_leaves(NULL) == 0);
  // Free the nodes
  free_tree(root_node);

  // New instances for worst case tree
  struct node * unbalanced_one = create_node(5, NULL, NULL);
  struct node * unbalanced_two = create_node(15, unbalanced_one, NULL);
  struct node * unbalanced_three = create_node(30, unbalanced_two, NULL);
  struct node * unbalanced_root = create_node(50, unbalanced_three, NULL);
  // Test unbalanced tree
  assert(height(unbalanced_root) == 4);
  assert(num_leaves(unbalanced_root) == 1);
  // Free the tree
  free_tree(unbalanced_root);
  printf("All tests passed successfully.\n");
}