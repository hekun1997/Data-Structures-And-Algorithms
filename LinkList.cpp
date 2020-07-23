#include <stdio.h>
#include <malloc.h>
#include <iostream>

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

//头插法
LinkList List_HeadInsert(LinkList &l){
    LNode *s;
    int x;
    l = (LinkList) malloc(sizeof(LNode));
    l -> next = NULL;

    s = (LNode*)malloc(sizeof(LNode));
    s->data = x;
    s->next = l->next;
    l->next = s;
    return l;
}

//尾插法
LinkList List_TailInsert(LinkList &l){
    LNode *s, *r;//r为表尾指针
    int x;
    l = (LinkList)malloc(sizeof(LNode));

    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    r->next = s;
    s->next = NULL;
    r = s;

    return l;
}
//找到指定位置的节点
LNode *GetElem(LinkList &l, int i){
    int j = 1;
    LNode *p = l->next;
    if(i<0){
        return NULL;
    }
    while (p&&j <= i)
    {
        p = p->next;
        j++;
    }
    return p;
}
//找到指定元素的位置
LNode  *LocateElem(LinkList l, ElemType e){
    LNode *p = l->next;
    while (p != NULL && p -> data != e)
    {
        p = p->next;
    }
    return p;
}
//将值为x的元素插入到第i个位置
LinkList insertXToI(LinkList &l, ElemType x, int i){
    LNode *p = GetElem(l, i - 1);
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = x;

    s->next = p->next;
    p->next = s;
    return l;
}
//将值为x的元素插入到第i个位置的前一个位置
LinkList insertXToIBefore(LinkList &l, ElemType x, int i){
    LNode *p = GetElem(l, i - 1);
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = x;

    s->next = p->next;
    p->next = s;

    ElemType temp = s->data;
    s->data = p->data;
    p->data = temp;
    return l;
}
//删除第i个节点
LinkList deleteI(LinkList &l, int i){
    LNode *p = GetElem(l, i - 1);
    LNode *q = p->next;
    p->next = q->next;
    free(q);
    return l;
}
//求表长操作,不带头结点
int GetLinkListLength(LinkList &l){
    int count = 0;
    LNode *p = l->next;
    while (p!=NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}
//求表长操作，带头结点
int GetLinkListLengthWithOutHead(LinkList &l){
    int count = 1;
    LNode *p = l->next;
    while (p!=NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}

//双链表
typedef struct DNode{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;
//获取第i个节点
DNode *GetElem(DLinkList &l, int i){
    int count = 0;
    DNode *p = l->next;
    while (count < i)
    {
        p = p->next;
        count++;
    }
    return p;
}

DLinkList DLinkList_insert(DLinkList &l, int x){
    int i = 1;
    DNode *p = GetElem(l, i);
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;  

    s->data = x;
    return l;
}
//删除p的后继节点q；
DLinkList DLinkList_delete(DLinkList &l,int i){
    DNode *p = GetElem(l, i);
    DNode *q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(p);
}

#define MaxSize 50

typedef struct{
    ElemType data;
    int idnex;
} SLinkList[MaxSize];
//以next=-1作为结束的标志

//设计一个递归算法,删除不带头结点的单链表L中所有值为x的结点
LinkList DeleteX(){
    
}
