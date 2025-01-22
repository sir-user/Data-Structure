#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


int main(){
    printf("***************************\n***************************\n");

    Tree_Node_Doubly *root = NULL;
    
    t_create_from_input(&root, 1, 1, 20);

    t_in_order_traversal(root);

    printf("\n");

    t_level_order_traversal(root);

    bst_delete_element(&root, 20);

    printf("AFTER REMOVING\n");

    t_in_order_traversal(root);

    printf("\n");

    t_level_order_traversal(root);

    printf("\n");
    return 0;
}


