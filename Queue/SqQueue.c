#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ElemType int

#define MaxSize 50

typedef struct{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

int main(){
    return 0;
}

SqQueue InitQueue(){
    SqQueue queue;
    queue.front = queue.rear = 0;
    return queue;
}

bool isEmpty(SqQueue q){
    if(q.front == q.rear){
        return true;
    }
    return false;
}

bool EnQueue(SqQueue q, ElemType data){
    if((q.rear + 1) % MaxSize == q.front)
        return false;
    q.data[q.rear] = data;
    q.rear = (q.rear + 1) % MaxSize;
    return true;
}

ElemType DeQueue(SqQueue q){
    if(q.front == q.rear){
        return -1;
    }
    ElemType data = q.data[q.front];
    q.front = (q.front + 1) % MaxSize;
    return data;
}
