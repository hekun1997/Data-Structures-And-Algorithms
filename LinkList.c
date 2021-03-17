#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int main(){
    LinkList L = List_HeadInsert();
    while(L){
        printf("%d\n", L->data);
        L = L->next;
    }

    return 0;
}