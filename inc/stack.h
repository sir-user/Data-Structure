#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "colors.h"

typedef struct
{
    int size;
    int top;
    int *Stack_Element;
}Stack;

void s_arr_create(Stack *st, int size);

void s_arr_resize(Stack *st, int size);

void s_arr_display(Stack st);

void s_arr_push(Stack *st, int x);

void s_arr_pop(Stack *st);

int s_arr_peek(Stack st, int index);

bool s_arr_is_it_empty(Stack st);

bool s_arr_is_it_full(Stack st);

int s_arr_take_top(Stack st);

#endif