#include "stack.h"


void s_arr_create(Stack_Arr *st, int size){
    /*
    * @brief Creates an dynamic array based on the stack logic.
    * 
    */

    assert(size > 0);

    st->top = -1;
    st->size = size;
    st->Stack_Element = (int *)malloc(st->size * sizeof(int));
}

void s_arr_resize(Stack_Arr *st, int size){
    /*
    * @brief Resize the dynamic array
    * 
    */
    
    assert(size > 0);

    st->size = size;
    st->Stack_Element = realloc(st->Stack_Element, size*sizeof(int));
}

void s_arr_display(Stack_Arr st){
    /*
    * @brief Prints the whole elements of stack from the last to first.
    * 
    */
    printf("Stack Elements: ");
    for(int i = st.top; i >= 0 ; i--){
        printf("%d ", st.Stack_Element[i]);
    }
    printf("\n");
}

void s_arr_push(Stack_Arr *st, int x){
    /*
    * @brief Pushes a new element to top. 
    * 
    */
    if(st->top == st->size - 1 ){
        printf(FORERED);
        printf("[ERROR] Stack overflow, could not pushed!\n");
        printf(RESETTEXT);
    }else{
        st->top++; 
        st->Stack_Element[st->top] = x;
    }
}

void s_arr_pop(Stack_Arr *st){
    /*
    * @brief Takes out the last element of stack.
    * 
    */
    if (st->top == -1){
        printf(FORERED);
        printf("[ERROR] Stack underflow, could not popped!\n");
        printf(RESETTEXT);
    }else{
        st->Stack_Element[st->top--];
        // st->Stack_Element[st->top + 1] = NULL ; // Clears the element, to NULL, no need to use. 
    }
}

int s_arr_peek(Stack_Arr st, int index){
    /*
    * @brief : Shows data on the index given.
    * 
    * @param index : it is index of stack. not element of stack.
    *  
    * @return : Returns data from given index. 
    */
    int x = -1 ;
    if(index >= 0 && st.top >= index){
        x = st.Stack_Element[index];
    }else{
        printf(FORERED);
        printf("[ERROR] Invalid index, could not peeked!\n");
        printf(RESETTEXT);
    }
    return x;
}

bool s_arr_is_it_empty(Stack_Arr st){
    /*
    * @brief Returns if stack is stack is empty. 
    * 
    * @return empty = 1 | not empty = 0
    */
    return st.top == -1;
}

bool s_arr_is_it_full(Stack_Arr st){
    /*
    * @brief Returns if stack is stack is full. 
    * 
    * @return full = 1 | not full = 0
    */
    return st.top == st.size - 1;
}

int s_arr_take_top(Stack_Arr st){
    /*
    * @brief Returns top element of stack
    */
    return st.top != -1 ? st.Stack_Element[st.top]: -1;
}


void s_ll_push(Stack_Node **st, int value){
    Stack_Node *new_node;
    new_node=(Stack_Node*)malloc(sizeof(Stack_Node));

    new_node->data = value;
    new_node->next = (*st);
    *st = new_node;
}

void s_ll_display(Stack_Node *st){
    printf("Stack Nodes: ");
    while(st!=NULL){
        printf("%d ",st->data);
        st = st->next;
    }
    printf("\n");
}

void s_ll_pop(Stack_Node **st){
    Stack_Node *temp = NULL;

    temp = (*st);
    *st = (*st)->next;
    free(temp);
}

int s_ll_count(Stack_Node *st){
    int counter = 0;

    while(st != NULL){
        st = st->next;
        counter++;
    }
    return counter;
}

void s_ll_peek(Stack_Node *st, int index){

    assert(index >= 0);
    
    index = s_ll_count(st) - index -1; // how many steps we should move ? 

    while(st!=NULL && index!= 0){
        st = st->next;
        index--;
    }
    printf("Data from given index : %d\n", st->data);
}