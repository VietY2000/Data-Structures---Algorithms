#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *pre;
} Node;

// tao node 
Node *creat_node(int data){
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    temp->pre = NULL;
    return temp;
}

// chen data vao dau list
Node *insert(int data, Node *head){
    Node *temp = creat_node(data);

    temp->next = head;
    head->pre = temp;   
    return temp;
}


// function xoa phan tu x
Node *del_x(Node *head, int data){
    Node *current = head;
    if(head->data == data){
        current = head->next;
        current->pre = NULL;
        return current;
    }
    else{
        while(head->next != NULL && head->next->data != data){
            head = head->next;
        }
        if(head->next == NULL){
            return current;
        } 
        head->next = head->next->next;
        head->next->pre = head;
        return current;
    }    

}

// function xoa phan tu dau

Node *del_first(Node *head){
    head = head->next;
    head->pre = NULL;
    return head;
}

// function xoa phan tu cuoi
Node *del_last(Node *head, Node *tail){
    if(tail->pre->pre == NULL){
        tail->pre = NULL;
        return tail;
    }
    else{
        Node *current = tail->pre->pre;
        tail->pre = current;
        current->next = tail;
        return head;
    }    
}

int main(){
    int n;
    scanf("%d", &n); // nhap so lenh
    Node *head = (Node*) malloc(sizeof(Node));
    Node *tail = head;
    tail->next = NULL;
    while(n--){
        char str[100];
        scanf("%s", str); // nhap chuoi
        if(strcmp(str,"insert") == 0){
            int data;
            scanf("%d", &data);
            head = insert(data,head);
        }
        else if(strcmp(str,"delete") == 0){
            int data;
            scanf("%d", &data);
            head = del_x(head,data);
        }
        else if(strcmp(str,"deleteFirst") == 0){
            head = del_first(head);
        }
        else {
            head = del_last(head,tail);
        }
    }
    while(head != tail){
        printf("%d ", head->data);
        head = head->next;
    }
    return 0;
}