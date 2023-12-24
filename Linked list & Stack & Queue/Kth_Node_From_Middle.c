#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node *creatNode(int value){
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

Node *creat_list(int n){
    int value;
    scanf("%d",&value);
    Node *temp = creatNode(value);
    Node *head = temp;
    n--;
    while (n--){
        scanf("%d",&value);
        Node *node = creatNode(value);
        temp->next = node;
        temp = temp->next;       
    }
    return head;
}

void print_list(Node *temp){
    while (temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void function(Node *temp, int n, int b){
    int p = n/2 - b;
    if(p < 0){
        printf("-1");
    }
    else{
        for(int e = 0; e <= p; ++e){
            if(e == p){
                printf("\n%d",temp->data);
            }
            else{
                temp = temp->next;
            }
        }
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    Node *temp = creat_list(n);
    int b; 
    scanf("%d",&b);
    print_list(temp);
    function(temp,n,b);
}