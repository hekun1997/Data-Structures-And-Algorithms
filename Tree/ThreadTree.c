#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ElemType int

typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadThree;

//中序遍历建立线索二叉树

void createThread(ThreadThree T){
    ThreadThree pre = NULL;
    if(T != NULL){
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

void InThread(ThreadThree p, ThreadThree pre){
    if(p != NULL){
        InThread(p->lchild, pre);
        if(p->lchild == NULL){
            p->lchild = pre;
            p->ltag = 1;
        }
        if(pre != NULL && pre->rchild == NULL){
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

ThreadNode *FristNode(ThreadNode *p){
    while (p->ltag == 0)
    {
        p = p->lchild;
    }
    return p;
}

ThreadNode *NextNode(ThreadNode *p){
    if(p->rtag == 0){
        return FristNode(p->rchild);
    }else{
        return p->rchild;
    }
}

void InOrder(ThreadNode *T){
    for (ThreadNode *p = FristNode(T); p != NULL; p = NextNode(p))
    {
        printf("%d ", p->data);
    }
    
}