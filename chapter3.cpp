#include <stdio.h>
#include <malloc.h>
#include <iostream>

#define MaxSize 50
#define ElemType int

typedef struct{
    ElemType data[MaxSize];
    int top;
} SqStack;

void InitSqStack(SqStack &S){
    S.top = -1;
}

bool StackElpty(SqStack S){
    if(S.top == -1){
        return true;
    }
    return false;
}

bool Push(SqStack &S, ElemType x){
    if(S.top == MaxSize-1){
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack S, ElemType e){
    if(S.top == -1)
        return false;
    e = S.data[S.top--];
    return true;
}

typedef struct Linknode
{
    ElemType data;
    struct Linknode *next;
} *LiStack;

typedef struct{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

typedef struct{
    ElemType data;
    struct LinkNode *next;
} *LinkNode;
typedef struct{
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    LinkNode *front = Q.front;
    front.next = NULL;
}

bool IsEmpty(LinkQueue Q){
    if (Q.front == Q.rear)
        return true;
    return false;
}

void EnQueue(LinkQueue &Q, ElemType e){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s.data = e;
    Q.rear->next = s;
    s.next = NULL;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, ElemType &x){
    if (Q.front == Q.rear)
        return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return true;
}

 