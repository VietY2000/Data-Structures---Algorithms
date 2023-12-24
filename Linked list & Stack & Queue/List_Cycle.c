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

Node *creat_list(){
    int value;
    scanf("%d",&value);
    Node *temp = creatNode(value);
    Node *head = temp;
    while (scanf("%d", &value) && value != 0){
        Node *node = creatNode(value);
        temp->next = node;
        temp = temp->next;
    }
    return head;
}

Node *creat_list_cycle(){
    int value;
    scanf("%d",&value);
    Node *temp = creatNode(value);
    Node *head = temp;
    while (scanf("%d", &value) && value != 0){
        Node *node = creatNode(value);
        temp->next = node;
        temp = temp->next;
    }
    temp->next = head;
    return head;
}
Node *detect_cycle(Node* temp){
    if(temp == NULL || temp->next == NULL){
        return NULL;
    }
    Node *slow = temp;
    Node *fast = temp->next->next;

    while (fast != NULL && fast->next != NULL){
        if(fast == slow){
            return slow;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return NULL;
}

int main(void){
    Node *temp1 = creat_list_cycle();
    Node *temp2 = creat_list();
    temp1 = detect_cycle(temp1);
    temp2 = detect_cycle(temp2);
    printf("%d %d", temp1, temp2);
}