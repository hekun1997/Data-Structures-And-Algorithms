#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ElemType int

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lChild, *rChild;
} BiTNode, *BiTree;

void PreOrder(BiTree T){
    if(T){
        printf("%d", T->data);
        PreOrder(T->lChild);
        PreOrder(T->rChild);
    }
}

void InOrder(BiTree T){
    if(T){
        InOrder(T->lChild);
        printf("%d", T->data);
        InOrder(T->rChild);
    }
}

void PostOrder(BiTree T){
    if(T){
        PostOrder(T->lChild);
        PostOrder(T->rChild);
        printf("%d", T->data);
    }
}

void LevelOrder(BiTree T){
    //InitQueue(Q);
    // BiTree p;
    // EnQueue(Q, T);
    // while(!isEmpty(Q)){
    //     DeQueue(Q, p);
    //     visit(p);
    //     if(p->lChild != NULL)
    //         EnQueue(Q, p->lChild);
    //     if(p->rChild != NULL)
    //         EnQueue(Q, p->rChild);
    // }
}