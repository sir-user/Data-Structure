#include "stack.h"

size_t custom_strlen(const char *str);             // to not include string.h library


int main(){
    printf("***************************\n***************************\nIN STACK EXAMPLE\n");
    
    Stack_Node *st = NULL;

    char *exp="))((a+b)*(c-d)))((";                          

    size_t length_exp = custom_strlen(exp);

    
    for(int i = 0; i < length_exp; i++){  
        if(exp[i] == ')' || exp[i] == '('){
            if(st!=NULL){
                if(st->data == '(' && exp[i] == ')'){         // only accepted match is for '(' and ')'
                    s_ll_pop(&st);
                }
                else{
                    s_ll_push(&st, exp[i]);
                }
            }
            else{
                s_ll_push(&st, exp[i]);
            }
        }

    }
    printf("Paranthesis' matching status is %d\n", st==NULL ? 1:0);
    s_ll_display(st);          // returns integer values of characters

    return 0;
}

size_t custom_strlen(const char *str){
    const char *s = str;
    while (*s) {
        s++;
    }
    return s - str;
}