#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 50

#define ElemType int

typedef struct{
    ElemType data;
    int next;
} SLinkList[MaxSize];