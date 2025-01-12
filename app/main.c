#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main(){
    printf("***************************\n***************************\n");

    Queue_ll *que = q_ll_create_queue();

    q_ll_enqueue(que, 10);
    q_ll_enqueue(que, 20);
    q_ll_enqueue(que, 30);

    q_ll_display(que);
    printf("count is : %d\n", q_ll_count(que));
    
    q_ll_dequeue(que);

    q_ll_enqueue(que, 40);
    q_ll_enqueue(que, 50);

    q_ll_display(que);
    printf("count is : %d\n", q_ll_count(que));

    q_ll_dequeue(que);

    q_ll_display(que);
    printf("count is : %d\n", q_ll_count(que));


    return 0;
}


