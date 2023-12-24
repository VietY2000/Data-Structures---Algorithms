#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue{
    int front, rear, volume;
    unsigned capacity;
    unsigned *arr;
} Queue;

Queue *creat_queue(unsigned capacity){
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = queue->capacity - 1;
    queue->volume = 0;
    queue->arr = (unsigned*) malloc(sizeof(unsigned)*queue->capacity);
    return queue;
}

bool Empty(Queue *queue){
    return queue->volume == 0;
}

bool Full(Queue *queue){
    return queue->volume == queue->capacity;
}

void enqueue(Queue *queue, unsigned value){
    if(Full(queue)){
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = value;
    queue->volume++;
}

void dequeue(Queue *queue){
    if(Empty(queue)){
        return;
    }
    int value = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->volume--;
}
unsigned Peek(Queue *queue){
    if(Empty(queue)){ 
        return -1;

    }
    return queue->arr[queue->front];
}

int main(void){
    int n;
    scanf("%d", &n);
    Queue *queue = creat_queue(100000);
    unsigned value;
    while(n--){
        int p;
        scanf("%d",&p);
        switch (p)
        {
        case 1:
            scanf("%d",&value);
            enqueue(queue,value);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            printf("%d\n", Peek(queue));
            break;
        default:
            break;
        }
    }
    return 0;
}
    