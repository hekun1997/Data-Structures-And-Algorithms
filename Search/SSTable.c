#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ElemType int

typedef struct{
    ElemType *data;
    int length;
} SSTable;

int Search_Seq(SSTable t, ElemType key){
    t.data[0] = key;
    int i;
    for (i = t.length; t.data[i] != key; --i);
    return i;
}