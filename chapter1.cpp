#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define MaxSize 100
#define ElemType int

typedef struct {
    ElemType *data;
    int length,MaxLength;
} SqList;

bool ListInsert(SqList &L, int i, ElemType e){
    if (i<1||i>L.length+1)
    {
        return false;
    }
    if(L.length>=MaxSize){
        return false;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, ElemType &e){
    if (i<1||i>L.length)
    {
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; i < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

int LocateElem(SqList L, ElemType e){
    int i;
    for (i = 0; i < L.length;i++){
        if(L.data[i]==e){
            return i + 1;
        }
    }
    return 0;
}

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

LinkList List_HeadInsert(LinkList &L){
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x!=-1)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

LinkList List_TailInsert(LinkList &L){
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x!=-1)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
}

LNode *GetElem(LinkList L, int i){
    int j = 1;
    LNode *p = L->next;
    if (i == 0)
    {
        return L;
    }
    if (i < 0)
    {
        return NULL;
    }
    while (p&&j<i)
    {
        p = p->next;
        j++;
    }
    return p;
}

LNode *LocalteElem(LinkList L, ElemType e){
    LNode *p = L->next;
    while (p!=NULL && p->data !=e)
    {
        p = p->next;
    }
    return p;
}

typedef struct DNode{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;
