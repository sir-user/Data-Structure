#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "colors.h"
#include "queue.h"

typedef struct Tree_Node_D
{
    int data;
    struct Tree_Node_D *left_child;
    struct Tree_Node_D *right_child;
}Tree_Node_Doubly;


static Tree_Node_Doubly *t_create_node(int data);

void t_insert_node_lo(Tree_Node_Doubly **root, int data);

void t_insert_element(Tree_Node_Doubly **root, int data, int place);

void t_create_from_level_order(Tree_Node_Doubly **root, int amount, ...);

int t_count(Tree_Node_Doubly *root);

int t_height(Tree_Node_Doubly *root);

void t_level_order_traversal(Tree_Node_Doubly *root);

void t_pre_order_traversal(Tree_Node_Doubly* root);

void t_in_order_traversal(Tree_Node_Doubly* root);

void t_post_order_traversal(Tree_Node_Doubly* root);




#endif