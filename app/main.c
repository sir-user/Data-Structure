#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main(){
    printf("***************************\n***************************\n");

    Queue_Arr que;

    q_arr_create(&que, 5);

    q_arr_enqueue(&que,10);
    q_arr_enqueue(&que,20);
    q_arr_enqueue(&que,30);

    q_arr_display_array(que);

    q_arr_enqueue(&que,40);
    q_arr_enqueue(&que,50);

    q_arr_display_array(que);

    q_arr_enqueue(&que,60);
    q_arr_enqueue(&que,70);

    q_arr_dequeue(&que);
    q_arr_dequeue(&que);
    q_arr_dequeue(&que);

    q_arr_display_array(que);

    q_arr_enqueue(&que,60);
    q_arr_enqueue(&que,70);

    q_arr_display_array(que);
    q_arr_display_queue(que);

    

    return 0;
}


