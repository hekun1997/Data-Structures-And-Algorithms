#include <stdio.h>
#define MaxSize 50
#define ElemType int

#define InitSize 100
typedef struct {
    ElemType *data;
    int maxSize, length;
} SeqList;

//how init this list?
//L.data = (ElemType *)malloc(sizeof(ElemType));

