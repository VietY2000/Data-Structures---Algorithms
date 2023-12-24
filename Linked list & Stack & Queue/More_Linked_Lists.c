#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int value;
    struct Node *next;
} node;
node *creatNode(int x){
    node *temp = (node*) malloc(sizeof(node));
    temp->value = x;
    temp->next = NULL;
    return temp;
}
node *function(){
    int n;
    scanf("%d",&n);
    
    int value;
    scanf("%d",&value);
    node *Node = creatNode(value);
    node *head = Node;
    for(int p = 1; p < n; ++p){
        scanf("%d",&value);
        if(value == Node->value){
            continue;
        }
        else{
            node *new_node = creatNode(value);
            Node->next = new_node;
            Node = Node->next;
        }
    }
    return head;
}
void print_list(node *temp){
    while (temp != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
}
int main(void){
    node *result = function();
    print_list(result);
}