#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "colors.h"

/*it is not exactly circular queue. 
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

void q_arr_create(Queue_Arr *que, int size);

void q_arr_resize(Queue_Arr *que, int new_size);

void q_arr_enqueue(Queue_Arr *que, int data);

void q_arr_dequeue(Queue_Arr *que);

void q_arr_display_array(Queue_Arr que);

void q_arr_display_queue(Queue_Arr que);

#endif
