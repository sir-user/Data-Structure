#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "colors.h"
#include "queue.h"

// Element structure
typedef struct Tree_Node_D
{
    int data;
    struct Tree_Node_D *left_child;
    struct Tree_Node_D *right_child;
}Tree_Node_Doubly;

// Common for binary tree and binary search trees
static Tree_Node_Doubly *t_create_node(int data);                          // Creates Nodes

// Below 2 functions are for only binary trees
void t_insert_node_lo(Tree_Node_Doubly **root, int data);                  // Inserts datas in level order
 
void t_insert_element(Tree_Node_Doubly **root, int data, int place);       // Inserts elements to particular node

// Below 2 functions are for only binary search trees 
Tree_Node_Doubly *bst_search(Tree_Node_Doubly *root, int key);

void bst_insert(Tree_Node_Doubly **root, int data);

// All below are common for binary tree and binary search trees
void t_create_from_input(Tree_Node_Doubly **root, int bst, int amount, ...);  // Inserts multiple datas at once, does not matter if the array is empty 

int t_count(Tree_Node_Doubly *root);                                       // Returns amount of elements. Recursive Function

int t_height(Tree_Node_Doubly *root);                                      // Returns height of tree. Recursive Function

void t_level_order_traversal(Tree_Node_Doubly *root);                      // Display in level order

void t_pre_order_traversal(Tree_Node_Doubly *root);                        // Display pre order

void t_in_order_traversal(Tree_Node_Doubly *root);                         // Display in order

void t_post_order_traversal(Tree_Node_Doubly *root);                       // Display post order

void bst_delete_element(Tree_Node_Doubly **root, int data);

#endif