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
    for(int p = 0; p < n - 1; ++p){
        scanf("%d", &value);
        Node *node = creatNode(value);
        temp->next = node;
        temp = temp->next;
    }
    return head;
}

Node *merge_list(Node *node1, Node *node2){

    Node *head;
    if(node1->data < node2->data){
        head = node1;
        while(node1 != NULL & node2 != NULL){
            if(node1->next != NULL && node1->next->data < node2->data ){
                node1 = node1->next;
            }
            else{
                if(node1->next == NULL){
                    break;
                }
                Node *node = node1->next;
                node1->next = node2;
                node2 = node2->next;
                node1->next->next = node;
                node1 = node1->next;               
            }
        }
        if(node2 != NULL){
            node1->next = node2;
        }
    }
    else{
        head = node2;
        while(node2 != NULL & node1 != NULL){
            if(node2->next != NULL && node2->next->data < node1->data ){
                node2 = node2->next;
            }
            else{
                if(node2->next == NULL){
                    break;
                }
                Node *node = node2->next;
                node2->next = node1;
                node1 = node1->next;
                node2->next->next = node;
                node2 = node2->next;               
            }
        }
        if(node1 != NULL){
            node2->next = node1;
        }
    }
    return head;
}
void print_list(Node *temp){
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(void){
    int number1, number2;
    scanf("%d %d", &number1, &number2);
    Node *node1 = creat_list(number1);
    Node *node2 = creat_list(number2);

    Node *result = merge_list(node1,node2);
    print_list(result);
}