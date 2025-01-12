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
    
    for(int i = que.front; i <= que.rear + que.size; i++)
        printf("%d ",que.Queue_Element[i%que.size]);

    printf("] - que front: %d   - que rear: %d\n", que.front, que.rear);
}
