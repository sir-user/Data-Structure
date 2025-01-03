#ifndef LIB1_H
#define LIB1_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <stdbool.h>

#include "colors.h"


struct Node
{
    int data;
    struct Node *next;
};

struct Node *create_from_arr(int arr[], int n);

void display(struct Node *p);

int count(struct Node *p);

int maxofll(struct Node *p);

struct Node *linear_search(struct Node *head, int value);

void move_to_head(struct Node **head, int value);

void insert(struct Node **head, int value, int index);

void delete(struct Node **head, int index);

void reverse(struct Node **head);

void merge(struct Node **first, struct Node **second);

void merge_sorted(struct Node **merged, struct Node *first, struct Node *second);

bool is_it_sorted(struct Node *head);

void sort_ll(struct Node **head);
#endif