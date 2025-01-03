#include <stdio.h>
#include <stdlib.h>
#include "linkedLists.h"

struct Node_Doubly *first = NULL;

struct Node_Doubly *second = NULL;

struct Node_Singly *merged = NULL;

int main(){
    printf("***************************\n***************************\n");

    int arr[5] = {46, 57, 123, 97, 6};
    int arr2[7] = {22, 44, 33, 66, 55, 77, 11};
    
    first = create_double_from_arr_doubly(arr, 5);
    second = create_double_from_arr_doubly(arr2, 7);


    display_doubly_forward(second);
    display_doubly_backward(second);

    reverse_doubly(&second);

    display_doubly_forward(second);
    display_doubly_backward(second);

    return 0;
}


