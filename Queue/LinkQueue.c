#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ElemType int

typedef struct
{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct
{
    LinkNode *front, *rear;
}LinkQueue;

LinkQueue InitQueue(){
    LinkQueue Q;
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
    return Q;
}

bool isEmpty(LinkQueue Q){
    if(Q.front = Q.rear)
        return true;
    return false;
}

void EnQueue(LinkQueue Q, ElemType data){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = data;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = Q.rear->next;
}

ElemType DeQueue(LinkQueue Q){
    if(Q.front == Q.rear)
        return -1;
    ElemType data;
    LinkNode *s = Q.front->next;
    data = s->data;

    Q.front->next = s->next;
    if(Q.rear == s){
        Q.rear = Q.front;
    }
    free(s);
    return data;
}

