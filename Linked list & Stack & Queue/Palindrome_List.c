#include <stdio.h>
#include <stdlib.h>


typedef struct Node_np{
    int data;
    struct Node_np *next;
    struct Node_np *pre;
} Node_np;

Node_np *creatNode(int value){
    Node_np *temp = (Node_np*) malloc(sizeof(Node_np));
    temp->data = value;
    temp->next = NULL;
    temp->pre = NULL;
    return temp;
}

int main(void){
    int value;
    scanf("%d", &value);
    Node_np *temp = creatNode(value);
    Node_np *head = temp;
    int n = 1;
    while(scanf("%d",&value) && value < 10){
        Node_np *node = creatNode(value);
        temp->next = node;
        node->pre = temp;
        temp = temp->next;
        n++;
    }
    for(int p = 1; p <= n/2; ++p){
        if(head->data == temp->data){
            if(p == n/2){
                printf("1");
            }
            head = head->next;
            temp = temp->pre;
        }
        else{
            printf("0");
            break;
        }
    }
    return 0;
}