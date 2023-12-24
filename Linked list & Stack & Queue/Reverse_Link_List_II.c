#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node *creatNode(int value){
    Node *temp = (Node*) malloc(sizeof(temp));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

Node *creat_list(){
    int value;
    scanf("%d",&value);
    Node *temp = creatNode(value);
    Node *head = temp;
    while(scanf("%d", &value) && value >= 0){
        Node *node = creatNode(value);
        temp->next = node;
        temp = node;
    }
    return head;
}

Node *rebetw(Node* temp, int b, int c){
    Node *head = temp;
    for(int p = 1; p < b - 1; ++p){
        temp = temp->next;
    }
    Node *b_temp;
    if( b == 1){
        b_temp = temp;
    }
    else{
        b_temp = temp->next;
    }
    
    Node *re_temp = (Node*) malloc(sizeof(Node));
    re_temp->data = b_temp->data;
    re_temp->next = NULL;
    b_temp = b_temp->next;
    for(int p = b; p < c; ++p){
        Node *node = (Node*) malloc(sizeof(Node));
        node->data = b_temp->data;
        node->next = re_temp;
        re_temp = node;
        b_temp = b_temp->next;
        node = NULL;
    }
    

    if(b == 1){
        head = re_temp;
        temp = re_temp;
    }
    else{
        temp->next = re_temp;
    }  
    while (1){
        if(temp->next == NULL){
            temp->next = b_temp;
            break;
        }
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

int main(void){
    Node *temp = creat_list();
    int b, c;
    scanf("%d %d", &b, &c);
    temp = rebetw(temp,b,c);
    print_list(temp);
}