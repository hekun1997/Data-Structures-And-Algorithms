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
    LNode *p = GetElem(l, i - 2);
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = x;

    s->next = p->next;
    p->next = s;
    return l;
}