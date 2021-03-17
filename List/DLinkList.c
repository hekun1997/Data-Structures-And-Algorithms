#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ElemType int

//双链表
typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

DLinkList createList(){
    DLinkList L = (DLinkList)malloc(sizeof(DNode));
    DNode *p = L;
    int x;
    while(scanf("%d", &x) && x != 999){
        DNode *q = (DNode *)malloc(sizeof(DNode));
        q->data = x;
        p->next = q;
        q->prior = p;
        p = q;
    }
    return L;
}

int main(){
    DLinkList L = createList();

    while (L)
    {
        printf("%d\n", L->data);
        L = L->next;
    }
    

    return 0;
}