#include <stdio.h>
#include <stdlib.h>
#include "linkedLists.h"
#include "stack.h"


int main(){
    printf("***************************\n***************************\n");
    
    Stack_Node *st = NULL;

    s_ll_push(&st, 10);
    s_ll_push(&st, 20);
    s_ll_push(&st, 30);
    s_ll_push(&st, 40);
    s_ll_push(&st, 50);

    s_ll_display(st);
    
    s_ll_pop(&st);

    s_ll_display(st);

    s_ll_peek(st, 0);
    s_ll_peek(st, 1);
    s_ll_peek(st, 2);


    return 0;
}


