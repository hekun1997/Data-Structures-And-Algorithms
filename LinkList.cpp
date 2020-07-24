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

//1 设计一个递归算法,删除不带头结点的单链表L中所有值为x的结点
void DeleteXWithOutHead(LinkList &l, ElemType x){
    LNode *p;
    
    if (l == NULL)
    {
        return;
    }
    if (l->data == x)
    {
        p = l;
        l = l->next;
        free(p);
    }
    DeleteXWithOutHead(l, x);
    
}

//2 在带头结点的单链表L中,删除所有值为x的结点,并释放其空间,假设值为x的结点.唯一,试编写算法以实现上述
void DeleteXWithHead(LinkList &L, ElemType x){
    LNode *pre = L, *p = L->next, *q;
    while (p!=NULL)
    {
        if (p->data == x)
        {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        }
        else
        {
            pre = pre->next;
            p = p->next;
        }
    }
    
}
//3 设L是带头结点的单链表，设置从尾到头反向输出每个结点的值。
//递归
void print(LinkList &l){
    if (l != NULL)
    {
        if (l->next!=NULL)
        {
            print(l->next);
        }
        if (l!=NULL)
        {
            printf(" "+l->data);
        }
    }
}
//4 删除带头结点的单链表的最小值，要求高效。
void deleteMinElem(LinkList &l){
    LNode *p = l->next, *pre = l;
    LNode *pMin = p, *preMin = pre;
    while (p != NULL)
    {
        if (p->data < pMin->data)
        {
            pMin = p;
            preMin = pre;
        }
        pre = pre->next;
        p = p->next;
    }
    preMin = pMin->next;
    free(pMin);
}
//5 试编写算法将带头结点的单链表就地逆值，所谓“就地”是指辅助空间复杂度为 0(1 ）。
//头插法
void Reverse_head1(LinkList &l){
    LNode *p = l->next, *r;
    l->next = NULL;
    while (p!=NULL)
    {
        r = p->next;
        p->next = l->next;//理解不了
        l->next = p;
        p = r;
    }
    return l;
}

void Reverse_head2(LinkList &l){
    LNode *pre, *p = l->next, *r = p->next;
    p->next = NULL;
    while (r!=NULL)
    {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    l->next = p;
    return l;
}
//6 带头结点的单链表，设计一个算法使其元素递增有序。
LinkList sort(LinkList &L){
    LNode *p = L->next, *pre;
    LNode *r = p->next;
    p->next = NULL;
    p = r;
    while (p!=NULL)
    {
        r = p->next;
        pre = L;
        while (pre->next!=NULL && pre->next->data < p->data)
        {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}
//7 设在一个带表头结点的单链表中所有元素结点的数据值无序，试编写函数，删除表中所有介于给定的两个值（作为函数参数给出）之间的元素的元素（若存在）
LinkList deleteBewteenAAndB(LinkList &l, ElemType A, ElemType B){
    LNode *p = l;
    while (p!=NULL)
    {
        if (p->next->data > A || p->next->data < B)
        {
            LNode *temp = p->next;
            p->next = temp->next;
            free(temp);
            continue;
        }
        p = p->next;
    }
    return l;
}
//8 给定两个单链表，编写算法找出两个链表的公共结点。

//9 给定两个单链表，编写算法找出两个链表的公共结点。

//10 将一个带头结点的单链表A分解为两个带头结点的单链表A和B,使得A表中含有原表中序号为奇数的元素,而B表中含有原表中序号为偶数的元素,且保持其相对顺序不变。
void split(LinkList &l, LinkList &A, LinkList &B){
    int count = 1;
    LNode *p = l->next;

    A = (LinkList)malloc(sizeof(LNode));
    LNode *a = A;

    B = (LinkList)malloc(sizeof(LNode));
    LNode *b = B;


    while (p !=NULL)
    {
        if (count % 2 != 0)
        {
            a->next = p;
        }else
        {
            b->next = p;
        }
        p = p->next;
        count++;
    }
}

//11 设C = {a1,b1, a2,b2,..an,bn}线性链表,采用带头结点的单链表存放,设计一个就地算法,将其拆分为两个线性表,使得A={a1, a2, ., an}, B={bn,..., b2, b1).
void split(LinkList &l){
    LNode *p = l->next;
    LinkList &A = (LinkList)malloc(sizeof(LNode));
    LinkList &B = (LinkList)malloc(sizeof(LNode));
    int count = 1;
    while (p!=NULL)
    {
        if (count % 2 != 0)
        {
            A->next = p;
        }else
        {
            B->next = p;
        }
        p = p->next;
        }
}

//12 在一个递增有序的线性表中,有数值相同的元素存在。若存储方式为单链表,设计算法去掉数值相同的元素,使表中不再有重复的元素,例如(7, 10, 10, 21, 30, 42, 42, 42, 51,70)将变为(7, 10, 21,30, 42, 51,70),

//13 假设有两个按元素值递增次序排列的线性表,均以单链表形式存储。请编写算法将这两·个单链表归并为一个按元素值递减次序排列的单链表,并要求利用原来两个单链表的结点存放归并后的单链表。

//14 设A和B是两个单链表(带头结点),其中元素递增有序。设计一个算法从A和B中的"公共元素产生单链表C,要求不破坏A,B的结点。

//15 已知两个链表A和B分别表示两个集合,其元素递增排列。编制函数,求A与B的交集，并存放到A链表。

//16 两个整数序列A=a1, a2, a3,... , am和B=b1, b2, ,.,bn已经存入两个单链表中,设计一算法，判断序列B是否是序A的子序列

//17 设计一个算法用于判断带头结点的循环双链表是否对称。

//18 有两个循环单链表,链表头指针分别为h1和h2,编写一个函数将链表h2链接到链表h1之后，要求链接后的链表仍然是循环链表的形式。

//19 设有一个带头结点的循环单链表,其结点值均为正整数。设计一个算法,反复找出单链表中结点值最小的结点并输出,然后将该结点从中删除,直到单链表空为止,再删除表头结点。


//20 设头指针为L的带有表头结点的非循环双向链表,其每个结点中除有pred (前驱指针)、data (数据)和next (后继指针)域外,还有一个访问频度域freq.在链表被启用前,其值均初始化为零。每当在链表中进行一次Locate (I, x)运算时,今元素值为x的结点中freq域的值增1,并使此链表中结点保持按访问频度非增(递减)的顺序排列,同时最近访问的结点排在频度相同的结点前面,以便使频繁访问的结点总是靠近表头。试编写符合上述要求的Locate (L, x)运算的算法,该运算为函数过程,返回找到结点的地址,类型为指针型。

//21

//22

//23

//24

//25