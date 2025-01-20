#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


int main(){
    printf("***************************\n***************************\n");
    // Create the queue in main
    //Queue_ll *queue = q_ll_create_queue();

    // Create the binary tree
    Tree_Node_Doubly *root = NULL;
    t_create_from_level_order(&root, 11, 10, 20, 30, 21, 22, 31, 32, 211, 212, 221, 222);

    /*
    t_insert_node_lo(&root, 10);
    t_insert_element(&root, 15, 0);
    t_insert_element(&root, 16, 1);
    t_insert_element(&(root->left_child), 37, 0);
    t_insert_element(&(root->left_child), 38, 1);
    t_insert_node_lo(&root, 20);
    t_insert_node_lo(&root, 30);
    t_insert_node_lo(&root, 40);
    t_insert_node_lo(&root, 50);
    t_insert_node_lo(&root, 60);
    
    */
    
    printf("Number of Elements : %d\n", t_count(root));
    printf("Height of Tree     : %d\n", t_height(root));

    t_level_order_traversal(root);
    
    printf("Pre-order: ");
    t_pre_order_traversal(root);
    printf("\n");
    printf("In-order: ");
    t_in_order_traversal(root);
    printf("\n");
    printf("Post-order: ");
    t_post_order_traversal(root);
    printf("\n");
    
    printf("%d ", root->data);

    printf("%d ", root->left_child->data);
    printf("%d ", root->right_child->data);

    printf("%d ", root->left_child->left_child->data);
    printf("%d ", root->left_child->right_child->data);
    printf("%d ", root->right_child->left_child->data);
    printf("%d ", root->right_child->right_child->data);
    
    printf("%d ", root->left_child->left_child->left_child->data);
    printf("%d ", root->left_child->left_child->right_child->data);
    printf("%d ", root->left_child->right_child->left_child->data);
    printf("%d ", root->left_child->right_child->right_child->data);
    
    printf("\n");
    return 0;
}


