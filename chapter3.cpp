#include <stdio.h>
#include <malloc.h>
#include <iostream>

#define MaxSize 50
#define ElemType int
typedef struct
{
    ElemType data[MaxSize];
    int top;
}SeqStack;

//init
void InitStack(SeqStack &s){
    s.top = -1;
}

//isEmpty
bool StackEmpty(SeqStack &S){
    if(S.top == -1){
        return true;
    }
    return false;
}

bool Push(SeqStack &S, ElemType x){
    if (S.top = MaxSize -1)
    {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

bool Pop(SeqStack &S, ElemType &x){
    if (S.top == -1)
    {
        return false;
    }
    x = S.data[S.top --];
    return true;
}
 
bool GetTop(SeqStack &S, ElemType &x){
    if (S.top == -1)
    {
        return false;
    }
    x = S.data[S.top];
    return true;
}

typedef struct Linklone
{
    ElemType data;
    struct Linknode *next;
}*LiStack;
//C C B C A B B C D A C D D D B C D D C C 21C  B A B B C A 3 (能， 不能，DB相邻了) （A C D 进栈+1，出栈-1，为负数报错）
//若元素的进栈序列为A, B, C,D,E,运用栈操作,能否得到出栈序列B, C, A, E, D和D, B,"A,C, E? 为什么?

typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
}SqQueue;
//队空条件 Q.front = Q.rear = 0;（初始时）
//循环队列 初始时：Q.front = Q.rear = 0;
//队空条件 Qfront = Q.rear
//队列长度 (Q.rear + MaxSize - Q.rear)
void initQueue(SqQueue &Q){
    Q.rear = Q.front = 0;
}

//队空
bool isEmpty(SqQueue Q){
    if (Q.rear == Q.front)
        return true;
    return false;
}

//入队
bool EnQueue(SqQueue Q, ElemType x){
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}
//出队
bool DeQueue(SqQueue &Q, ElemType &x){
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}
typedef struct{
    ElemType data;
    struct LinkNode *next;
} LinkNode;
typedef struct{
    LinkNode *front, *rear;
}LinkQueue;

//队列为空时 Q.front = Q.rear = NULL
void initQueue(LinkQueue Q){
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}
bool isEmpty(LinkQueue Q){
    if (Q.front == Q.rear)
    {
        return true;
    }
    return false;
}
void EnQueue(LinkQueue &Q, ElemType x){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}