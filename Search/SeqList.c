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

int Binary_Search(SeqList L, ElemType key){
    int low = 0, high = L.length - 1, mid = (low + high)/2;
    while(low < high && L.data[mid] != key){
        mid = (low + high) / 2;
        if(L.data[mid] == key){
            return mid;
        }else if(L.data[mid] < key){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;
} 

