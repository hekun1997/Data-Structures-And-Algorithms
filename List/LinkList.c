#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//链表

#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList List_HeadInsert(){
    LNode *s;
    int x;
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    
    while(scanf("%d", &x) && x!=999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
    }

    return L;
}

LinkList List_TailInsert(LinkList L){
    int x;
    L = (LinkList)malloc(sizeof(LNode));

    LNode *s, *r = L;
    while(scanf("%d", &x) && x != 999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
    }
    return L;
}

LNode *GetElem(LinkList L, int i){
    int j = 1;
    LNode *p = L->next;
    if(i == 0){
        return L;
    }
    if(i < 0){
        return NULL;
    }
    while(p && j < i){
        p = p->next;
        j++;
    }
    return p;
}

LNode *LocateElem(LinkList L, ElemType e){
    LNode *p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
}

void Del_Node(LinkList L, ElemType e){
    if(L == NULL){
        return;
    }
    LNode *p = L;
    while(p){
        if(p->data == e){
            LNode *q = p->next;
            p->next = p->next->next;
            free(q);
        }
        p = p->next;
    }
}

//具有头节点,只计算了除头节点之外的节点
int ListLen(LinkList L){
    int length = 0;
    LNode *p = L->next;
    while(p){
        length++;
        p = p->next;
    }
    return length;
}

int main(){
    LinkList L = List_HeadInsert();
    while(L){
        printf("%d\n", L->data);
        L = L->next;
    }

    return 0;
}