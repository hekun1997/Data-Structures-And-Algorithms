#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <queue>

#define Elemtype int

typedef struct BiTNode{
    Elemtype data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//访问根节点
void visit(BiTree T){

}

//先序遍历
void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//中序遍历
void InOrder(BiTree T){
    if (T!=NULL)
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}
//后序遍历
void PostOrder(BiTree T){
    if (T!=NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}
//上述遍历时间复杂度都为O（n

//层次遍历
void LevelOrder(BiTree T){
    InitQueue(Q);
    BiTree p;
    EnQueue(Q, T);
    while(!IsEmpty(Q)){
        DeQueue(Q);
        visit(p);
        if(p->lchild != NULL){
            EnQueue(Q, p->lchild);
        }
        if(p->rchild != NULL)
            EnQueue(Q, p->rchild);
    }
}

typedef struct ThreadNode
{
    Elemtype data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
}ThreadNode, *ThreadTree;

void InThread(ThreadTree &p, ThreadTree &pre){
    if(p!=NULL){
        InThread(p->lchild, pre);
        if (p->lchild==NULL)
        {
            p->rchild = pre;
            p->ltag = 1;
        }
        if (pre!=NULL && pre->rchild==NULL)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

void CreateInThread(ThreadTree T){
    ThreadTree pre = NULL;
    if(T != NULL){
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

#define MAX_TREE__SIZE 100
typedef struct{
    Elemtype data;
    int parent;
} PTNode;
//二叉树的查找
BiTNode *BST_Search(BiTree T, Elemtype key){
    while (T!=NULL &&key != T->data)
    {
        if (key > T->data)
        {
            T = T->rchild;
        }
        if (key<T->data)
        {
            T = T->lchild;
        }
    }
    return T;
}
//二叉树的插入
int BST_Insert(BiTree T, Elemtype data){
    if (T ==NULL)
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = data;
        T->lchild = T->rchild = NULL;
        return 1;
    }
    if (T->data == data)
    {
        return 0;
    }
    if (data > T->data)
    {
        return BST_Insert(T->rchild, data);
    }
    if (data < T->data)
    {
        return BST_Insert(T->lchild, data);
    }
}
//二叉树的构造
BiTree Create_BST(BiTree &T,Elemtype data[], int n){
    BiTree T = NULL;
    int i = 0;
    while (i < n)
    {
        BST_Insert(T, data[i]);
        i++;
    }
    return T;
}
//左单旋转，B, A . B是A的左子树，B的左子树插入导致不平衡，B成为根节点，A成为右孩子，B的右子树成为A的左孩子，其余不变
//右单旋转则相反。
//LR旋转， 插入A B C ，B是A的左子树， C是B的右子树，插入C导致ABC不平衡，C成为根节点，A成为C的右子树，B成为C的左子树，C的左子树成为B的左子树，C的右子树成为B的右子树。
//RL旋转则相反。

