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

struct Node_Singly *create_single_from_arr(int arr[], int n);

void display_single(struct Node_Singly *p);

int count_singly(struct Node_Singly *p);

int maxofll_singly(struct Node_Singly *p);

struct Node_Singly *linear_search_singly(struct Node_Singly *head, int value);

void move_to_head_singly(struct Node_Singly **head, int value);

void insert_singly(struct Node_Singly **head, int value, int index);

void delete_singly(struct Node_Singly **head, int index);

void reverse_singly(struct Node_Singly **head);

void merge_singly(struct Node_Singly **first, struct Node_Singly **second);

void merge_sorted_singly(struct Node_Singly **merged, struct Node_Singly *first, struct Node_Singly *second);

bool is_it_sorted_singly(struct Node_Singly *head);

bool is_it_circular_singly(struct Node_Singly *head);

void sort_ll_singly(struct Node_Singly **head);

void display_circular_singly(struct Node_Singly *head);

void insert_into_circular_singly(struct Node_Singly **head, int value, int index);

void delete_from_circular_singly(struct Node_Singly **head, int index);

struct Node_Doubly *create_double_from_arr_doubly(int arr[], int n);

void display_doubly_forward(struct Node_Doubly *head);

void display_doubly_backward(struct Node_Doubly *head);

void insert_into_doubly(struct Node_Doubly **head, int value, int index);

void delete_doubly(struct Node_Doubly **head, int index);

void reverse_doubly(struct Node_Doubly **head);


#endif