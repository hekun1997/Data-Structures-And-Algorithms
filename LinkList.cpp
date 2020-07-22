#include <stdio.h>
#include <malloc.h>
#include <iostream>

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList List_HeadInsert(LinkList &l){
    LNode *s;
    int x;
    l = (LinkList) malloc(sizeof(LNode));
    l -> next = NULL;
    scanf("%d", &x);

    s = (LinkList)malloc(sizeof(LNode));
    s->data = x;
    s->next = l->next;
    l->next = s;
    return l;
}