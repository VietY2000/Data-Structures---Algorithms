#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STACK{
    int top;
    unsigned capacity;
    int *arr;
} STACK;

STACK *creat_stack(unsigned capacity){
    STACK *stack = (STACK*) malloc(sizeof(STACK));
    stack->top = -1;
    stack->capacity = capacity;
    stack->arr = (int*) malloc(sizeof(int)*capacity);
    return stack;
}

int Full(STACK *stack){
    return stack->top == stack->capacity - 1;
}

int Empty(STACK *stack){
    return stack->top == -1;

}

void push(STACK *stack, int data){
    if(Full(stack)){
        return;
    }
    stack->arr[++stack->top] = data;
}

int pop(STACK *stack){
    if(Empty(stack)){
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(STACK *stack){
    if(Empty(stack)){
        return -1;
    }
    return stack->arr[stack->top];
}


int main(){

    STACK *stack = creat_stack(201);

    char str[1000000];
    fgets(str,sizeof(str),stdin);

    int value = 0;
    for(int p = 0; p < strlen(str) - 1; ++p){
        if(str[p] <= 57 && str[p] >= 48){
            int number = str[p] - 48;
            if(value == 0){
                value = number;
            }
            else{
                value = value*10 + number;
            }
        }
        else if(str[p] == ' '){
            if(value == 0){
                continue;
            }
            push(stack,value);
            value = 0;
        }
        else{
            int value = pop(stack);
            switch(str[p]){
                case '+':
                    value = value + pop(stack);
                    break;
                case '-':
                    value = pop(stack) - value;
                    break;
                case '*':
                    value = value*pop(stack);
                    break;
                default:
                    break; 
            }
            push(stack,value);
        }
    }
    printf("%d", peek(stack));
    
    return 0;
}