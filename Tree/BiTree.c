#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ElemType int
#define KeyType int

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lChild, *rChild;
} BiTNode, BSTNode, *BiTree;

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

BSTNode *BST_Search(BiTree T, ElemType key){
    while (T != NULL && key != T->data)
    {
        if(key < T->data)
            T = T->lChild;
        else
            T = T->rChild;
    }
    return T;
}

bool BST_Insert(BiTree T, KeyType k){
    if(T == NULL){
        T = (BiTree)malloc(sizeof(BSTNode));
        T->data = k;
        T->lChild = T->rChild = NULL;
        return true;
    }else if(T->data == k){
        return false;
    }else if(k < T->data){
        return BST_Insert(T->lChild, k);
    }else{
        return BST_Insert(T->rChild, k);
    }
}

BiTree createBiTree(KeyType k[], int n){
    BiTree T = NULL;
    int i = 0;
    while(i < n){
        BST_Insert(T, k[i]);
        i++;
    }
    return T;
}