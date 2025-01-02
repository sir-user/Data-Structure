#include <stdio.h>
#include <stdlib.h>
#include "linkedLists.h"

struct Node *first = NULL;

struct Node *second = NULL;

struct Node *merged = NULL;

int main(){
    printf("***************************\n***************************\n");

    int arr[5] = {46, 57, 123, 97, 6};
    int arr2[7] = {22, 44, 33, 66, 55, 77, 11};
    
    first = create_from_arr(arr, 5);
    second = create_from_arr(arr2, 7);

    display(first);
    display(second);

    sort_ll(&first);
    sort_ll(&second);

    display(first);
    display(second);
    
    merge_sorted(&merged, first, second);
    
    display(merged);
    return 0;
}


