#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "colors.h"

/*
* Queue_Arr is not exactly circular queue.
* You cant overwrite on a value, you just use the empty spaces from front. 
* Rear cannot overtake Front from behind to prevent ambiguity between full and empty states.
*/
typedef struct
{
    int size;           // dynamic array size
    int front;          // head of queue
    int rear;           // tail/end of queue
    int *Queue_Element; // data array
}Queue_Arr;             

// it is just a singly linked list
typedef struct Queue_Node_S
{
    int data;
    struct Queue_Node_S *next;
}Queue_Node_Singly;

typedef struct{
    Queue_Node_Singly* front; // Points to the front node of the queue
    Queue_Node_Singly* rear;  // Points to the rear node of the queue
} Queue_ll;


// ARRAYS 

void q_arr_create(Queue_Arr *que, int size);

void q_arr_resize(Queue_Arr *que, int new_size);

void q_arr_enqueue(Queue_Arr *que, int data);

void q_arr_dequeue(Queue_Arr *que);

void q_arr_display_array(Queue_Arr que);

void q_arr_display_queue(Queue_Arr que);

bool q_arr_is_empty(Queue_Arr que);

bool q_arr_is_full(Queue_Arr que);


// LINKED LISTS

Queue_Node_Singly* q_ll_create_node(int data);

Queue_ll* q_ll_create_queue();

void q_ll_enqueue(Queue_ll *que, int data);

void q_ll_dequeue(Queue_ll *que);

void q_ll_display(Queue_ll *queue);

#endif

