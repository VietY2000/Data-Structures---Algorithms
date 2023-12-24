#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue{

    unsigned time;
    char name[11];
} queue;

int main(){
    queue *process = (queue*) malloc(sizeof(queue)*100000);

    queue *result = (queue*) malloc(sizeof(queue)*100000);
    int n, q;
    scanf("%d %d", &n, &q);
    // nhap cac phan tu vao process
    for(int p = 0; p < n; ++p){
        scanf("%s %d", process[p].name, &process[p].time);
    }
    int front = 0;
    int rear = n-1;

    int position = -1;
    while(front != rear){

        if(process[front].time <= q){
            position++;
            if(front == 0){
                process[front].time = process[99999].time + process[front].time;                
            }
            else{
                process[front].time = process[front-1].time + process[front].time;
            }
            strcpy(result[position].name, process[front].name);
            result[position].time = process[front].time;
            front = (front + 1)%100000;            
        }
        else{
            rear = (rear + 1)%100000;
            process[rear].time = process[front].time - q;
            strcpy(process[rear].name, process[front].name);
            if(front == 0){
                process[front].time = process[99999].time + q;
            }
            else{
                process[front].time = process[front-1].time + q;
            }
            front = (front + 1)%100000;  
        }

    }
    position++;
    strcpy(result[position].name, process[front].name);

    result[position].time = result[position - 1].time + process[front].time;

    for(int p = 0; p < n; ++p){
        printf("%s %d\n",result[p].name, result[p].time);
    }
    return 0;
}