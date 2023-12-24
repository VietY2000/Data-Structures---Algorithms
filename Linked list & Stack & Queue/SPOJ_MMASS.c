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


int function(char str[]){
    int l1 = strlen(str);
    STACK *stack = creat_stack(l1);

    for(int p = 0; p < l1; ++p){
        if(str[p] >= 50 && str[p] <=57){
            int x = str[p] - 48;
            int nt = pop(stack);
            nt = nt*x;
            push(stack, nt);
            continue;
        }
        else if(str[p] == ')'){
            int sum = 0;
            int nt = pop(stack);
            while(nt != '('){
                sum = sum + nt;
                nt = pop(stack);
            }
            push(stack,sum);
            continue;
        }    
        int nt = str[p];
        switch (nt)
        {
        case 'O':
            push(stack,16);
            break;
        case 'H':
            push(stack,1);
            break;
        case 'C':
            push(stack,12);
            break;
        case '(':
            push(stack,'(');
            break;
        default:
            break;
        }
    }

    int result = 0;
    int nt = pop(stack);

    while(nt != -1){
        result = result + nt;
        nt = pop(stack);
    }
    return result;
}

int main(void){
    char str[106];

    scanf("%s",str);
    int result = function(str);
    printf("%d",result);
}