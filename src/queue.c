#include "queue.h"

void q_arr_create(Queue_Arr *que, int size){
    que->size = size;
    que->front = que->rear = -1;
    que->Queue_Element = (int *)malloc(que->size * sizeof(int));
}

void q_arr_resize(Queue_Arr *que, int new_size){
    if(new_size <= 0){                          // that means destroy the array
        free(que->Queue_Element);               // to avoid memory leaks
        que->Queue_Element = NULL;              // to avoid dangling pointers
    }
    else{
        que->size = new_size;
        que->Queue_Element = (int *)realloc(que->Queue_Element, que->size * sizeof(int));
    }
}

void q_arr_enqueue(Queue_Arr *que, int data){
    if (que->rear == que->front - 1 || (que->rear == que->size - 1 && que->front == 0)){
        printf(FORERED);
        printf("[ERROR] Queue overflow, could not enqueued!\n");
        printf(RESETTEXT);
    }
    else{
        if(que->rear < que->size - 1){
            que->rear++;
        }
        else if (que->rear == que->size - 1){
            que->rear = 0;
        }
        if (que->front == que->rear){
            que->front++;
        }
        if(que->front == -1)
            que->front++;
        que->Queue_Element[que->rear] = data;
    }
}

void q_arr_dequeue(Queue_Arr *que){
    if(que->front == que->rear){
        printf(FORERED);
        printf("[ERROR] Queue is empty, could not dequeued!\n");
        printf(RESETTEXT);
    }
    else{
        que->Queue_Element[que->front] = NULL;
        que->front++;
    }
}

void q_arr_display_array(Queue_Arr que){
    printf("Queue: [ ");
    for(int i = 0; i < que.size; i++)
        printf("%d ",que.Queue_Element[i]);
    printf("] - que front: %d   - que rear: %d\n", que.front, que.rear);
}

void q_arr_display_queue(Queue_Arr que){
    printf("Queue: [ ");
    
    for(int i = que.front; i <= que.rear + que.size; i++){
        printf("%d ",que.Queue_Element[i]);
        if (i>=que.size-1) break;
    }
    printf("] - que front: %d   - que rear: %d\n", que.front, que.rear);
}

bool q_arr_is_empty(Queue_Arr que){
    return que.front == que.rear;
}

bool q_arr_is_full(Queue_Arr que){
    return ((que.rear - que.front == -1) || (que.rear - que.front == (que.size - 1)));
}

void q_arr_destroy(Queue_Arr *que){
    if (que->Queue_Element != NULL) {
        free(que->Queue_Element);
        que->Queue_Element = NULL;
    }
    que->size = 0;
    que->front = -1;
    que->rear = -1;
}

Queue_Node_Singly* q_ll_create_node(void *data){
    Queue_Node_Singly* newNode = (Queue_Node_Singly*)malloc(sizeof(Queue_Node_Singly));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue_ll* q_ll_create_queue(){
    Queue_ll* queue = (Queue_ll*)malloc(sizeof(Queue_ll));
    if (!queue) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

void q_ll_enqueue(Queue_ll *que, void *data){
    Queue_Node_Singly* newNode = q_ll_create_node(data);

    if (que->rear == NULL) {  // If the queue is empty, both front and rear point to the new node
        que->front = que->rear = newNode;
    }
    else{                       // Add the new node
        que->rear->next = newNode;
        que->rear = newNode;
    }
}

void *q_ll_dequeue(Queue_ll *que){
    if (que->front == NULL) {
        printf(FORERED);
        printf("[ERROR] Queue is empty, could not dequeued!\n");
        printf(RESETTEXT);
    }
    else{
        // Store the front node and move the front pointer to the next node
        Queue_Node_Singly *temp = que->front;
        void *data = temp->data;
        que->front = que->front->next;

        // If the front becomes NULL, set the rear to NULL as well
        if (que->front == NULL) {
            que->rear = NULL;
        }

        // Free the dequeued node
        free(temp);
        return data;
    }
}

void q_ll_display(Queue_ll *que, void (print_func)(void *)){
    if (que->front == NULL) {
        printf(FORERED);
        printf("[ERROR] Queue is empty, could not displayed!\n");
        printf(RESETTEXT);
    }
    else{
        Queue_Node_Singly *temp = que->front;
        printf("Queue: ");
        while (temp) {
            //printf("%d ", temp->data);
            print_func(temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void print_int(void *data){
    printf("%d ", *(int*)data);
}

int q_ll_count(Queue_ll *que){
    if (que->front == NULL) {
        printf(FORERED);
        printf("[ERROR] Queue is empty, could not counted!\n");
        printf(RESETTEXT);
        return 0;
    }
    else{
        int counter = 0;
        Queue_Node_Singly *temp = que->front;
        while (temp) {
            temp = temp->next;
            counter++;
        }
        return counter;
    }
}

int q_ll_is_empty(Queue_ll *que){
    return que->front == NULL;
}

void q_ll_destroy(Queue_ll *que){
    Queue_Node_Singly *current = que->front;
    Queue_Node_Singly *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    que->front = NULL;
    que->rear = NULL;
    free(que); // Kuyruğun kendisini de serbest bırakıyoruz.
}
