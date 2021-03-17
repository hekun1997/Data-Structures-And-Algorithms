#include <stdio.h>
#define MaxSize 50
#define ElemType int

typedef enum{
    false = 0,
    true = 1
} bool;

typedef struct{
    ElemType data[MaxSize];
    int length;
} SqList;

SqList MakeEmptyList(){
    SqList L;
    L.length = 0;
    return L;
}

bool ListInsert(SqList L, int i, ElemType e){
    if(i < 1 || i > L.length + 1){
        return false;
    }
    if(L.length >= MaxSize){
        return false;
    }
    int j;
    for (j = L.length; j >= i; j--){
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    printf("%d\n", L.data[i - 1]);
    L.length++;
    return true;
}

bool ListDelete(SqList L, int i, ElemType e){
    if(i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length;j++){
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

int LocateElem(SqList L, ElemType e){
    int i;
    for (i = 0; i < L.length; i++){
        if(L.data[i] == e)
            return i;
    }
    return -1;
}

int main(){
    SqList L;
    L = MakeEmptyList();
    ListInsert(L, 1, 99);
    printf("List --> %d", L.data[0]);
    return 0;
}