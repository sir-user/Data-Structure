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
        printf(FOREYEL);
        printf("[WARNING] Node couldn't created! Inserting terminated\n");
        printf(RESETTEXT);
        return;
    }

    if (!place && (*root)->left_child == NULL) {
        (*root)->left_child = new_node;
    }
    else if (place && (*root)->right_child == NULL) {
        (*root)->right_child = new_node;
    }
    else{
        printf(FOREYEL);
        printf("[WARNING] Node couldn't inserted! child is full\n");
        printf(RESETTEXT);
    }
}

Tree_Node_Doubly *bst_search(Tree_Node_Doubly *root, int key){
    while (root != NULL){
        if (key == root->data){
            return root;    // match
        }
        else if (key < root->data){
            root = root->left_child;
        }
        else{
            root = root->right_child;
        }
    }
    return NULL;    //No match
}

void bst_insert(Tree_Node_Doubly **root, int data){
    Tree_Node_Doubly *new_node = t_create_node(data);

    if (new_node == NULL) {
        printf(FOREYEL);
        printf("[WARNING] Node couldn't created! Inserting terminated\n");
        printf(RESETTEXT);
        return;
    }

    if (*root == NULL) { // If tree is empty, new_node is the first element
        *root = new_node;
    }
    else{
        Tree_Node_Doubly *current = (*root), *temp = NULL;
        while(current != NULL){
            temp = current;
            if(data == current->data){
                return; // Already exist, no inserting!
            }
            else if (data < current->data){
                current = current->left_child;
            }
            else{
                current = current->right_child;
            }
        }
        if (temp->data > data){
            temp->left_child = new_node;
        }
        else{
            temp->right_child = new_node;
        }
    }
}

void t_create_from_input(Tree_Node_Doubly **root, int bst, int amount, ...) {
    va_list args;
    va_start(args, amount); 

    if (bst){
        for (int i = 0; i < amount; i++) {
            bst_insert(root, va_arg(args, int)); 
        }
    }
    else{
        for (int i = 0; i < amount; i++) {
            t_insert_node_lo(root, va_arg(args, int)); 
        }
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

void t_pre_order_traversal(Tree_Node_Doubly *root){
    if (root != NULL){
        printf("%d ", root->data); 
        t_pre_order_traversal(root->left_child); 
        t_pre_order_traversal(root->right_child);
    }
}

void t_in_order_traversal(Tree_Node_Doubly *root){
    if (root != NULL){
        t_in_order_traversal(root->left_child); 
        printf("%d ", root->data); 
        t_in_order_traversal(root->right_child);
    }
}

void t_post_order_traversal(Tree_Node_Doubly *root){
    if (root != NULL){
        t_post_order_traversal(root->left_child); 
        t_post_order_traversal(root->right_child);
        printf("%d ", root->data); 
    }
}

void bst_delete_element(Tree_Node_Doubly **root, int data){
    Tree_Node_Doubly *current = (*root), *current_parent = (*root);

    // Finding element
    while (current != NULL){
        if (data == current->data){
            break;// match
        }
        else if (data < current->data){
            current_parent = current;
            current = current->left_child;
        }
        else{
            current_parent = current;
            current = current->right_child;
        }
    }

    printf("Element found ! Current : %d  -  Current's parent  %d\n", current->data, current_parent->data);

    
    // Delete section
    if (current->left_child == NULL && current->right_child == NULL){ // No child
        // Just delete the node 
        if (current_parent->left_child == current){
            current_parent->left_child = NULL;
        }
        else if (current_parent->right_child == current){
            current_parent->right_child = NULL;
        }
        else if (current_parent == current){
            *root = NULL;
        }
        free(current);
    }
    else if (current->left_child && !(current->right_child) || !(current->left_child) && current->right_child){ // There is only 1 child
        // Connect it to parent directly
        if (current_parent->left_child == current){
            if (current->left_child){
                current_parent->left_child = current->left_child;
            }
            else if (current->right_child){
                current_parent->left_child = current->right_child;
            }
        }
        else if (current_parent->right_child == current){
            if (current->left_child){
                current_parent->right_child = current->left_child;
            }
            else if (current->right_child){
                current_parent->right_child = current->right_child;
            }     
        }
        else if (current_parent == current){
            if (current->left_child){
                (*root) = current->left_child;
            }
            else if (current->right_child){
                (*root) = current->right_child;
            }   
        }
        free(current);
    }
    else if(current->left_child && current->right_child){ // There are 2 child
        // find the closest value and handle the connections
        Tree_Node_Doubly *predecessor = current, *predecessor_parent = current; // we will not lose the found element which will be deleted (current), predecessor will be used to find the closest value to replace it with current, predecessor_parent will hold the predecessor's parent to handle the connection predecessor_parent->predecessor
        
        if (predecessor->left_child != NULL){
            predecessor = predecessor->left_child;
        }
        while(predecessor != NULL){  // we will break it after we detect the predecessor, predecessor_parent is following it one behind as predecessor's parent
            if (predecessor->right_child == NULL){
                break;
            }
            predecessor_parent = predecessor;
            predecessor = predecessor->right_child;
        }

        // Replace predecessor with current 
        if (current_parent->left_child == current){
            current_parent->left_child = predecessor;
        }
        else if (current_parent->right_child == current){
            current_parent->right_child = predecessor;            
        }

        // Remove predecessor from it's current place and connect predecessor's child to predecessor_parent
        if (predecessor_parent->left_child == predecessor){
            predecessor_parent->left_child = predecessor->left_child;
        }
        else if (predecessor_parent->right_child == predecessor){
            predecessor_parent->right_child = predecessor->left_child;            
        }

        // Connect current's childs to predecessor as its childs  
        predecessor->right_child = current->right_child;
        predecessor->left_child = current->left_child;

        // Special condition, if the data will be deleted is root
        if (current_parent == current){
            (*root) = predecessor;
        }
        
        free(current);        
    }
}