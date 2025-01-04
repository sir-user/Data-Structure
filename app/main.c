#include <stdio.h>
#include <stdlib.h>
#include "linkedLists.h"
#include "stack.h"


int main(){
    printf("***************************\n***************************\n");
    
    Stack st;
    s_arr_create(&st, 5);

    s_arr_push(&st,10);
    s_arr_push(&st,20);
    s_arr_push(&st,30);
    s_arr_push(&st,40);
    s_arr_push(&st,50);

    s_arr_push(&st,60);
    s_arr_resize(&st, 7);
    s_arr_push(&st,60);
    s_arr_display(st);
    s_arr_push(&st,70);

    s_arr_display(st);
    s_arr_push(&st,80);

    printf("%d \n", s_arr_peek(st,2));
    
    printf("top element : %d \n", s_arr_take_top(st));
    printf("is it empty : %d \n", s_arr_is_it_empty(st));
    printf("is it full  : %d \n", s_arr_is_it_full(st));
    
    
    return 0;
}


