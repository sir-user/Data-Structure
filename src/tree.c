#include "tree.h"

static Tree_Node_Doubly *t_create_node(int data){
    Tree_Node_Doubly *new_node = (Tree_Node_Doubly *)malloc(sizeof(Tree_Node_Doubly));
    if(new_node == NULL){
        printf(FOREGRN);
        for(int i = 1; i<4; i++){
            printf("[INFO] Retrying memory allocation... Attemp %d!\n", i);
            new_node = (Tree_Node_Doubly *)malloc(sizeof(Tree_Node_Doubly));
            if (new_node) break;
        }
        if(new_node == NULL){
            printf(FORERED);
            printf("[ERROR] Malloc Failed! Node couldn't created\n");
            printf(RESETTEXT);
            return NULL;
        }
        printf("[INFO] Malloc Succeeded!\n");
        printf(RESETTEXT);
    }
    new_node->data = data;
    new_node->left_child = NULL;
    new_node->right_child= NULL;
    return new_node;
}

void t_insert_node_lo(Tree_Node_Doubly **root, int data){
    Tree_Node_Doubly *new_node = t_create_node(data);

    if (new_node == NULL) {
        printf(FORERED);
        printf("[ERROR] Node couldn't created! Inserting terminated\n");
        printf(RESETTEXT);
        return;
    }

    if (*root == NULL) { // If tree is empty
        *root = new_node;
    }
    else{
        Queue_ll *queue = q_ll_create_queue();
        q_ll_enqueue(queue, *root); // Enqueue the root-node

        while (!q_ll_is_empty(queue)) {
            Tree_Node_Doubly *current = q_ll_dequeue(queue);

            // Check the left child
            if (current->left_child == NULL) {
                current->left_child = new_node;
                break;
            } else {
                q_ll_enqueue(queue, current->left_child);
            }

            // Check the right child
            if (current->right_child == NULL) {
                current->right_child = new_node;
                break;
            } else {
                q_ll_enqueue(queue, current->right_child);
            }
        }
    }
}

void t_insert_element(Tree_Node_Doubly **root, int data, int place){
    Tree_Node_Doubly *new_node = t_create_node(data);

    if (new_node == NULL) {
        printf(FORERED);
        printf("[ERROR] Node couldn't created! Inserting terminated\n");
        printf(RESETTEXT);
        return;
    }

    if (!place && (*root)->left_child == NULL ) {
        (*root)->left_child = new_node;
    }
    else if (place && (*root)->right_child == NULL) {
        (*root)->right_child = new_node;
    }
}

void t_create_from_level_order(Tree_Node_Doubly **root, int amount, ...) {
    va_list args;
    va_start(args, amount); 

    for (int i = 0; i < amount; i++) {
        t_insert_node_lo(root, va_arg(args, int)); 
    }

    va_end(args);
}

int t_count(Tree_Node_Doubly *root){
    // return root ? t_count(root->left_child) + t_count(root->right_child) + 1 : 0
    if (root == NULL){
        return 0;
    }
    int x, y;
    x = t_count(root->left_child);
    y = t_count(root->right_child);
    return x + y + 1;
}

int t_height(Tree_Node_Doubly *root){
    if (root == NULL){
        return 0;
    }        
    int x, y;
    x = t_height(root->left_child);
    y = t_height(root->right_child);
    return x > y ? x + 1: y + 1;

}

// Display Functions
void t_level_order_traversal(Tree_Node_Doubly *root){
    if (root == NULL) {
        printf(FOREYEL);
        printf("[ERROR] Tree is empty, nothing to print!\n");
        printf(RESETTEXT);
        return;
    }

    Queue_ll *queue = q_ll_create_queue();

    q_ll_enqueue(queue, root);

    printf("Level Order: ");
    while (!q_ll_is_empty(queue)) {
        Tree_Node_Doubly *current = q_ll_dequeue(queue);
        printf("%d ", current->data);

        if (current->left_child != NULL) {
            q_ll_enqueue(queue, current->left_child);
        }
        if (current->right_child != NULL) {
            q_ll_enqueue(queue, current->right_child);
        }
    }
    printf("\n");
}

void t_pre_order_traversal(Tree_Node_Doubly* root){
    if (root == NULL){
        printf(FOREYEL);
        printf("[WARNING] Tree is empty, nothing to print!\n");
        printf(RESETTEXT);
        return;
    }
    printf("%d ", root->data); 
    t_pre_order_traversal(root->left_child); 
    t_pre_order_traversal(root->right_child);
}

void t_in_order_traversal(Tree_Node_Doubly* root){
    if (root == NULL){
        printf(FOREYEL);
        printf("[WARNING] Tree is empty, nothing to print!\n");
        printf(RESETTEXT);
        return;
    }
    t_in_order_traversal(root->left_child); 
    printf("%d ", root->data); 
    t_in_order_traversal(root->right_child);

}

void t_post_order_traversal(Tree_Node_Doubly* root){
    if (root == NULL){
        printf(FOREYEL);
        printf("[WARNING] Tree is empty, nothing to print!\n");
        printf(RESETTEXT);
        return;
    }
    t_post_order_traversal(root->left_child); 
    t_post_order_traversal(root->right_child);
    printf("%d ", root->data); 
}

