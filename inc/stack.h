#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "colors.h"

typedef struct
{
    int size;           // dynamic array size
    int top;            // index of top element's
    int *Stack_Element; // data
}Stack_Arr;

typedef struct Stack_N
{   
    // first node is top, last is bottom.

    int data;             // data
    struct Stack_N *next; // next node
}Stack_Node;


// ARRAYS 

void s_arr_create(Stack_Arr *st, int size);

void s_arr_resize(Stack_Arr *st, int size);

void s_arr_display(Stack_Arr st);

void s_arr_push(Stack_Arr *st, int x);

void s_arr_pop(Stack_Arr *st);

int s_arr_peek(Stack_Arr st, int index);

bool s_arr_is_it_empty(Stack_Arr st);

bool s_arr_is_it_full(Stack_Arr st);

int s_arr_take_top(Stack_Arr st);



// LINKED LISTS

void s_ll_push(Stack_Node **st, int value);

void s_ll_display(Stack_Node *st);

void s_ll_pop(Stack_Node **st);

int s_ll_count(Stack_Node *st);

void s_ll_peek(Stack_Node *st, int index);

#endif