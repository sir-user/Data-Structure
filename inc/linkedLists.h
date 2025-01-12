#ifndef LIB1_H
#define LIB1_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <stdbool.h>

#include "colors.h"


struct Node_Singly
{
    int data;
    struct Node_Singly *next;
};

struct Node_Doubly
{
    int data;
    struct Node_Doubly *prev;
    struct Node_Doubly *next;
};

struct Node_Singly *ll_create_single_from_arr(int arr[], int n);

void ll_display_single(struct Node_Singly *p);

int ll_count_singly(struct Node_Singly *p);

int ll_maxofll_singly(struct Node_Singly *p);

struct Node_Singly *ll_linear_search_singly(struct Node_Singly *head, int value);

void ll_move_to_head_singly(struct Node_Singly **head, int value);

void ll_insert_singly(struct Node_Singly **head, int value, int index);

void ll_delete_singly(struct Node_Singly **head, int index);

void ll_reverse_singly(struct Node_Singly **head);

void ll_merge_singly(struct Node_Singly **first, struct Node_Singly **second);

void ll_merge_sorted_singly(struct Node_Singly **merged, struct Node_Singly *first, struct Node_Singly *second);

bool ll_is_it_sorted_singly(struct Node_Singly *head);

bool ll_is_it_circular_singly(struct Node_Singly *head);

void ll_sort_ll_singly(struct Node_Singly **head);

void ll_display_circular_singly(struct Node_Singly *head);

void ll_insert_into_circular_singly(struct Node_Singly **head, int value, int index);

void ll_delete_from_circular_singly(struct Node_Singly **head, int index);


struct Node_Doubly *ll_create_double_from_arr_doubly(int arr[], int n);

void ll_display_doubly_forward(struct Node_Doubly *head);

void ll_display_doubly_backward(struct Node_Doubly *head);

void ll_insert_into_doubly(struct Node_Doubly **head, int value, int index);

void ll_delete_doubly(struct Node_Doubly **head, int index);

void ll_reverse_doubly(struct Node_Doubly **head);


#endif