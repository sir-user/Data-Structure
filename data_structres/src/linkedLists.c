#include "linkedLists.h"

struct Node_Singly *ll_create_single_from_arr(int arr[], int n){
    /*
    * @brief     Creates an singly linked list from an array.
    */
    struct Node_Singly *head, *t, *last;
    head=(struct Node_Singly *)malloc(sizeof(struct Node_Singly));
    head->data = arr[0];
    head->next = NULL;
    last = head;
    for (int i = 1; i < n; i++){
        t = (struct Node_Singly *)malloc(sizeof(struct Node_Singly));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return head;
}

void ll_display_single(struct Node_Singly *head){
    /*
    * @brief     Prints whole linked list.
    */
    printf("Nodes : ");
    while (head!=NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int ll_count_singly(struct Node_Singly *head){
    /*
    * @brief     Returns number of nodes in linked list.
    */
    int amount = 0;
    while (head!=NULL)
    {
        amount ++;
        head = head->next;
    }
    return amount;
}

int ll_maxofll_singly(struct Node_Singly *head){
    /*
    * @brief     Returns greatest value in linked list.
    */
    int max = INT_MIN;
    while (head!=NULL)
    {
        max = (max < head->data) ? head->data : max;
        head = head->next;
    }
    return max;
}

struct Node_Singly *ll_linear_search_singly(struct Node_Singly *head, int value){
    /*
    * @brief     Returns first node found you looked for.
    */
    while (head!=NULL)
    {
        if (head->data == value)
            return head;
        head = head->next;
    }
    return NULL;
}

void ll_move_to_head_singly(struct Node_Singly **head, int value){
    /*
    * @brief     Replaces the first node found looked for to head.
    */

    if (*head == NULL || (*head)->data == value) {
        return;
    }
    struct Node_Singly *prev = NULL, *current = *head;
    while (*head!=NULL)
    {
        if (current->data == value){
            prev->next = current->next;
            current->next = *head;
            *head = current;
            break;
        }   
        prev = current;         
        current = current->next;
    }
}

void ll_insert_singly(struct Node_Singly **head, int value, int index){
    /*
    * @brief     Inserts a node to index given.
    */
    assert(index>=0);

    struct Node_Singly *new_node = NULL, *prev = NULL, *current = *head;
    new_node=(struct Node_Singly *)malloc(sizeof(struct Node_Singly));
    new_node->data = value;

    if (index == 0){
        new_node->next = *head;
        *head = new_node; 
        return;
    }

    int i = 0;
    while (current!=NULL && i<index){        
        prev = current;         
        current = current->next;
        i++;
    }
    
    if (i==index){
            new_node->next = current;  
            prev->next = new_node;      
    }
    else {
        printf(FORERED);
        printf("[ERROR] Index out of bounds, could not inserted.\n");
        printf(RESETTEXT);
        free(new_node);  // Free the allocated memory for the new node
    }
}   

void ll_delete_singly(struct Node_Singly **head, int index){
    /*
    * @brief     Removes the node on the given index.
    */
    assert(index>=0);

    struct Node_Singly *prev = NULL, *current = *head;

    if (index == 0){
        *head = (*head)->next;
        return;
    }

    int i = 0;
    while (current!=NULL && i<index){        
        prev = current;         
        current = current->next;
        i++;
    }
    
    if (i==index){
            prev->next = current->next;
            free(current);    
    }
    else {
        printf(FORERED);
        printf("[ERROR] Index out of bounds.\n");
        printf(RESETTEXT);
    }
}

void ll_reverse_singly(struct Node_Singly **head){
    /*
    * @brief     Reverses the whole linked list. 
    */
    struct Node_Singly *prev = NULL, *next = NULL, *current = *head;

    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;  
    }
    *head = prev;
}

void ll_merge_singly(struct Node_Singly **first, struct Node_Singly **second){
    /*
    * @brief     Merges linked lists into first.
    */
    struct Node_Singly *current = *first;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (*second);
}

void ll_sort_ll_singly(struct Node_Singly **head){
    /*
    * @brief     
    */
    assert((*head) != NULL && (*head)->next != NULL && "should not be empty or single node");

    struct Node_Singly *current = NULL, *next = NULL;

    int swapped, temp;  

    do {
        swapped = 0;
        current = *head;

        while (current->next != NULL) {
            next = current->next;
            if (current->data > next->data) {
                temp = current->data;
                current->data = next->data;
                next->data = temp;

                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

bool ll_is_it_sorted_singly(struct Node_Singly *head){
    /*
    * @brief     Returns true or false depends on if it is sorted linked list.
    */
    if (head == NULL || head->next == NULL) {
        return false; 
    }

    struct Node_Singly *prev = NULL, *current = head;

    prev = current;

    while(current->next != NULL){
        if (current->data < prev->data){
            return false;
        }
        prev = current;
        current = current -> next;
    }    
    return true;
}

void ll_merge_sorted_singly(struct Node_Singly **merged, struct Node_Singly *first, struct Node_Singly *second){
    /*
    * @brief     Merges already sorted 2 linked lists into first paramater(merged). 
    */

    assert(first != NULL && second != NULL && "should not be empty or single node");

    if (first->data < second->data){
        (*merged) = first;
        first = first->next;
    }
    else if (first->data >= second->data){
        (*merged) = second;
        second = second->next;
    }
    
    struct Node_Singly *head_merged = *merged;

    while(first != NULL && second != NULL){
        if (first->data < second->data){
            (*merged)->next = first;
            *merged = (*merged)->next;
            first = first->next;
        }
        else if (first->data >= second->data){
            (*merged)->next = second;
            *merged = (*merged)->next;
            second = second->next;
        }
    }
    if (first != NULL){
        (*merged)->next = first;   
    }
    else if (second != NULL){
        (*merged)->next = second;
    }
    *merged = head_merged;
}

bool ll_is_it_circular_singly(struct Node_Singly *head){
    /*
    * @brief     Floyd's Cycle Detection
    *           There are slow and fast pointers they moves along the linked list.
    *           If there is a cycle, they will eventually come across with each other.
    */
    struct Node_Singly *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1;
        }
    }
    return 0; 
}

void ll_display_circular_singly(struct Node_Singly *head){
    /*
    * @brief     Prints an whole circular array. Head to tail to head
    */
    
    assert(head!=NULL);

    struct Node_Singly *head_keeper = head;

    printf("Nodes : ");
    do{
        printf("%d ", head->data);
        head = head->next;
    }
    while (head!=head_keeper);

    printf("\n");
}

void ll_insert_into_circular_singly(struct Node_Singly **head, int value, int index){
    /*
    * @brief     Inserts a node into circular array.
    */
    
    assert((*head)!=NULL && index>=0);

    struct Node_Singly *new_node = NULL, *prev = NULL, *current = *head, *head_keeper= NULL;
    new_node=(struct Node_Singly *)malloc(sizeof(struct Node_Singly));
    new_node->data = value;

    head_keeper = current;

    if (index == 0){
        new_node->next = *head;
        *head = new_node;   
        
        while (current->next!=head_keeper){
            current = current->next;
        }
        current->next = *head;
        return;
    }

    int i = 0;
    do{
        prev = current;         
        current = current->next;
        i++;
    }
    while (current!=head_keeper && i<index);
    
    if (i==index){
            new_node->next = current;  
            prev->next = new_node;      
    }
    else {
        printf(FORERED);
        printf("[ERROR] Index out of bounds, could not inserted.\n");
        printf(RESETTEXT);
        free(new_node);  // Free the allocated memory for the new node
    }
}

void ll_delete_from_circular_singly(struct Node_Singly **head, int index){
    /*
    * @brief     Removes the node on the given index.
    */
    assert(index>=0);

    struct Node_Singly *prev = NULL, *current = *head;


    if (index == 0){
        while(current->next != *head){
            current = current->next;
        }
        *head = (*head)->next;
        current->next = *head;
        return;
    }

    int i = 0;
    do{
        prev = current;           
        current = current->next;
        i++;
    }
    while (current!=(*head) && i<index);
    
    if (i==index){
            prev->next = current->next;
            free(current);    
    }
    else {
        printf(FORERED);
        printf("[ERROR] Index out of bounds.\n");
        printf(RESETTEXT);
    }
}


// DOUBLY

struct Node_Doubly *ll_create_double_from_arr_doubly(int arr[], int n){
    /*
    * @brief     Creates an doubly linked list from an array.
    */
    struct Node_Doubly *head, *node, *last;
    head=(struct Node_Doubly *)malloc(sizeof(struct Node_Doubly));
    head->data = arr[0];
    head->next = NULL;
    head->prev = NULL;
    last = head;
    for (int i = 1; i < n; i++){
        node = (struct Node_Doubly *)malloc(sizeof(struct Node_Doubly));
        node->data = arr[i];
        node->next = NULL;
        node->prev = last;
        last->next = node;
        last = node;
    }
    return head;
}

void ll_display_doubly_forward(struct Node_Doubly *head){
    /*
    * @brief     Prints whole single linked list to forward direction.
    */
    printf("Nodes : ");
    while (head!=NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void ll_display_doubly_backward(struct Node_Doubly *head){
    /*
    * @brief     Prints whole single linked list to forward direction.
    */

    while(head->next != NULL){
        head = head->next;
    }
    printf("Nodes : ");
    while (head!=NULL)
    {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

void ll_insert_into_doubly(struct Node_Doubly **head, int value, int index){
    /*
    * @brief     Inserts a node to index given.
    */
    assert(index>=0);

    struct Node_Doubly *new_node = NULL, *prev, *current = *head;
    new_node=(struct Node_Doubly *)malloc(sizeof(struct Node_Doubly));
    new_node->data = value;

    if (index == 0){
        (*head)->prev = new_node;
        new_node->next = *head;
        *head = new_node; 
        return;
    }

    int i = 0;
    while (current->next!=NULL && i<index){   
        current = current->next;
        i++;
    }

    if (current->next == NULL && index - i == 1){
        current->next = new_node;
        new_node->prev = current;
    }
    else if (i==index){
        new_node->next = current;  
        new_node->prev = current->prev;
        current->prev->next = new_node;
        current->prev = new_node;
    }
    else {
        printf(FORERED);
        printf("[ERROR] Index out of bounds, could not inserted.\n");
        printf(RESETTEXT);
        free(new_node);  // Free the allocated memory for the new node
    }
}

void ll_delete_doubly(struct Node_Doubly **head, int index){
    /*
    * @brief     Removes the node on the given index.
    */
    assert(index>=0);

    struct Node_Doubly *prev = NULL, *current = *head;

    if (index == 0){
        *head = (*head)->next;
        (*head)->prev = NULL;
        return;
    }

    int i = 0;
    while (current->next!=NULL && i<index){
        current = current->next;
        i++;
    }

    if (current->next == NULL && i==index){
        prev = current->prev;
        free(current);
        prev->next = NULL;
    }
    else if (i==index){
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);    
    }
    else {
        printf(FORERED);
        printf("[ERROR] Index out of bounds.\n");
        printf(RESETTEXT);
    }
}

void ll_reverse_doubly(struct Node_Doubly **head){
    /*
    * @brief     Reverses the whole linked list. 
    */
    struct Node_Doubly *prev = NULL, *next = NULL, *current = *head;

    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        current->prev = next;
        prev = current;       
        current = next;  
    }
    *head = prev;
}

