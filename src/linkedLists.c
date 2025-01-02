#include "linkedLists.h"

struct Node *create_from_arr(int arr[], int n){
    int i; 
    struct Node *head, *t, *last;
    head=(struct Node *)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL;
    last = head;
    for (i = 1; i < n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return head;
}

void display(struct Node *head){
    printf("Nodes : ");
    while (head!=NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int count(struct Node *head){
    int amount = 0;
    while (head!=NULL)
    {
        amount ++;
        head = head->next;
    }
    return amount;
}

int maxofll(struct Node *head){
    int max = INT_MIN;
    while (head!=NULL)
    {
        max = (max < head->data) ? head->data : max;
        head = head->next;
    }
    return max;
}

struct Node *linear_search(struct Node *head, int value){
    while (head!=NULL)
    {
        if (head->data == value)
            return head;
        head = head->next;
    }
    return NULL;
}

void move_to_head(struct Node **head, int value){

    if (*head == NULL || (*head)->data == value) {
        return;
    }
    struct Node *prev = NULL, *current = *head;
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

void insert(struct Node **head, int value, int index){
    assert(index>=0);

    struct Node *new_node = NULL, *prev = NULL, *current = *head;
    new_node=(struct Node *)malloc(sizeof(struct Node));
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
        printf("[ERROR] Index out of bounds.\n");
        printf(RESETTEXT);
        free(new_node);  // Free the allocated memory for the new node
    }

}   

void delete(struct Node **head, int index){
    assert(index>=0);

    struct Node *prev = NULL, *current = *head;

    if (index == 0){
        *head = (*head)->next;
        return;
    }

    int i = 0;
    while (*head!=NULL && i<index){        
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

void reverse(struct Node **head){
    struct Node *prev = NULL, *next = NULL, *current = *head;

    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;  
    }
    *head = prev;
}

void merge(struct Node **first, struct Node **second){
    struct Node *current = *first;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (*second);
}

void sort_ll(struct Node **head){
    /*if ((*head) == NULL || (*head)->next == NULL) {
        return ; 
    }*/

    struct Node *current = NULL, *next = NULL;

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

bool is_it_sorted(struct Node *head){
    if (head == NULL || head->next == NULL) {
        return false; 
    }

    struct Node *prev = NULL, *current = head;

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

void merge_sorted(struct Node **merged, struct Node *first, struct Node *second){
    /*
    * brief:    Merges already sorted 2 linked lists into first paramater(merged). 
    */

    //assert(first == NULL || second == NULL);

    if (first->data < second->data){
        (*merged) = first;
        first = first->next;
    }
    else if (first->data >= second->data){
        (*merged) = second;
        second = second->next;
    }
    
    struct Node *head_merged = *merged;

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