#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
} node;

node *creatNode(int x){
    node *temp = (node*) malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

node *intial_list(){
    int n;
    scanf("%d",&n);
    int value;
    scanf("%d",&value);
    node *head = creatNode(value);
    node *headNode = head;
    for(int p = 1; p < n; ++p){
        int value;
        scanf("%d",&value);
        node* Node = creatNode(value);
        head->next = Node;
        head = head->next;
    }
    return headNode;
}

node *reversed_list(node *Node){
    node *re_node = (node*) malloc(sizeof(node));
    re_node->data = Node->data;
    re_node->next = NULL;
    node *result = re_node;
    Node = Node->next;
    re_node = NULL;
    while (Node != NULL){
        re_node = (node*) malloc(sizeof(node));
        re_node->data = Node->data;
        re_node->next = result;
        result = re_node;
        Node = Node->next;
        re_node = NULL;
    }
    return result;
}
void printNode(node *node){
    
    while (node != NULL){
        printf("%d ",node->data);
        node = node->next;
    }

}

int main(void){
    int tc;
    scanf("%d",&tc);
    while (tc--){
        node *Node = intial_list();
        node *result = reversed_list(Node);
        printNode(result);
    }
    return 0;
}